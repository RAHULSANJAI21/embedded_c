#include<AT89S52.h>
#define DATABUS P2
#define RS P1_0
#define RW P1_1
#define EN P1_2
#include<LCD.h>
int main()
{
	lcd_init();
	lcd_print("HELLO WORLD");
	while(1)
	{

	}
}
