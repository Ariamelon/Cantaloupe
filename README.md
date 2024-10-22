# Cantaloupe
~60% QMK-compatible split ergonomic keyboard.

## Disclaimer
This keyboard is licensed under CERN-OHL-S-2.0. The layout is based on the [Ergodash](https://github.com/omkbd/ErgoDash) layout with the inner-most keys removed and an improved thumb cluster. The layout was only used as a reference, nothing was copied and the board is a completely new design. In addition, design cues from the [YAEMK](https://karlk90.github.io/yaemk-split-kb/) were used in this design.

## Key Features
* Ergonomic 30-key layout including pinky stagger and arrow keys.
* MX switches with kailh hot-swap sockets.
* 100% reversible design which means only a single board is needed for both sides.
* 0.96" 128x64 SSD1306 OLED support.
* Two rotary encoders supported above the thumb cluster, one on each side.
* Support for the Pimoroni trackball module is also available, replacing one rotary encoder slot.
* On-board ARM STM32F401CCU6 processor.
* USB-C input and split connect ports with full ESD protection.
* SWD breakout header for an alternate means of programming the board.

![Cantaloupe Front Render](Images/Render.png)
![Cantaloupe PCB](Images/PCB.png)
![Cantaloupe PCB Zoomed](Images/PCB_Zoom.png)
![Cantaloupe Schematic](Images/Schematic.svg)

## Changelog
* 22/10/2024: License updated to CERN-OHL-S-2.0.
* 14/5/2022: Added silkscreen jumper guides. Connected indicator LED to spare GPIO. Updated images.
* 13/5/2022: Finalized firmware. Added custom graphic to OLED display. Updated 3DP case and BOM. Removed CNC case. Fixed error with silkscreen. Added silkscreen jumper guides.
* 15/2/2022: Revised 3DP and CNC case designs.
* 13/2/2022: Added tentative designs for CNC and 3D printed cases. 
* 11/2/2022: Clean up of design. New images. Added gerbers and files for FR4 plates.
* 9/2/2022: Changed pin assignments so B2 isn't used. Added pull-up for RX pin and pull-down for B2 pin so the keyboard can properly load into the bootloader. Changed reset circuit so it actually works. Removed USB series resistors. Removed non-functional JTAG pins. Changed SRV05-04 to SRV0504. Thanks to sigprof and MasterSpoon from the QMK discord server for the help!
* 8/2/2022: Removed holes in middle of PCB. Added top and bottom plate DXF files, as well as a tentative STEP file for a CNC case. 
* 25/1/2022: Did some rerouting, increased clearances and via size.
* 21/1/2022: Changed CPU to STM32F4x1CxUx (lets me steal them from Black Pill boards). Added plate and base gerber files. Changed BOM to reflect changes.
* 20/1/2022: Cleaned up read-me. Rearranged location of mounting holes and changed size of holes. Rerouted some traces. Cleaned up silkscreen. Added DXF files for plate and base. Changed images. Added BOM.
* 19/1/2022: New V2.0 version. On-board ARM STM32F303 processor, kailh hot-swap, ESD protection, 0.96" OLED, trackball and rotary encoder. 100% reversible design which means only a single board is needed for both sides. Plenty of design cues taken from the YAEMK. Pinky stagger added.