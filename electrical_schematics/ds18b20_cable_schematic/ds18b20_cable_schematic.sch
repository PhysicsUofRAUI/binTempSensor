EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Connector:Conn_01x03_Male J?
U 1 1 612A7F52
P 2500 3650
F 0 "J?" H 2608 3931 50  0000 C CNN
F 1 "Conn_01x03_Male" H 2608 3840 50  0000 C CNN
F 2 "" H 2500 3650 50  0001 C CNN
F 3 "~" H 2500 3650 50  0001 C CNN
	1    2500 3650
	1    0    0    -1  
$EndComp
$Comp
L dk_Temperature-Sensors-Analog-and-Digital-Output:DS18B20_ U?
U 1 1 612A870C
P 4350 3600
F 0 "U?" H 4478 3653 60  0000 L CNN
F 1 "DS18B20_" H 4478 3547 60  0000 L CNN
F 2 "digikey-footprints:TO-92-3" H 4550 3800 60  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 4550 3900 60  0001 L CNN
F 4 "DS18B20+-ND" H 4550 4000 60  0001 L CNN "Digi-Key_PN"
F 5 "DS18B20+" H 4550 4100 60  0001 L CNN "MPN"
F 6 "Sensors, Transducers" H 4550 4200 60  0001 L CNN "Category"
F 7 "Temperature Sensors - Analog and Digital Output" H 4550 4300 60  0001 L CNN "Family"
F 8 "https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 4550 4400 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/maxim-integrated/DS18B20-/DS18B20--ND/956983" H 4550 4500 60  0001 L CNN "DK_Detail_Page"
F 10 "SENSOR DIGITAL -55C-125C TO92-3" H 4550 4600 60  0001 L CNN "Description"
F 11 "Maxim Integrated" H 4550 4700 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4550 4800 60  0001 L CNN "Status"
	1    4350 3600
	1    0    0    -1  
$EndComp
$Comp
L dk_Temperature-Sensors-Analog-and-Digital-Output:DS18B20_ U?
U 1 1 612A8B91
P 5700 3600
F 0 "U?" H 5828 3653 60  0000 L CNN
F 1 "DS18B20_" H 5828 3547 60  0000 L CNN
F 2 "digikey-footprints:TO-92-3" H 5900 3800 60  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 5900 3900 60  0001 L CNN
F 4 "DS18B20+-ND" H 5900 4000 60  0001 L CNN "Digi-Key_PN"
F 5 "DS18B20+" H 5900 4100 60  0001 L CNN "MPN"
F 6 "Sensors, Transducers" H 5900 4200 60  0001 L CNN "Category"
F 7 "Temperature Sensors - Analog and Digital Output" H 5900 4300 60  0001 L CNN "Family"
F 8 "https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 5900 4400 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/maxim-integrated/DS18B20-/DS18B20--ND/956983" H 5900 4500 60  0001 L CNN "DK_Detail_Page"
F 10 "SENSOR DIGITAL -55C-125C TO92-3" H 5900 4600 60  0001 L CNN "Description"
F 11 "Maxim Integrated" H 5900 4700 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5900 4800 60  0001 L CNN "Status"
	1    5700 3600
	1    0    0    -1  
$EndComp
$Comp
L dk_Temperature-Sensors-Analog-and-Digital-Output:DS18B20_ U?
U 1 1 612A8EE0
P 6850 3550
F 0 "U?" H 6978 3603 60  0000 L CNN
F 1 "DS18B20_" H 6978 3497 60  0000 L CNN
F 2 "digikey-footprints:TO-92-3" H 7050 3750 60  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 7050 3850 60  0001 L CNN
F 4 "DS18B20+-ND" H 7050 3950 60  0001 L CNN "Digi-Key_PN"
F 5 "DS18B20+" H 7050 4050 60  0001 L CNN "MPN"
F 6 "Sensors, Transducers" H 7050 4150 60  0001 L CNN "Category"
F 7 "Temperature Sensors - Analog and Digital Output" H 7050 4250 60  0001 L CNN "Family"
F 8 "https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 7050 4350 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/maxim-integrated/DS18B20-/DS18B20--ND/956983" H 7050 4450 60  0001 L CNN "DK_Detail_Page"
F 10 "SENSOR DIGITAL -55C-125C TO92-3" H 7050 4550 60  0001 L CNN "Description"
F 11 "Maxim Integrated" H 7050 4650 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7050 4750 60  0001 L CNN "Status"
	1    6850 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3900 3850 3900
Wire Wire Line
	2700 3900 2700 3750
Wire Wire Line
	5700 3900 5700 4300
Wire Wire Line
	5700 4300 4850 4300
Wire Wire Line
	3850 4300 3850 3900
Connection ~ 3850 3900
Wire Wire Line
	3850 3900 2700 3900
Wire Wire Line
	6850 3850 6850 4600
Wire Wire Line
	6850 4600 4850 4600
Wire Wire Line
	4850 4600 4850 4300
Connection ~ 4850 4300
Wire Wire Line
	4850 4300 3850 4300
Wire Wire Line
	4050 3600 3850 3600
Wire Wire Line
	2950 3600 2950 3650
Wire Wire Line
	2950 3650 2700 3650
Wire Wire Line
	5400 3600 5400 3250
Wire Wire Line
	5400 3250 4950 3250
Wire Wire Line
	3850 3250 3850 3600
Connection ~ 3850 3600
Wire Wire Line
	3850 3600 2950 3600
Wire Wire Line
	6550 3550 6550 3100
Wire Wire Line
	6550 3100 4950 3100
Wire Wire Line
	4950 3100 4950 3250
Connection ~ 4950 3250
Wire Wire Line
	4950 3250 3850 3250
Wire Wire Line
	6850 3250 6850 2850
Wire Wire Line
	6850 2850 5700 2850
Wire Wire Line
	3050 2850 3050 3550
Wire Wire Line
	3050 3550 2700 3550
Wire Wire Line
	4350 3300 4350 2850
Connection ~ 4350 2850
Wire Wire Line
	4350 2850 3050 2850
Wire Wire Line
	5700 3300 5700 2850
Connection ~ 5700 2850
Wire Wire Line
	5700 2850 4350 2850
Text Notes 3050 5250 0    50   ~ 0
Note:\nThere is no pull up resistor here since that resistor is located on the PCB board. \nI created this schematic to better show the wiring of the cables. It basically\ngoes that the three sensors are spread out between 4 and 7ft apart\n(whatever you decide) and have to be connected to the same wires and\nthen those wire are connected to the PCB.\nI hope this is clear if not it would be great if people reached out.
$EndSCHEMATC
