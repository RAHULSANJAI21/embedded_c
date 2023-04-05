 #include <AT89S52.h>
#define FOSC 11059200
#define TCLK FOSC/12
#define SCLK TCLK/32
#define LED P2_0
#define DATABUS P2
#define RS P1_0
#define RW P1_1
#define EN P1_2
#include<LCD.h>
void baud_rate(int);
void send_msg(char*);
void wait (char);

void main()
{
 char a;
 int b;
 baud_rate(9600);

 LED=1;/*LED OFF*/
 lcd_init();
 lcd_print("INITIAL");
 while(1)
 {
  if(RI==1)
  {
  RI=0;
  lcd_cmd(0x01);
   a=SBUF;
   if(a=='1')
   {
	lcd_cmd(0x01);
	lcd_print("LED ON");
   }
   else if(a=='0')
   {
	lcd_cmd(0x01);
	lcd_print("LED OFF");
   }
	else
	{
		lcd_cmd(0x01);
		lcd_print("INVALID INPUTS");
	}
  }
 }
}

void baud_rate(int baud)
{
 char b;
 SCON=0X50;
 TMOD=0x20;
 b=(0xFF-(SCLK/baud))+1;
 TH1=b;
 TL1=b;
 TR1=1;
}

void send_msg(char *m)
{
 while(*m!=0)
 {
  SBUF=*m;
  *m++;
  while(TI==0)
  {}
  TI=0;
 }
}

void wait (char d)
{
 char i;
 int j;
 for(i=0;i<d;i++)
 {
  for(j=0;j<1275;j++)
  {}
 }
}
