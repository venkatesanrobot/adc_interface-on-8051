#include<reg51.h>
#define lcd P0
sbit rs =P1^0;
sbit rw = P1^1;
sbit en = P1^2;
sbit bf=P0^7;

void ready();
void lcd_com (char ll);
void lcd_data (char lll );
void lcd_string(char *c);
void lcd_initial();

void delay(int i)
{
int j;
for(i=0;i<=j;i++)
	for(j=0;j<=10000;j++);

}
 

void main ()
{
	lcd = 0x00;
	rs = 0;
	rw = 0;
	en = 0;
	lcd_initial();
while(1)
	{	
		lcd_com(0x01);
	lcd_com(0x80);
 lcd_string("hello ");	
	lcd_com(0xc0);
	lcd_string(" venkey");
	 delay(5000);
			}
}
		void lcd_com (char ll)
		{
			ready();
		lcd =ll;
		 en = 1;
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
lcd_com (0x06);    
		lcd_com(0x01);
	lcd_com(0x1C);     /*ROTATE*/

}
		
	void lcd_string(char *c)
{
		while(*c!='\0') /*or while(*c)*/

	lcd_data(*c++);
			}
	

		
		