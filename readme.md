# m3501_stm32f072

![m3501_stm32f072](imgur.com image replace me!)

This is a drop in replacement PCB for the Apple M3501 (Apple Extended Keyboard 2, AEK2). Utilizing a custom MCU this PCB replaces the stock PCB and provides the following benefits:
    1. Native USB support. No need for a converter.
    2. NKRO (No Key Roll Over)

This PCB maintains the following features:
    1. Locking caps lock switch support
    2. LED status indicators
    3. Left and right USB connectors (NOT to be used at the same time!)

* Keyboard Maintainer: [Tomahawk Labs](https://github.com/tomahawklabskb)
* Hardware Supported: MCU: https://github.com/nearestexit/kb_f072
* Hardware Availability: Used market

## Bootloader

Enter the bootloader: short the BOOTSEL pin to 3.3v and press the reset button mounted on the MCU, then unshort BOOTSEL. Tweezers work great for this.

Known issues: 
    1. Onboard BOOTSEL switch is not wired correctly
    2. USB Breakout has D+ and D- flipped on both sides
