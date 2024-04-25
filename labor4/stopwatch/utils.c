#include "string.h"
#include "utils.h"

uint32_t cvr2ms(uint32_t cvr, uint32_t halfs){
  return halfs * 500 + 500*(0x1E8480 - cvr)/0x1E8480;
}


char *utoa(char *buf, uint32_t val) {
	uint32_t	v;
	char		c;

	v = val;

  
	do {
		v /= 10;
		buf++;
	} while(v != 0);

  
	*buf-- = 0;

  
	do {
		c = val % 10;
		val /= 10;
		c += '0';
		*buf-- = c;
	} while(val != 0);

	return ++buf;
}

void format_ms(char *buf, int buflen, uint32_t ms){
	char temp[buflen];
	uint32_t sec = ms / 1000;
	uint32_t mil = ms % 1000;
	utoa(temp, sec);
	for(int i = 0; temp[i] != 0; i++){
		*buf++ = temp[i];
	}
	*buf++ = '.';
	if(mil < 100)
		*buf++ = '0';
	if(mil < 10)
		*buf++ = '0';
	utoa(temp, mil);
	for(int i = 0; temp[i] != 0; i++){
		*buf++ = temp[i];
	}
	*buf = 0;
}
