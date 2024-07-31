#include<stm32f10x.h>
void delay_ms(uint16_t t); //initilizing a function
void delay_ms(uint16_t t)//delay function for 72 MHz ARM  controller 
{
  volatile unsigned long l=0;
  for(uint16_t i=0;i<=t;i++)
    {
      for(l=0;l<6000;l++)
        {
        }
    }
}
uint16_t e[16]={0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};//HEX VALUE TO ENABLE EACH PIN
int main()
{
  RCC->APB2ENR |=0xFC; //ENABLE THE CLOCK FOR THE GPIO PINS
  GPIOA->CRL = 0x33333333; //PA0 TO PA7 AS OUTPUTS
  GPIOA->CRH = 0x33333333; //PA8 TO PA15 AS OUTPUTS 
  while(1)
    {
			for(int i=0;i<16;i++)
       {
				 GPIOA-> ODR= e[i];//pirticular pins of port A set to high 
      delay_ms(1000);//dely for 100ms
       GPIOA-> ODR=0x0000;//all the pins of the PORT A  set to low
       delay_ms(1000);//dely for 100ms
			 }
    }
}
