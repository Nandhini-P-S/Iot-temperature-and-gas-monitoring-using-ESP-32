# IoT-Based Temperature and Gas Monitoring System using ESP32

## Project Overview
This project monitors gas levels, temperature and humidity using ESP32 and different sensors.

## Objectives
- Monitor gas leakage levels.
- Measure temperature and humidity.
- Display sensor readings on LCD.
- Provide alerts using buzzer and LEDs.

## Hardware Components
- ESP32
- MQ-2 Gas Sensor
- MQ-5 Gas Sensor
- DHT11 Temperature Sensor
- 16x2 I2C LCD
- Buzzer
- Red LED
- Green LED

## Software Requirements
- Arduino IDE
- ESP32 Board Package
- DHT Sensor Library
- LiquidCrystal I2C Library

## Working Principle
The MQ sensors monitor gas-related readings.
The DHT11 measures temperature and humidity.
ESP32 processes the readings and activates
an alert when the configured gas threshold
is crossed.

## Repository Structure
- src/gas_temperature_monitor.ino
- README.md

## Future Enhancements
- Wi-Fi connectivity
- Live IoT dashboard
- Cloud data monitoring
- Historical data graphs

## Author
Add your name here.