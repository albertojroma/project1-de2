/***********************************************************************
 * 
 * Use Analog-to-digital conversion to read joy-stick movements and button
 * and display it on LCD screen.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Components:
 *   16x2 character LCD with parallel interface
 *     VSS  - GND (Power supply ground)
 *     VDD  - +5V (Positive power supply)
 *     Vo   - (Contrast)
 *     RS   - PB0 (Register Select: High for Data transfer, Low for Instruction transfer)
 *     RW   - GND (Read/Write signal: High for Read mode, Low for Write mode)
 *     E    - PB1 (Read/Write Enable: High for Read, falling edge writes data to LCD)
 *     D3:0 - NC (Data bits 3..0, Not Connected)
 *     D4   - PD4 (Data bit 4)
 *     D5   - PD5 (Data bit 5)
 *     D6   - PD6 (Data bit 3)
 *     D7   - PD7 (Data bit 2)
 *     A+K  - Back-light enabled by PB2
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions

#define Pushbutton PD2      //arduino pin of encoder's pushbutton
uint8_t joybutton = 0;      //represents the state of joystick button

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and start ADC conversion every 100 ms.
 *           When AD conversion ends, send converted value to LCD screen.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize LCD display
    lcd_init(LCD_DISP_ON);

    // Set characters that won't change in the LCD
    lcd_gotoxy(1, 0); 
    lcd_puts("value:");
    lcd_gotoxy(3, 1); 
    lcd_puts("key:");

    // Enable input pull-up in PD2
    GPIO_mode_input_pullup(&DDRD, Pushbutton);

    // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVcc with external capacitor at AREF pin"
    ADMUX = ADMUX | (1<<REFS0);

    // Enable ADC module
    ADCSRA = ADCSRA | (1<<ADEN);
     
    // Enable conversion complete interrupt
    ADCSRA = ADCSRA | (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA = ADCSRA | (1<<ADPS2 | 1<<ADPS1 | 1<<ADPS0);   

    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Set prescaler to 33 ms and enable overflow interrupt
    TIM1_overflow_33ms();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Use Single Conversion mode and start conversion every 100 ms.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    joybutton = GPIO_read(&PIND, Pushbutton);

    if(ADMUX == 64){ // ADC0 = 0b0100_0000
        ADMUX = ADMUX | (1<<MUX0);
    } else { // ADC1 = 0b0100_0001
        ADMUX = ADMUX & ~(1<<MUX0);
    }
    // Start ADC conversion
    ADCSRA = ADCSRA | (1<<ADSC);
}

/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display converted value on LCD screen.
 **********************************************************************/
ISR(ADC_vect)
{
  
    uint16_t value;  // auxiliar variable
    char string[4];  // String for converted numbers by itoa()

    static uint8_t no_of_overflows = 0;
    // Read converted value
    // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
    value = ADC; 

    no_of_overflows++;  

    if (no_of_overflows >= 3) 
    {
      no_of_overflows = 0;
      itoa(value, string, 10);
      lcd_gotoxy(8,0);
      lcd_puts("    ");
      lcd_gotoxy(8,0); //this is done to properly update de value
      lcd_puts(string);

      if (ADMUX == 64) //ADC0 => X-axis 
      { 
        if (value < 20)
        {
          lcd_gotoxy(8,1);
          lcd_puts("left  ");  
        } else if (value > 1000)
        {
          lcd_gotoxy(8,1);
          lcd_puts("right ");
        }
      } else if (ADMUX == 65) //ADC1 => Y-axis
      { 
        if (value < 20)
        {
          lcd_gotoxy(8,1);
          lcd_puts("up    ");  
        } else if (value > 1000)
        {
          lcd_gotoxy(8,1);
          lcd_puts("down  ");
        }
      }

      if (joybutton == 0)
      {
        lcd_gotoxy(8,1);
        lcd_puts("      ");
      }         
    }
    // Else do nothing and exit the ISR       
  }