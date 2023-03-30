#include<AT89S52.h>//include header for AT89S52
#define LED P2_0 
#define ON 0
#define OFF 1
#define SW P3_3
#define INPUT 1
void main()
{
	SW=INPUT;
	LED=OFF;
	while(1)
	{
	     
		while(!SW)
		{
			LED=ON;
			delay(75);
			LED=OFF;
			delay(75);
		}
	     LED=OFF;
	}

}
