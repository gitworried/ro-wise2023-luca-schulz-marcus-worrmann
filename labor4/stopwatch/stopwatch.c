#include "blinky.h"
#include "usart.h"
#include "utils.h"

static volatile uint32_t halfseconds;

void _systick(void){
	halfseconds++;
	led_toggle();
}

void _start(){
	usart_init();
	led_init();

	int state = 0;
	int waitForRelease = 0;
	int clfl = 1;
	halfseconds = 0;
	char buf[20];
	volatile uint32_t val;

	while(1){
		if(clfl){
			halfseconds = 0;
			clfl = 0;
			clock_toggle();
		}
	  if (state && button() && !waitForRelease){
			state = 0;
			clfl = 1;
			val = *stk_value();
			format_ms(buf, sizeof(buf), cvr2ms(val, halfseconds));
			usart_puts(buf);
			waitForRelease = 1;
	  }
		else{
	    if (!state && button() && !waitForRelease){
				state = 1;
				clfl = 1;
				usart_puts("Start!");
				waitForRelease = 1;
	    }
			else{
	    	if (state && !button()){
					state = 1;
					waitForRelease = 0;
	    	}
				else{
	    		if (!state && !button()){
						state = 0;
						waitForRelease = 0;
	    		}
				}
			}
		}
	}
}
