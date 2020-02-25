EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_Motor:DRV8872DDA U?
U 1 1 5E55BFD3
P 8900 3800
F 0 "U?" H 8900 4281 50  0000 C CNN
F 1 "DRV8872DDA" H 8900 4190 50  0000 C CNN
F 2 "Package_SO:Texas_HTSOP-8-1EP_3.9x4.9mm_P1.27mm_EP2.95x4.9mm_Mask2.4x3.1mm_ThermalVias" H 9100 3700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8872.pdf" H 8650 4150 50  0001 C CNN
	1    8900 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 4000 9300 4200
Wire Wire Line
	9300 4200 8900 4200
Text Notes 9250 4400 0    50   ~ 0
Iocp = approx. 4.5A when ISEN is shorted
Text HLabel 10400 3550 2    50   Input ~ 0
MOTOR_A
Text HLabel 10400 3750 2    50   Input ~ 0
MOTOR_B
$Comp
L Device:C C?
U 1 1 5E55CE1E
P 9450 4000
F 0 "C?" H 9565 4046 50  0000 L CNN
F 1 "10u" H 9565 3955 50  0000 L CNN
F 2 "" H 9488 3850 50  0001 C CNN
F 3 "~" H 9450 4000 50  0001 C CNN
	1    9450 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5E55D664
P 9800 4000
F 0 "C?" H 9915 4046 50  0000 L CNN
F 1 "10u" H 9915 3955 50  0000 L CNN
F 2 "" H 9838 3850 50  0001 C CNN
F 3 "~" H 9800 4000 50  0001 C CNN
	1    9800 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 4150 9800 4200
Wire Wire Line
	9800 4200 9450 4200
Connection ~ 9300 4200
Wire Wire Line
	9450 4150 9450 4200
Connection ~ 9450 4200
Wire Wire Line
	9450 4200 9300 4200
Wire Wire Line
	9450 3850 9450 3500
Wire Wire Line
	9450 3500 9300 3500
Wire Wire Line
	9450 3500 9800 3500
Wire Wire Line
	9800 3500 9800 3850
Connection ~ 9450 3500
$Comp
L 74xx:74HC00 U?
U 1 1 5E55EBB1
P 7750 3400
F 0 "U?" H 7750 3725 50  0000 C CNN
F 1 "74HC00" H 7750 3634 50  0000 C CNN
F 2 "" H 7750 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7750 3400 50  0001 C CNN
	1    7750 3400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U?
U 2 1 5E560E2D
P 6600 3100
F 0 "U?" H 6600 3425 50  0000 C CNN
F 1 "74HC00" H 6600 3334 50  0000 C CNN
F 2 "" H 6600 3100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 6600 3100 50  0001 C CNN
	2    6600 3100
	-1   0    0    1   
$EndComp
$Comp
L 74xx:74HC00 U?
U 3 1 5E562588
P 7750 3950
F 0 "U?" H 7750 4275 50  0000 C CNN
F 1 "74HC00" H 7750 4184 50  0000 C CNN
F 2 "" H 7750 3950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 7750 3950 50  0001 C CNN
	3    7750 3950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U?
U 4 1 5E5645EE
P 6600 4150
F 0 "U?" H 6600 4475 50  0000 C CNN
F 1 "74HC00" H 6600 4384 50  0000 C CNN
F 2 "" H 6600 4150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 6600 4150 50  0001 C CNN
	4    6600 4150
	-1   0    0    1   
$EndComp
$Comp
L 74xx:74HC00 U?
U 5 1 5E56678C
P 8000 2050
F 0 "U?" H 8230 2096 50  0000 L CNN
F 1 "74HC00" H 8230 2005 50  0000 L CNN
F 2 "" H 8000 2050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 8000 2050 50  0001 C CNN
	5    8000 2050
	1    0    0    -1  
$EndComp
$Comp
L agg-kicad:GND #PWR?
U 1 1 5E576C4A
P 8900 4350
F 0 "#PWR?" H 8770 4390 50  0001 L CNN
F 1 "GND" H 8900 4439 50  0000 C CNN
F 2 "" H 8900 4350 50  0001 C CNN
F 3 "" H 8900 4350 50  0001 C CNN
	1    8900 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 4350 8900 4200
Connection ~ 8900 4200
Wire Wire Line
	6900 4250 6950 4250
