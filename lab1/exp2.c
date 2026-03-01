/* This program blinks the red LED on the
* TI Tiva LaunchPad. The connections are:
* PF1 - red LED
* PF2 - blue LED
* PF3 - green LED
* They are high active (a '1' turns on the LED).
*/
#include "TM4C123GH6PM.h"
void delayMs(int n);
int main(void)
{
		uint8_t blue = 0x04; //init blue
		uint8_t red = 0x02; //init red
		uint8_t green = 0x08; //
		int running = 1;
	
		uint8_t col = blue;
	
// enable clock to GPIOF at clock gating control register
SYSCTL->RCGCGPIO |= 0x20;
	//lock and commit PF0
	
		//set gpio lock
	
	GPIOF -> LOCK = 0x4C4F434B; //unlockes
		
		//set commit reg
	
	GPIOF->CR = 0x01;
	
	// enable the GPIO pins for digital function
	GPIOF->DEN |= 0x1f;
	
	
	// enable the GPIO pins for the LED (PF3, 2 1) as output
	GPIOF->DIR |= 0x0e;

	
	//set  switch active low, using pull up reg
	
	GPIOF->PUR = 0x11;
	
	GPIOF->DATA = blue;

while(1)
{ 
	if((GPIOF->DATA & 0x01) ==0){ //if sw2 pressed
		running = !running;
	}

	//switching colors
	if(running){
		if (col == 0x00){
			col = blue;}
		if((GPIOF->DATA & 0x10) ==0){ //if sw1 pressed
			if (col == blue){
				col = green;
			}else if(col == green){
				col = red;
			}else if (col ==red){
				col = blue;
			} else if (col == 0x00){
			col = blue;}
		}
}else{
			col = 0x00;}
	
	GPIOF->DATA = col; // turn on blue LED
	delayMs(500);
	GPIOF->DATA = 0; // turn off blue LED
	delayMs(500);
	}
}
// delay in milliseconds (16 MHz CPU clock)

void delayMs(int N)
{
//N ms Delay mx 1000 Ms
	uint32_t delay_ticks = 16000*N; //16MHz clk * Nms
	
	SysTick->LOAD = delay_ticks-1;
	SysTick->CTRL = 0x5; /*Enable the timer and choose sysclk */
	while((SysTick->CTRL & 0x10000) == 0) /*wait until the Count flag is set */
	{ }
	SysTick->CTRL = 0; /*Stop the timer (Enable = 0) */
	
}
