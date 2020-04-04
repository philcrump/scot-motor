EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2000 2950 2200 1150
U 5E55A5CD
F0 "CAN Transceiver" 50
F1 "scot-can-txrx.sch" 50
F2 "CAN_L" I L 2000 3350 50 
F3 "CAN_H" I L 2000 3600 50 
F4 "CAN_MCU_RXD" I R 4200 3700 50 
F5 "CAN_MCU_TXD" I R 4200 3600 50 
F6 "3.3V_MCU" I R 4200 3050 50 
F7 "5V_CAN" I R 4200 3200 50 
F8 "LV_GND" I R 4200 3350 50 
$EndSheet
$Sheet
S 6700 2450 1200 1500
U 5E55A713
F0 "MCU" 50
F1 "scot-motor-mcu.sch" 50
F2 "MOTOR_A" I R 7900 2600 50 
F3 "MOTOR_B" I R 7900 2700 50 
F4 "LIMIT_1A" I R 7900 2850 50 
F5 "LIMIT_1B" I R 7900 2950 50 
F6 "LIMIT_2A" I R 7900 3100 50 
F7 "LIMIT_2B" I R 7900 3200 50 
F8 "ESTOP_B" I R 7900 3500 50 
F9 "ESTOP_A" I R 7900 3400 50 
F10 "VI_I2C_SCL" I L 6700 2850 50 
F11 "VI_I2C_SDA" I L 6700 2950 50 
$EndSheet
$Sheet
S 3300 850  1650 1650
U 5E55A987
F0 "Power Supplies" 50
F1 "scot-motor-power.sch" 50
F2 "POWER_28V+" I L 3300 1000 50 
F3 "POWER_28V-" I L 3300 1100 50 
F4 "3V3_MCU" I R 4950 2200 50 
F5 "5V_CAN" I R 4950 2050 50 
F6 "MOTOR_28V-" I R 4950 1100 50 
F7 "MOTOR_28V+" I R 4950 1000 50 
F8 "VI_SDA" I R 4950 1500 50 
F9 "VI_SCL" I R 4950 1600 50 
F10 "VI_ALERT" I R 4950 1700 50 
F11 "LV_GND" I R 4950 2350 50 
$EndSheet
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5E880BD6
P 2250 1100
F 0 "J?" H 2142 775 50  0000 C CNN
F 1 "Conn_01x02_Female" H 2142 866 50  0000 C CNN
F 2 "" H 2250 1100 50  0001 C CNN
F 3 "~" H 2250 1100 50  0001 C CNN
	1    2250 1100
	-1   0    0    1   
$EndComp
Text Notes 2000 1300 0    50   ~ 0
>0.1" Terminal Block
Text Notes 9000 2850 0    50   ~ 0
>0.1" Terminal Block
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5F16698D
P 9500 2700
F 0 "J?" H 9392 2375 50  0000 C CNN
F 1 "Conn_01x02_Female" H 9392 2466 50  0000 C CNN
F 2 "" H 9500 2700 50  0001 C CNN
F 3 "~" H 9500 2700 50  0001 C CNN
	1    9500 2700
	1    0    0    1   
$EndComp
Text Notes 9000 3600 0    50   ~ 0
0.1" Terminal Block
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5F169795
P 9500 3450
F 0 "J?" H 9392 3125 50  0000 C CNN
F 1 "Conn_01x02_Female" H 9392 3216 50  0000 C CNN
F 2 "" H 9500 3450 50  0001 C CNN
F 3 "~" H 9500 3450 50  0001 C CNN
	1    9500 3450
	1    0    0    1   
$EndComp
Text Notes 9000 4300 0    50   ~ 0
0.1" Terminal Block
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5F16A059
P 9500 4150
F 0 "J?" H 9392 3825 50  0000 C CNN
F 1 "Conn_01x02_Female" H 9392 3916 50  0000 C CNN
F 2 "" H 9500 4150 50  0001 C CNN
F 3 "~" H 9500 4150 50  0001 C CNN
	1    9500 4150
	1    0    0    1   
$EndComp
Text Notes 9000 5000 0    50   ~ 0
0.1" Terminal Block
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5F16B504
P 9500 4850
F 0 "J?" H 9392 4525 50  0000 C CNN
F 1 "Conn_01x02_Female" H 9392 4616 50  0000 C CNN
F 2 "" H 9500 4850 50  0001 C CNN
F 3 "~" H 9500 4850 50  0001 C CNN
	1    9500 4850
	1    0    0    1   
$EndComp
Text Notes 9950 2700 0    100  ~ 20
MOTOR
Text Notes 9950 3450 0    100  ~ 20
LIMIT_1
Text Notes 9950 4150 0    100  ~ 20
LIMIT_2
Text Notes 9950 4850 0    100  ~ 20
ESTOP
Text Notes 1300 1150 0    100  ~ 20
28V IN
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5F16DEFB
P 1250 3350
F 0 "J?" H 1142 3025 50  0000 C CNN
F 1 "Conn_01x02_Female" H 1142 3116 50  0000 C CNN
F 2 "" H 1250 3350 50  0001 C CNN
F 3 "~" H 1250 3350 50  0001 C CNN
	1    1250 3350
	-1   0    0    1   
$EndComp
Text Notes 600  3550 0    100  ~ 20
CAN
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5F16F7C8
P 1250 3750
F 0 "J?" H 1142 3425 50  0000 C CNN
F 1 "Conn_01x02_Female" H 1142 3516 50  0000 C CNN
F 2 "" H 1250 3750 50  0001 C CNN
F 3 "~" H 1250 3750 50  0001 C CNN
	1    1250 3750
	-1   0    0    1   
$EndComp
Text Notes 1000 3950 0    50   ~ 0
0.1" Terminal Block
Text Notes 4650 4650 0    50   ~ 0
TODO: Sort out global ground.
$EndSCHEMATC
