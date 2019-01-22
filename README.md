# STM32F7xx_midi
forty-seven effects midi library on STM hal, DMA.

## Status
Stable, but not healthy.

This branch configured for the STM32F446 nucleo board.
* MIDI data can be read but DMA crashes
* Buttons and LEDs enabled
* ADC configured in cubeMX but not working
* 3-digit plus time format on seven segment display

## General Commands
Use `make` to build.

Use `make info` to see the object and include lists.

To debug, run 2 cmd windows

OpenOCD:

`C:\Users\marshall>openocd -f "E:\github\STM32F7xx_midi\MidiTemplate\usbDebug.cfg" -c "init; reset halt"`

gcb (run from make directory)

`C:/STM32/gcc-arm-none-eabi/bin/arm-none-eabi-gdb -x gdbinit.txt build/output.elf`