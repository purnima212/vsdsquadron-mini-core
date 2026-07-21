How to build PlatformIO based project
=====================================

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/Community-PIO-CH32V/platform-ch32v/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```shell
# Change directory to example
$ cd platform-ch32v/examples/blinky-none-os

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Upload firmware for the specific environment
$ pio run -e ch32v307_evt --target upload

# Clean build files
$ pio run --target clean
```

# Task 2 – GPIO Library and UART Demonstration

## Overview

This project implements a reusable GPIO library for the VSDSquadron Mini (CH32V003) development board. The application demonstrates GPIO control by blinking the onboard LED and UART communication by printing status messages and a counter over the serial interface.

---

## Features

- GPIO initialization
- GPIO set
- GPIO clear
- GPIO toggle
- UART initialization
- Serial debug output
- Onboard LED blinking

---

## Project Structure

```
.
├── include
│   └── gpio.h
├── src
│   ├── gpio.c
│   └── main.c
├── README.md
└── evidence.md
```

---

## GPIO Library APIs

| Function | Description |
|----------|-------------|
| gpio_init() | Initializes GPIO for LED output |
| gpio_set() | Turns LED ON |
| gpio_clear() | Turns LED OFF |
| gpio_toggle() | Toggles LED state |

---

## Hardware Used

- VSDSquadron Mini Development Board
- CH32V003 Microcontroller
- Onboard LED (PD6)
- USB Type-C Cable

No external LED or resistor was required because the onboard LED was used.

---

## Software Used

- Visual Studio Code
- PlatformIO
- VSDSquadron Mini SDK
- WCH-Link Driver

---

## Working

1. Initializes system clock.
2. Initializes UART at 115200 baud.
3. Initializes GPIO using the GPIO library.
4. Toggles the onboard LED every second.
5. Prints an incrementing counter over UART every second.

---

## UART Output

```
====================================
VSDSquadron Mini
Firmware Version : 1.0
====================================

Counter : 1
Counter : 2
Counter : 3
...
```

---

## Result

The onboard LED blinks successfully while UART continuously prints the counter, demonstrating correct GPIO abstraction and serial communication.