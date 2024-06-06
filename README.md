# ESP32 NTP Clock with OLED Display
![2669166C-4E84-47D6-9581-085282B236CB-min copy](https://github.com/sina-tahbaz/esp32_ntpClock/assets/110201165/fe79a371-ec5f-4b99-b427-ee538706e95e)

## Project Overview
This project involves creating a network-enabled clock using an ESP32 microcontroller and an OLED display. The clock displays the current time, which it fetches from an NTP (Network Time Protocol) server over the internet. This project is ideal for anyone interested in building internet-connected devices with real-time capabilities.

## Features
- **Accurate Timekeeping:** Fetches the current time from NTP servers, ensuring the clock is always accurate.
- **WiFi Connectivity:** Connects to the internet via WiFi to access time data.
- **OLED Display:** Displays time information clearly on a small OLED screen.

## Hardware Requirements
- ESP32 Development Board
- OLED Display Module (e.g., SSD1306, 128x64 pixels)

## Software Requirements
- Arduino IDE
- ESP32 Board Definitions for Arduino IDE

## Usage
Once powered, the ESP32 will connect to your WiFi network and begin fetching the current time from the configured NTP server. The time will be displayed on the OLED screen and updated periodically.

## Customization
You can customize the NTP server settings and the time update interval by modifying the respective variables in the code.

## Contributing
Contributions to this project are welcome. Please fork the repository and submit a pull request with your enhancements.

## License
This project is licensed under the MIT License - see the `LICENSE.md` file for details.