Wire Wire Line
	6950 4250 6950 4150
Wire Wire Line
	6950 4050 6900 4050
Wire Wire Line
	6900 3200 6950 3200
Wire Wire Line
	6950 3200 6950 3100
Wire Wire Line
	6950 3000 6900 3000
Wire Wire Line
	8500 3700 8250 3700
Wire Wire Line
	8250 3700 8250 3400
Wire Wire Line
	8250 3400 8050 3400
Wire Wire Line
	8050 3950 8250 3950
Wire Wire Line
	8250 3950 8250 3800
Wire Wire Line
	8250 3800 8500 3800
$Comp
L Device:R R?
U 1 1 5E5DDCF2
P 7450 4300
F 0 "R?" H 7520 4346 50  0000 L CNN
F 1 "R" H 7520 4255 50  0000 L CNN
F 2 "" V 7380 4300 50  0001 C CNN
F 3 "~" H 7450 4300 50  0001 C CNN
	1    7450 4300
	1    0    0    -1  
$EndComp
Text HLabel 7300 4650 2    50   Input ~ 0
LIMIT_1A
Text HLabel 7300 4800 2    50   Input ~ 0
LIMIT_1B
$Comp
L agg-kicad:3v3 #PWR?
U 1 1 5E5ED166
P 7250 4650
F 0 "#PWR?" H 7250 4760 50  0001 L CNN
F 1 "3v3" H 7250 4773 50  0000 C CNN
F 2 "" H 7250 4650 50  0001 C CNN
F 3 "" H 7250 4650 50  0001 C CNN
	1    7250 4650
	1    0    0    -1  
$EndComp
$Comp
L agg-kicad:GND #PWR?
U 1 1 5E5F2C8A
P 7450 4450
F 0 "#PWR?" H 7320 4490 50  0001 L CNN
F 1 "GND" H 7450 4539 50  0000 C CNN
F 2 "" H 7450 4450 50  0001 C CNN
F 3 "" H 7450 4450 50  0001 C CNN
	1    7450 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 4650 7250 4650
Wire Wire Line
	7450 4050 7100 4050
Wire Wire Line
	7100 4050 7100 4150
Wire Wire Line
	7100 4800 7300 4800
Wire Wire Line
	7450 4150 7450 4050
Connection ~ 7450 4050
Wire Wire Line
	7100 4150 6950 4150
Connection ~ 7100 4150
Wire Wire Line
	7100 4150 7100 4800
Connection ~ 6950 4150
Wire Wire Line
	6950 4150 6950 4050
Wire Wire Line
	7450 3850 6150 3850
Wire Wire Line
	6300 4150 6150 4150
$Comp
L agg-kicad:3v3 #PWR?
U 1 1 5E61B627
P 8000 1500
F 0 "#PWR?" H 8000 1610 50  0001 L CNN
F 1 "3v3" H 8000 1623 50  0000 C CNN
F 2 "" H 8000 1500 50  0001 C CNN
F 3 "" H 8000 1500 50  0001 C CNN
	1    8000 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 1550 8000 1500
$Comp
L Device:C C?
U 1 1 5E61E517
P 8650 2000
F 0 "C?" H 8765 2046 50  0000 L CNN
F 1 "100n" H 8765 1955 50  0000 L CNN
F 2 "" H 8688 1850 50  0001 C CNN
F 3 "~" H 8650 2000 50  0001 C CNN
	1    8650 2000
	1    0    0    -1  
$EndComp
$Comp
L agg-kicad:GND #PWR?
U 1 1 5E622642
P 8000 2600
F 0 "#PWR?" H 7870 2640 50  0001 L CNN
F 1 "GND" H 8000 2689 50  0000 C CNN
F 2 "" H 8000 2600 50  0001 C CNN
F 3 "" H 8000 2600 50  0001 C CNN
	1    8000 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2600 8000 2550
Wire Wire Line
	8650 2150 8650 2550
Wire Wire Line
	8650 2550 8000 2550
Connection ~ 8000 2550
Wire Wire Line
	8650 1850 8650 1550
Wire Wire Line
	8650 1550 8000 1550
