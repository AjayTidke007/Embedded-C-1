/**
 * @file main.c
 * @author DhyeyaPatel (https://github.com/DhyeyaPatel/Embedded-C.git)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
//#include <util/delay.h>

int main(void)
{
    DDRD |= (1<<PD3);       //output pin to led
    DDRD &= ~(1<<PD2);    //input pin to seat button(clear bit)
    DDRD &= ~(1<<PD4);    //input pin to heater(clear bit)

    /*Enabling pull ups at pin 2 and 4 of port D*/
    PORTD |= (1<<PD2);    //set bit
    PORTD |= (1<<PD4);    //set bit

    while(1)
    {

        if((!(PIND&(1<<PD2)))&(!(PIND&(1<<PD4))))
        {
            PORTD |= (1<<PD3);      //Turn On Led
        }

         else
        {
            PORTD &= ~(1<<PD3);     //Turn Off Led
        }
    }
    return 0;
}