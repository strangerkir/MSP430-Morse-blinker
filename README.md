# Morse Blinker for MSP430

This is a simple Morse code blinker written in C for the MSP430 microcontroller.  
It blinks a LED on `P1.0` using Timer_A, representing dots, dashes, and spaces according to Morse timing.

## Features
- Converts text in Morse Code by blinking a LED at `P1.0`.
- Uses hardware timer interrupts for accurate Morse timing.

## Limitations
- Input text is hardcoded in firmware
- No persistent storage

## Requirements

- Code Composer Studio (CCS)
- MSP430xxxx Launchpad board

## Build & Run

1. Clone this repository.
2. Import the project into your CCS.
3. Connect your LaunchPad and run **Start Debugging** to flash and run the code.
4. The LED on `P1.0` will blink Morse signals repeatedly.

## Status
This project is considered complete in its current scope.

## Notes

This is an **educational project**, created to learn and practice embedded development concepts on the MSP430 platform, including:

- Timer configuration
- GPIO control
- Interrupt handling
- Interaction with filesystem
- Basic system design

Feel free to fork or modify it as a base for your own experiments.

## License

This project includes code from Texas Instruments under their BSD license (see header comments in source files).

The rest of the project is under [MIT License](LICENSE).
