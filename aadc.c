#include<reg51.h>
#include<stdio.h>
#define ADC P1
#define lcd P0
sbit rs =P2^7;
sbit rw = P2^6;
sbit en = P2^5;
sbit bf=P0^7;

void gen1();
void gen2();
int a,b,c,d,e,f,g,x,y,z;
x=0x30; y=100; z=10;
int h,s,m; 
void con();
void ready();
void gen();
void lcd_com (char ll);
void lcd_data (char lll );
void lcd_string(char *c);
void lcd_initial();

void delay(unsigned int itime)
{
unsigned int i,j;
for(i=0;i<itime;i++)
for(j=0;j<1275;j++);
}
 void main()
 {
	 P0=0x00;
	  P2=0x00;
	  P3=0x00;
	 ADC=0xff;
	 
	 lcd_initial();    
{
while(1)
{
	lcd_com(0x01);
	lcd_string("varying range");
lcd_com(0xc0);
	
	gen();
	delay(100);
}
}
}

void gen()
{
	 a=ADC ;
c=(a/100)+x;
 lcd_data(c);
	c=(a%100)/10+x;
 lcd_data(c);
	 c=(a%10)+x;
 lcd_data(c);
	delay(10);
	
}

 void con()
 {
 if(a<100)

 {
	 lcd_com(0x01);
	lcd_string(" under working ");
	 lcd_com(0xc0);
	 gen();
 }
 }
void lcd_com (char ll)
		{
			ready();
		lcd =ll;en = 1;
		rs = 0;
		rw = 0;
		en = 0;
		
		}
		
		void lcd_data (char lll)
		{
			ready();
			lcd = lll;
			en = 1;
			rs = 1;
			rw = 0;
			en = 0;
			
		}
		
		
		void ready()
		{
			bf=1;
			rs=0;
			rw=1;
			god:
			en=0;
			en=1;
			while(bf)
			goto god;
		}
		void lcd_initial()
{
	lcd_com (0x38);   
		lcd_com(0x0F);
	//lcd_com(0x0E);
		lcd_com(0x01);

}
		
	void lcd_string(char *c)
{
		while(*c!='\0') /*or while(*c)*/

	lcd_data(*c++);
			}