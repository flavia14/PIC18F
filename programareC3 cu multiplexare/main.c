#include <p18F4455.h>
#include <timers.h>
void main()
{

char vector[10]={0b00111111,0b0000110,0b1011011,0b1001111,0b1100110,0b01101101,0b01111100,0b00000111,0b01111111, 0b01101111};
int i;
int unitati, zeci, sute, mii;
int contor;


PORTD=0;
LATD=0;
PORTA=0;
LATA=0;
PORTB=0;
LATB=0;
TRISB=0b00011000;
TRISD=0b00000000;
TRISA=0;

ADCON1=0X0F; 
CMCON = 0x07;


T0CON=0b00000101;
TMR0H=0XB3;
TMR0L=0XB4;
INTCONbits.TMR0IF=0;
T0CONbits.TMR0ON=1;

i=0;
zeci=0;
unitati=0;
contor=0;
sute=0;
mii=0;

while(1)
{
PORTAbits.RA5=1;
PORTAbits.RA4=0;
PORTAbits.RA3=0;
PORTAbits.RA2=0;
LATD=vector[unitati];
Delay10KTCYx(1);

PORTAbits.RA4=1;
PORTAbits.RA5=0;
PORTAbits.RA3=0;
PORTAbits.RA2=0;
LATD=vector[zeci];
Delay10KTCYx(1);

PORTAbits.RA5=0;
PORTAbits.RA4=0;
PORTAbits.RA3=1;
PORTAbits.RA2=0;
LATD=vector[sute];
Delay10KTCYx(1);

PORTAbits.RA5=0;
PORTAbits.RA4=0;
PORTAbits.RA3=0;
PORTAbits.RA2=1;
LATD=vector[mii];
Delay10KTCYx(1);


	if(INTCONbits.TMR0IF==1)
	{
	T0CONbits.TMR0ON=0;
	INTCONbits.TMR0IF=0;
	if(PORTBbits.RB3==1)
		{unitati++;
		if(unitati==10)
			{
			unitati=0;
			zeci++;
			if(zeci==10)
			{
			zeci=0;
			sute++;
			if(sute==10)
				{sute=0;
				 mii++;
				if(mii==10)
				mii=0;
				}
				
			}
			}
		}
	else
		{
			unitati--;
		if(unitati==-1)
			{
			unitati=9;
			zeci--;
			if(zeci==-1)
			{
			zeci=9;
			sute--;
			if(sute==-1)
				{sute=9;
				 mii--;
				if(mii==-1)
				mii=9;
				}
				
			}
			}
		}

	if(PORTBbits.RB4==1)
		{
		TMR0H = 0x13;   
		TMR0L = 0x12;      
		T0CONbits.TMR0ON = 1; 
	

		}
	else
		
	{
		TMR0H = 0x26;   
		TMR0L = 0x25;
		INTCONbits.TMR0IF = 0;        
		T0CONbits.TMR0ON = 1; 
	
		
	}
}
}		
}