# Smart Industrial Safety Monitoring System using LPC2129

## Overview
A real-time industrial safety monitoring system developed using the LPC2129 microcontroller. It monitors temperature, worker presence, and flame conditions and indicates the safety status through an LCD, LEDs, and UART.

## Features
- LM35 temperature monitoring
- PIR worker detection
- Flame detection
- 16x2 LCD display
- Green, Yellow and Red LED indication
- UART monitoring

## Safety Status
- **GREEN – SAFE:** Temperature below 35°C, no worker or flame detected
- **YELLOW – WARNING:** Temperature between 35°C and 40°C
- **RED – DANGER:** Worker detected, temperature above 40°C, or flame detected

## Pin Configuration

| Device | Pin |
|---|---|
| LM35 | P0.28 / AD0.1 |
| PIR | P0.30 |
| Flame Sensor | P0.5 |
| Green LED | P0.17 |
| Yellow LED | P0.18 |
| Red LED | P0.19 |

## Technologies
**Embedded C · LPC2129 · ADC · GPIO · UART · 16x2 LCD**
