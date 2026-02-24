/* This program blinks the red LED on the
* TI Tiva LaunchPad. The connections are:
* PF1 - red LED
* PF2 - blue LED
* PF3 - green LED
* They are high active (a '1' turns on the LED).

#include "TM4C123GH6PM.h"
void delayMs(int n);
int main(void)
{
// enable clock to GPIOF at clock gating control register
SYSCTL->RCGCGPIO |= 0x20;
// enable the GPIO pins for the LED (PF3, 2 1) as output
GPIOF->DIR |= 0x0e;
// enable the GPIO pins for digital function
GPIOF->DEN |= 0x0e;
while(1)
{
GPIOF->DATA = 0x04; // turn on red LED
delayMs(500);
GPIOF->DATA = 0; // turn off red LED
delayMs(500);
}
}
// delay in milliseconds (16 MHz CPU clock)

void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} // do nothing for 1 ms
}

*/
/*
void delayMs(int N)
{
//N ms Delay mx 1000 Ms
	uint32_t delay_ticks = 16000*N; //16MHz clk * Nms
	
	SysTick->LOAD = delay_ticks-1;
	SysTick->CTRL = 0x5; //Enable the timer and choose sysclk 
	while((SysTick->CTRL & 0x10000) == 0) //wait until the Count flag is set
	{ }
	SysTick->CTRL = 0; //Stop the timer (Enable = 0) 
	
}
*/