# Smart Industrial Safety Monitoring System Using LPC2129

## Project Overview

Developed a multi-sensor industrial safety monitoring system using the LPC2129 ARM7 microcontroller to monitor environmental conditions and detect potential safety hazards.

The system integrates a temperature sensor, PIR motion sensor, and flame sensor to identify unsafe conditions. It provides real-time alerts through LEDs and an LCD display while transmitting monitoring information to a PC through UART communication.

## Hardware Components

- LPC2129 ARM7 Microcontroller
- LM35 Temperature Sensor
- PIR Motion Sensor
- Flame Sensor Module
- 16x2 LCD Display
- Green LED
- Yellow LED
- Red LED
- USB-to-UART Interface

## Pin Connections

### Sensor Connections

| Component | LPC2129 Pin |
|---|---|
| LM35 OUT | P0.28 (AD0.1) |
| PIR Sensor OUT | P0.17 |
| Flame Sensor DO | P0.18 |

### LED Connections

| LED | LPC2129 Pin |
|---|---|
| Green LED | P0.14 |
| Yellow LED | P0.15 |
| Red LED | P0.16 |

All LEDs operate in active-LOW configuration.

### LCD Connections

| LCD Pin | LPC2129 Pin |
|---|---|
| RS | P1.17 |
| RW | P1.18 |
| EN | P1.19 |
| D4 | P1.20 |
| D5 | P1.21 |
| D6 | P1.22 |
| D7 | P1.23 |

## Working Principle

1. The LM35 temperature sensor provides analog temperature readings through the ADC.
2. The PIR sensor detects human movement through a digital input.
3. The flame sensor detects fire-related conditions through its digital output.
4. The LPC2129 processes the sensor readings and determines the machine safety status.
5. The LCD displays the measured temperature and current safety condition.
6. LEDs provide visual indications of the detected condition.
7. UART communication transmits sensor readings and machine status to a PC.

## Safety Classification

| Condition | Description | LED Indication |
|---|---|---|
| SAFE | Temperature below 35°C, no motion or flame detected | Green |
| WARNING | Temperature between 35°C and 40°C only | Yellow |
| DANGER | Temperature above 40°C, motion detected, or flame detected | Red |

## Communication and Peripherals

- ADC – Temperature sensor data acquisition
- GPIO – Digital sensor interfacing and LED control
- UART – Serial communication at 9600 baud
- LCD – Real-time status visualization

## Software and Tools

- Embedded C
- Keil µVision
- LPC2129 ARM7
- ADC, GPIO, UART and LCD drivers

## Repository Structure

| File | Description |
|---|---|
| main.c | Main application and safety classification logic |
| header.h | Function declarations and definitions |
| adc_driver.c | ADC peripheral driver |
| driver.c | Peripheral driver functions |
| delay.c | Delay functions |
| lcd_4bit_driver.c | LCD interface driver |
| uart_driver.c | UART communication driver |
| Startup.s | ARM7 startup assembly |
| proj1.uvproj | Keil project configuration |
| proj1.uvopt | Keil project options |
| proj1.hex | Generated firmware HEX file |

## Author

Praveen Kannan
