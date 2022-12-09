# Project 1

### Team members

* Alberto Jesús Rodríguez Machado (responsible for xxx)
* Juan Gabriel Villarruel Aragón (responsible for xxx)

## Hardware description


### Arduino UNO
We have used the Arduino UNO board, which is based on the ATMEGA328P AVR chip.
Then, are shown needed devices in order to implement the Hardware descripction; an Analog joy-stick, a Digilent PmodCLP LCD module and an Arduino Uno michrocontroller:

![arduino pines](https://user-images.githubusercontent.com/114478665/205801328-98a1b3a3-3683-46dd-b304-cfa29902ad7a.jpeg)


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
1. DB0(Data Bit 0) not connected on the PmodCLP
2. DB1(Data Bit 1) not connected on the PmodCLP
3. DB2(Data Bit 2) not connected on the PmodCLP
4. DB3(Data Bit 3) not connected on the PmodCLP
5. GND connected to ground node
6. VCC connected to VCC node






    ### Joystick

![joystick-pinout](https://user-images.githubusercontent.com/114478665/205809645-354abd0d-8842-42dd-b8fd-089f4948db37.jpg)

* GND is connected to ground node 
* 5v is connected to VCC node
* Vrx outputs an analog value corresponding to the horizontal positin (called x-coordinate)
* Vry outputs an analog value corresponding to the vertical position (called y-coordinate)
* SW is the output from the pushbutton inside the joystick. It's normally oopen. If we use a pull-up resistor in this pin, the SW pin will be High when it is not pressed, and Low when it is pressed.


## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

https://www.youtube.com/watch?v=WugzbzgTG3k



## References

1. [lab4-lcd](https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/04-lcd)
2. [How to use joy-stick](https://www.robotique.tech/robotics/using-the-joystick-with-arduino/#google_vignette)
3. [lcd datasheet](https://digilent.com/reference/_media/pmod:pmod:pmodclp_rm.pdf)
4. [How to use rotary encoder](https://electronoobs.com/eng_arduino_tut125.php)
5. [Arduino Uno scheme](https://pighixxx.tumblr.com/tagged/Arduino%20Uno)
6. [ATmega328P datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061B.pdf)
