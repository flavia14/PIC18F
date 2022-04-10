#include "p18f4455.h"
#include "delays.h"
#include "timers.h"
#include "adc.h"
#include "PWM.h"

void nota_do();
void nota_re();
void nota_mi();
void nota_fa();
void nota_sol();
void nota_la();
void nota_si();
void nota_do2();
void oda_bucuriei(float n);
void desteaptate_romane();
int Rez=0;
int low=0;
void nota_do()
{
	OpenPWM1(238);
	SetDCPWM1(477);
	PORTB=0b00000001;
}

void nota_re()
{
	OpenPWM1(211);
	SetDCPWM1(425);
	PORTB=0b00000010;
}

void nota_mi()
{
	OpenPWM1(191);
	SetDCPWM1(379);
	PORTB=0b00000100;
}

void nota_fa()
{
	OpenPWM1(179);
	SetDCPWM1(358);
	PORTB=0b00001000;
}
void nota_sol()
{
	OpenPWM1(160);
	SetDCPWM1(319);
	PORTB=0b00010000;
}
void nota_la()
{
	OpenPWM1(142);
	SetDCPWM1(284);
	PORTB=0b00100000;
}

void nota_si()
{
	OpenPWM1(127);
	SetDCPWM1(253);
	PORTB=0b01000000;
}
void nota_do2()
{
	OpenPWM1(120);
	SetDCPWM1(239);
	PORTB=0b10000000;
}

void main ()
{

	OSCCONbits.IRCF2=1;
	OSCCONbits.IRCF1=1;
	OSCCONbits.IRCF0=0;
	OSCCONbits.SCS1=1;
	LATC=0;
	TRISC=0;
	PORTB=0;
	LATB=0; 
	PORTD=0; 
	LATD=0;
	ADCON1=0x0F;
    CMCON=0x07;
	TRISD=0b00001111; 
	TRISB=0b00000000; 
	
	T2CON=0b0000111; 


	INTCONbits.GIE=1;				
	INTCONbits.TMR0IF=0;			
	RCONbits.IPEN=0;				
	INTCONbits.TMR0IE=1;			
	T0CONbits.TMR0ON=1;			

	T0CON=0b11111111;

	TMR0H=0xF8;
	TMR0L=0x5E;


 
//configurare convertor A/D
    ADCON0 = 0b00000001;
    ADCON1 = 0b00001110;
    ADCON2 = 0b00110110;

//reset ADIF
    PIR1bits.ADIF = 0; 

//setare go
    ADCON0bits.GO = 1; 
	LATAbits.LATA1=1;
	LATAbits.LATA2=0;

	while(1)
	{
	if(ADCON0bits.GO ==0) 
			{
			PIR1bits.ADIF = 0;
			Rez=ADRESH<<2;
			low=(ADRESH>>6)&0x03;
			Rez=Rez|low;
			if((Rez>=0)&&(Rez<=100))
			{  oda_bucuriei(0.5);
           
        	}  
    		if((Rez>=101)&&(Rez<=200))
			{   
			oda_bucuriei(1);	
            
        	}   
  			if((Rez>=201)&&(Rez<=300))
			{  
           	 oda_bucuriei(1.5);
             
        	}          
    		if((Rez>=301)&&(Rez<=400))
			{  oda_bucuriei(2);
           
			}  
    	 
			ADCON0bits.GO=1;
			} 
	}
}

void oda_bucuriei(float n)
{
	nota_mi();
	Delay10KTCYx(n*50);
	nota_mi();
	Delay10KTCYx(n*50);
	nota_fa();
	Delay10KTCYx(n*50);
	nota_sol();
	Delay10KTCYx(n*50);
	nota_sol();
	Delay10KTCYx(n*50);
	nota_fa();
	Delay10KTCYx(n*50);
	nota_mi();
	Delay10KTCYx(n*50);
	nota_re();
	Delay10KTCYx(n*50);
	nota_do();
	Delay10KTCYx(n*50);
	nota_do();
	Delay10KTCYx(n*50);
	nota_re();
	Delay10KTCYx(n*50);
	nota_mi();
	Delay10KTCYx(n*50);
	nota_mi();
	Delay10KTCYx(n*50);
	nota_re();
	Delay10KTCYx(n*50);
	nota_re();
	Delay10KTCYx(n*100);


	nota_mi();
	Delay10KTCYx(n*50);
	nota_mi();
	Delay10KTCYx(n*50);
	nota_fa();
	Delay10KTCYx(n*50);
	nota_sol();
	Delay10KTCYx(n*50);
	nota_sol();
	Delay10KTCYx(n*50);
	nota_fa();
	Delay10KTCYx(n*50);
	nota_mi();
	Delay10KTCYx(n*50);
	nota_re();
	Delay10KTCYx(n*50);
	nota_do();
	Delay10KTCYx(n*50);
	nota_do();
	Delay10KTCYx(n*50);
	nota_re();
	Delay10KTCYx(n*50);
	nota_mi();
	Delay10KTCYx(n*50);
	nota_re();
	Delay10KTCYx(n*50);
	nota_do();
	Delay10KTCYx(n*50);
	nota_do();
	Delay10KTCYx(n*100);

}

void desteaptate_romane()
{
	nota_re();
	Delay10KTCYx(50);
	nota_re();
	Delay10KTCYx(100);
	nota_mi();
	Delay10KTCYx(50);
	nota_fa();
	Delay10KTCYx(50);
	nota_sol();
	Delay10KTCYx(100);
	nota_la();
	Delay10KTCYx(50);
	nota_re();
	Delay10KTCYx(50);

	nota_re();
	Delay10KTCYx(50);
	nota_si();
	Delay10KTCYx(100);
	nota_la();
	Delay10KTCYx(50);
	nota_sol();
	Delay10KTCYx(50);
	nota_sol();
	Delay10KTCYx(100);
	nota_do();
	Delay10KTCYx(50);
	nota_si();
	Delay10KTCYx(100);
	nota_la();
	Delay10KTCYx(50);


}