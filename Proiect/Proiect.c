#include "p18f4455.h"
#include "delays.h"
#include "timers.h"
#include "pwm.h"

#define s1 PORTCbits.RC0
#define s2 PORTCbits.RC1
#define s3 PORTCbits.RC4
#define s4 PORTCbits.RC5
#define s5 PORTCbits.RC6
#define s6 PORTCbits.RC7

int seg[12];
int t=15;

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
	ClosePWM1();
	Delay10KTCYx(3);

}
void main()
{

seg[1]  =0b00000110;          //I
seg[2]  =0b00000000;          //I
seg[3]  =0b00110111;          //A
seg[4]  =0b01000100;          //A
seg[5]	=0b00001111;		  //3
seg[6]	=0b11000000;
//Configurare oscilator intern pentru 4MHz
OSCCONbits.IRCF2 = 1;
OSCCONbits.IRCF1 = 1; 
OSCCONbits.IRCF0 = 0;
OSCCONbits.SCS1 = 1; 
     
TRISA=0b00000000;
PORTA=0;
LATA=0;

TRISC=0b10000000;
PORTC=0;

TRISD=0b10000000;
PORTD=0;
LATD = 0;

TRISB=0b10000000;
PORTB=0;
LATB = 0;

TRISCbits.TRISC2 = 0;    
T2CONbits.TMR2ON = 0;    //Opresc Timer 2  
T2CONbits.T2CKPS1 = 1;   //Predivizor 16        
T2CONbits.T2CKPS0 = 1; 
T2CONbits.TMR2ON = 1;    //Pornesc Timer 2

while(1)
{

if(PORTCbits.RC7 == 0)
{

LATA=0b00000100;
oda_bucuriei(2);

}

if(PORTBbits.RB7 == 0)
{
oda_bucuriei(3);
 LATA=0b00000001;
   
  

}


if(PORTDbits.RD7== 0)
{
LATA=0b00000010;
LATB = seg[3];
LATD = seg[4];
s1=0;
Delay1KTCYx(3);
s1=1;
   
LATB = seg[1];
LATD = seg[2];
s2=0;
Delay1KTCYx(3);
s2=1;
   
LATB = seg[3];
LATD = seg[4];
s3=0;
Delay1KTCYx(3);
s3=1;

LATB = seg[5];
LATD = seg[6];
s5=0;
Delay1KTCYx(3);
s5=1;
}
else 
{
LATA=0b00000000;
s2=1;
s3=1;
s4=1;
s1=1;
s5=1;
}
}
}
