# scot-motor

Motor Interface for the SCOT.

* 9-36V DC Input
* STM32F042K6 Microcontroller @ 48MHz
* MCP2562 CAN 2.0A/B Communication Interface
* DRV8872 3.6A PWM H-Bridge Motor Driver
* INA260 Motor Voltage & Current Supply Monitoring
* NCV8450 800mA Clutch Driver
* E-Stop, End-of-travel Limit Interlocks support
  * Hardware CMOS NAND Logic (immune to software override)
  * Opto-isolation of Switches from Logic Inputs (power supply not isolated)

[**Circuit Board Schematic**](https://github.com/philcrump/scot-motor/raw/master/scot-motor-schematic.pdf)

## PCB (CAD Render)

![PCB CAD Render](https://raw.githubusercontent.com/philcrump/scot-motor/master/scot-motor-cad.png)

### Errata - April 2020

* 0603 footprint used for C3 (4.7uF, 25V), should be 0805 - Minimal impact, 0805 still fits.