Connection ~ 8000 1550
$Comp
L agg-kicad:VCC #PWR?
U 1 1 5E6313B5
P 9300 3450
F 0 "#PWR?" H 9300 3560 50  0001 L CNN
F 1 "VCC" H 9300 3573 50  0000 C CNN
F 2 "" H 9300 3450 50  0001 C CNN
F 3 "" H 9300 3450 50  0001 C CNN
	1    9300 3450
	1    0    0    -1  
$EndComp
Connection ~ 9300 3500
Wire Wire Line
	9300 3500 8900 3500
Text HLabel 7450 2750 2    50   Input ~ 0
LIMIT_2A
Text HLabel 7450 2900 2    50   Input ~ 0
LIMIT_2B
$Comp
L agg-kicad:3v3 #PWR?
U 1 1 5E63DAF4
P 7350 2700
F 0 "#PWR?" H 7350 2810 50  0001 L CNN
F 1 "3v3" H 7350 2823 50  0000 C CNN
F 2 "" H 7350 2700 50  0001 C CNN
F 3 "" H 7350 2700 50  0001 C CNN
	1    7350 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2700 7350 2750
$Comp
L Device:R R?
U 1 1 5E649B2D
P 7250 3050
F 0 "R?" H 7320 3096 50  0000 L CNN
F 1 "R" H 7320 3005 50  0000 L CNN
F 2 "" V 7180 3050 50  0001 C CNN
F 3 "~" H 7250 3050 50  0001 C CNN
	1    7250 3050
	1    0    0    -1  
$EndComp
$Comp
L agg-kicad:GND #PWR?
U 1 1 5E649B37
P 7250 3200
F 0 "#PWR?" H 7120 3240 50  0001 L CNN
F 1 "GND" H 7250 3289 50  0000 C CNN
F 2 "" H 7250 3200 50  0001 C CNN
F 3 "" H 7250 3200 50  0001 C CNN
	1    7250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2900 7400 3300
Wire Wire Line
	7400 3300 7450 3300
Wire Wire Line
	7400 2900 7250 2900
Wire Wire Line
	7350 2750 7450 2750
Wire Wire Line
	7450 2900 7400 2900
Connection ~ 7400 2900
Wire Wire Line
	7450 3500 6150 3500
Wire Wire Line
	6300 3100 6150 3100
Wire Wire Line
	6950 3100 7100 3100
Wire Wire Line
	7100 3100 7100 2900
Wire Wire Line
	7100 2900 7250 2900
Connection ~ 6950 3100
Wire Wire Line
	6950 3100 6950 3000
Connection ~ 7250 2900
Text Notes 5800 4600 0    50   ~ 0
LIMIT_1_MCU - HIGH when FAULT
Text Notes 6300 3700 0    50   ~ 0
MOTOR_PWM1/2 - HIGH for GO
Wire Wire Line
	9300 3450 9300 3500
$Comp
L agg-kicad:VCC #PWR?
U 1 1 5E6A00FE
P 9350 2300
F 0 "#PWR?" H 9350 2410 50  0001 L CNN
F 1 "VCC" H 9350 2423 50  0000 C CNN
F 2 "" H 9350 2300 50  0001 C CNN
F 3 "" H 9350 2300 50  0001 C CNN
	1    9350 2300
	1    0    0    -1  
$EndComp
$Comp
L agg-kicad:GND #PWR?
U 1 1 5E6A2063
P 9350 2700
F 0 "#PWR?" H 9220 2740 50  0001 L CNN
F 1 "GND" H 9350 2789 50  0000 C CNN
F 2 "" H 9350 2700 50  0001 C CNN
F 3 "" H 9350 2700 50  0001 C CNN
	1    9350 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5E6A417D
P 9150 2500
F 0 "C?" H 9268 2546 50  0000 L CNN
F 1 "22u/35V" H 9268 2455 50  0000 L CNN
F 2 "" H 9188 2350 50  0001 C CNN
F 3 "~" H 9150 2500 50  0001 C CNN
	1    9150 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5E6A4BEF
P 9750 2500
F 0 "C?" H 9868 2546 50  0000 L CNN
F 1 "22u/35V" H 9868 2455 50  0000 L CNN
F 2 "" H 9788 2350 50  0001 C CNN
F 3 "~" H 9750 2500 50  0001 C CNN
	1    9750 2500
	1    0    0    -1  
$EndComp
Text Notes 6250 5150 0    50   ~ 10
NAND Gate, actually use 74AC00?? (check availability)
$EndSCHEMATC
