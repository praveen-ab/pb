#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"timer0.h"
#include"adcc.h"
#include"interrupt01.h"
#include"doorcheck.h"

extern int flag1;
extern int flag2;


int main(void)
{
    initADC();
    inittimer0();
    initinterrupt01();
    DDRC&=~(1<<PC0);
    DDRC|=(1<<PC2);
    DDRD|=(1<<PD5);
    DDRD&=~(1<<PD4);
    PORTD|=(1<<PD4);
    uint16_t temp;
    while(1)
    {
          temp=readADC(0);
          if(flag1==1)
          {
              PORTC&=~(1<<PC2);
              doorcheck(temp);
          }
          if(flag2==1)
          {
              PORTC|=(1<<PC2);
              doorcheck(temp);

          }

    }

    return 0;
}


