# Project 1

### Team members

* Alberto Jesús Rodríguez Machado (responsible for joy-stick movement)
* Juan Gabriel Villarruel Aragón (responsible for joy-stick button)

## Hardware description


### Arduino UNO

We have used the Arduino UNO board, which is based on the ATMEGA328P AVR chip.
Then, are shown needed devices in order to implement the Hardware descripction; an Analog joy-stick, a Digilent PmodCLP LCD module and an Arduino Uno michrocontroller:

![arduino pines](https://user-images.githubusercontent.com/114478665/205801328-98a1b3a3-3683-46dd-b304-cfa29902ad7a.jpeg)

### Scheme

![Scheme](https://user-images.githubusercontent.com/114478211/206809155-5146905e-69a0-4d58-9042-1b07a9d2cd11.jpg)

### LCD module connections

The PmodCLP utilizes a Samsung KS0066 LCD controller to display information to a Sunlike LCD panel. The module can execute a variety of instructions, such as erasing specific characters, setting different display modes, scrolling, and displaying user-defined characters.

![LCD](https://user-images.githubusercontent.com/114478665/205805599-93924876-041f-4d80-b408-3c0fd2f10418.png)

Our connections:

- Header J2
1. RS (Register Select) connected to PB0
2. R/W (Read/Write signal) connected to GND
3. E (Read/Write Enable) connected to PB1
4. NC connected to GND
5. GND connected to ground node
6. VCC connected to VCC node

- Header J1-Bottom Half
7. DB4 (Data Bit 4) connected to digital port PD4
8. DB5 (Data Bit 5) connected to digital port PD5
9. DB6 (Data Bit 6) connected to digital port PD6
10. DB7 (Data Bit 7) connected to digital port PD7
11. GND connected to ground node
12. VCC connected to VCC node

- Header J1-Top Half
There is no need to connect any of the pins for our proyect

### Joystick

![joystick-pinout](https://user-images.githubusercontent.com/114478665/205809645-354abd0d-8842-42dd-b8fd-089f4948db37.jpg)

* GND is connected to ground node 
* 5v is connected to VCC node
* Vrx outputs an analog value corresponding to the horizontal positin (called x-coordinate)
* Vry outputs an analog value corresponding to the vertical position (called y-coordinate)
* SW is the output from the pushbutton inside the joystick. It's normally open. If we use a pull-up resistor in this pin, the SW pin will be High when it is not pressed, and Low when it is pressed.


## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders. <br/>

This project contains a total of 7 files with this structure: <br/>

```c
├── include
│    └── timer.h
├── lib
│    │   ├── gpio
│    │   ├── gpio.c
│    │   └── gpio.h
│    └── lcd
│         ├── lcd_definitions.h
│         ├── lcd.c
│         └── lcd.h
└── src
     └── main.c 
```
* [timer.h](https://github.com/albertojroma/project1-de2/blob/main/lab9-project1/include/timer.h) Timer library for AVR-GCC
* [gpio.c](https://github.com/albertojroma/project1-de2/blob/main/lab9-project1/lib/gpio/gpio.c) Contains function definitions for GPIO AVR-GCC
* [gpio.h](https://github.com/albertojroma/project1-de2/blob/main/lab9-project1/lib/gpio/gpio.h) The library contains functions for controlling AVRs' gpio pin(s)
* [lcd_definitions.h](https://github.com/albertojroma/project1-de2/blob/main/lab9-project1/lib/lcd/lcd_definitions.h) The library contains functions for Adjusting the display settings 
* [lcd.c](https://github.com/albertojroma/project1-de2/blob/main/lab9-project1/lib/lcd/lcd.c) Contains basic routines definitions for interfacing a HD44780U-based text lcd display
* [lcd.h](https://github.com/albertojroma/project1-de2/blob/main/lab9-project1/lib/lcd/lcd.h) Basic routines for interfacing a HD44780U-based character LCD display
* [main.c](https://github.com/albertojroma/project1-de2/blob/main/lab9-project1/src/main.c) use Analog-to-digital conversion to read joy-stick movements and button and display it on LCD screen. These are its flowdiagrams

* Main function
![Main function](https://user-images.githubusercontent.com/114478211/207087037-c18011d3-c160-437d-851f-5536496ef7d7.jpg)

* TIMER1_OVF <br/>
![Timer1_OVF](https://user-images.githubusercontent.com/114478211/207087175-5a7c713d-fa7c-4c21-b8b6-89252cddb5d6.jpg)

* ADC <br/>
![ADC_vect](https://user-images.githubusercontent.com/114478211/207087324-8a873971-f8fe-422e-80f4-9cffa5887098.jpg)


## Video
https://user-images.githubusercontent.com/114478211/206811537-af3ff59d-5ea7-48df-b456-e39d1ad0dfa5.mp4

## References

1. [lab4-lcd](https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/04-lcd)
2. [How to use joy-stick](https://www.robotique.tech/robotics/using-the-joystick-with-arduino/#google_vignette)
3. [lcd datasheet](https://digilent.com/reference/_media/pmod:pmod:pmodclp_rm.pdf)
4. [How to use rotary encoder](https://electronoobs.com/eng_arduino_tut125.php)
5. [Arduino Uno scheme](https://pighixxx.tumblr.com/tagged/Arduino%20Uno)
6. [ATmega328P datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061B.pdf)
