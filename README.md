# ColdBuddy - a temperature/humidity monitor built on top of arduino ![Continuous Integration](https://travis-ci.org/rscarvalho/ColdBuddy.svg?branch=master)

This project is my first attempt on building stuff with microcontrollers.
It monitors temperature and humidity and displays it on a screen.

## Components

This project uses the following components:

* One [UNO r3](https://store.arduino.cc/usa/arduino-uno-rev3/) board.
* One Velleman [VMA311](https://www.vellemanusa.com/products/view/?id=528380) (DHT11) as temperature+humidity sensor.
* A Velleman [VMA437](https://www.vellemanusa.com/products/view/?id=529148) (SH1106 Driver, SPI) 1.3" OLED monochrome screen.

## Software

I'm using [PlatformIO](https://platformio.org/) for building, uploading and testing the software part of this component.
