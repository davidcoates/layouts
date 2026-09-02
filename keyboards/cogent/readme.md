# cogent

A 38-key, split, ortholinear, columnar keyboard with a dedicated palm key per
hand (its own row and column in the matrix). Hardware source lives in
`hardware/cogent` (ergogen + KiCad) in the parent repo.

Controller: Pro Micro RP2040 (nice!nano-footprint), via `ceoloide/mcu_nice_nano`
reversible footprint on a single PCB design shared by both hands (one is
populated with the MCU flipped to the opposite face to mirror the layout).

## Hardware notes

The `ceoloide/mcu_nice_nano` footprint (with `only_required_jumpers: true`)
only jumpers the 4 pin-pairs that can't be swapped in firmware (RAW/P1,
GND/P0, GND/RST, GND/VCC). The other 8 pairs are left to firmware, because
flipping the MCU to populate the opposite face (used here to get a mirrored
right hand from the same PCB) swaps which physical pin drives which net:

    P2 <-> P21   P3 <-> P20   P4 <-> P19   P5 <-> P18
    P6 <-> P15   P7 <-> P14   P8 <-> P16   P9 <-> P10

`keyboard.json` treats the un-mirrored ergogen point set as the left hand
(direct net-to-pin mapping) and the mirrored/flipped one as the right hand
(swapped per the table above) -- confirmed correct by cross-checking the
swap pairs against the board's actual pinout (e.g. left `bottom` and right
`palm` column both land on GP4, as `P4<->P19` predicts).

`diode_direction: COL2ROW` was inferred from the `ceoloide/diode_tht_sod123`
`from`/`to` pad convention (`from: colrow` = column side, `to: row_net`),
and confirmed against continuity on the actual board.

GPIO numbers were verified against the board's actual pinout (a generic
RP2040 "Pro Micro" clone whose seller states its IO is identical to the
SparkFun Pro Micro RP2040), not assumed -- the naive "sequential pin number
== same GPIO number" pattern does *not* hold past P7:

    P2  -> GP2   P3  -> GP3   P4  -> GP4
    P6  -> GP6   P7  -> GP7   P9  -> GP9   P8  -> GP8
    P10 -> GP21  P14 -> GP20  P15 -> GP22  P16 -> GP23
    P18 -> GP26  P19 -> GP27  P21 -> GP29

(P0/P1 are swapped relative to naive identity too -- P1(TX) -> GP0,
P0(RX) -> GP1 -- but neither is used as a matrix net here, only as the
pre-jumpered RAW/GND pair, so it doesn't matter for this board.)
