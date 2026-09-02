#!/usr/bin/env node
'use strict'

// Renders a 1:1 scale, top-down SVG of the top plate outline with keycap-sized
// rectangles in place of switch cutouts (all 1U, palm key sized/rotated
// correctly). Meant for printing at 100% ("actual size", no "fit to page")
// and cutting out as a rough physical spacing prototype.
//
// Usage: node scripts/keycap_preview.js [config.yaml] [output.svg]

const fs = require('fs')
const path = require('path')
const yaml = require('js-yaml')

const prepare = require('ergogen/src/prepare')
const units_lib = require('ergogen/src/units')
const points_lib = require('ergogen/src/points')
const outlines_lib = require('ergogen/src/outlines')
const io = require('ergogen/src/io')
const u = require('ergogen/src/utils')

const configPath = path.resolve(process.argv[2] || path.join(__dirname, '..', 'ergogen', 'config.yaml'))
const outPath = path.resolve(process.argv[3] || path.join(__dirname, '..', 'output', 'keycap_preview.svg'))

let config = yaml.load(fs.readFileSync(configPath, 'utf8'))
config = prepare.unnest(config)
config = prepare.inherit(config)
config = prepare.parameterize(config)

const units = units_lib.parse(config)
const points = points_lib.parse(config.points, units)
const outlines = outlines_lib.parse(config.outlines || {}, points, units)

if (!outlines.top_plate) {
    throw new Error('config.yaml has no "top_plate" outline to draw')
}

// Points tagged "thumb_ref" are pivots used to anchor the thumb/palm zones --
// not real keys (see the comments next to `thumb_ref` in config.yaml) -- so
// skip them to avoid drawing phantom, unrotated keycaps under the real
// (rotated) palm/thumb_outer keys. The board is split/mirrored, and
// "top_plate" only outlines one hand, so also skip the "mirror_"-prefixed
// points (the other hand) -- keeping both halves would draw keycaps for the
// right hand with no plate beneath them, roughly doubling the print width.
const keycaps = {}
for (const [name, p] of Object.entries(points)) {
    if ((p.meta.tags || []).includes('thumb_ref')) continue
    if (name.startsWith('mirror_')) continue
    const w = p.meta.width
    const h = p.meta.height
    keycaps[name] = p.position(u.rect(w, h, [-w / 2, -h / 2]))
}

const combined = {
    models: {
        plate: outlines.top_plate,
        keycaps: {models: keycaps},
    },
}

const result = io.twodee(combined, {svg: true})

// Append a 100mm scale bar below the plate, so a print can be checked for
// correct 1:1 scaling with a ruler before cutting anything out.
const match = result.svg.match(/width="([\d.]+)mm" height="([\d.]+)mm" viewBox="0 0 ([\d.]+) ([\d.]+)"/)
if (!match) {
    throw new Error('Could not parse dimensions out of generated SVG')
}
const width = parseFloat(match[1])
const height = parseFloat(match[2])
const margin = 6
const barLength = 100
const rulerY = height + margin
const newHeight = rulerY + 14

const ticks = []
for (let mm = 0; mm <= barLength; mm += 10) {
    const major = mm % 50 === 0
    const len = major ? 3 : 1.5
    ticks.push(`<line x1="${mm}" y1="${rulerY - len}" x2="${mm}" y2="${rulerY + len}" />`)
}
const labels = [0, 50, 100]
    .map(mm => `<text x="${mm}" y="${rulerY + 8}" text-anchor="middle" font-size="4" stroke="none" fill="#000">${mm}</text>`)
    .join('')

const scaleBar = `<g id="scaleBar" stroke="#000" stroke-width="0.25mm">` +
    `<line x1="0" y1="${rulerY}" x2="${barLength}" y2="${rulerY}" />` +
    ticks.join('') +
    labels +
    `<text x="0" y="${rulerY + 13}" font-size="3" stroke="none" fill="#000">Scale check: bar above must measure exactly 100mm when printed. Print at 100% / "Actual size" -- not "fit to page".</text>` +
    `</g>`

let svg = result.svg
    .replace(`height="${match[2]}mm"`, `height="${newHeight}mm"`)
    .replace(`viewBox="0 0 ${match[3]} ${match[4]}"`, `viewBox="0 0 ${width} ${newHeight}"`)
    .replace('</svg>', `${scaleBar}</svg>`)

fs.mkdirSync(path.dirname(outPath), {recursive: true})
fs.writeFileSync(outPath, svg)
console.log(`Wrote ${outPath}`)

// Printing a bare .svg file directly often ends up scaled wrong -- browsers
// don't reliably honor physical (mm) units on a standalone SVG's root
// element when paginating for print. Wrapping it in HTML and sizing it with
// CSS mm units instead is handled correctly by print engines. Print *this*
// file, not the .svg, at 100% / "Actual size".
const htmlPath = outPath.replace(/\.svg$/, '.html')
const svgFile = path.basename(outPath)
const html = `<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Keycap preview</title>
<style>
  @page { margin: 0; }
  html, body { height: 100%; margin: 0; }
  body { display: flex; align-items: center; justify-content: center; }
  img { display: block; width: ${width}mm; height: ${newHeight}mm; }
</style>
</head>
<body>
<img src="${svgFile}" alt="keycap preview">
</body>
</html>
`
fs.writeFileSync(htmlPath, html)
console.log(`Wrote ${htmlPath} -- print this (not the .svg) at 100% / "Actual size"`)
