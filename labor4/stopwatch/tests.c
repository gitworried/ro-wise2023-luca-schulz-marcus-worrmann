#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "utils.c" 

int main(void) {
  assert(cvr2ms(0, 0) == 500);
  assert(cvr2ms(0, 1) == 1000);
  assert(cvr2ms(0, 2) == 1500);
  assert(cvr2ms(1000000, 0) == 250);


char buf[20];

format_ms(buf, sizeof(buf), 0);
assert(strcmp(buf, "0.000") == 0);
format_ms(buf, sizeof(buf), 100);
assert(strcmp(buf, "0.100") == 0);
format_ms(buf, sizeof(buf), 5875);
assert(strcmp(buf, "5.875") == 0);
format_ms(buf, sizeof(buf), 12345);
assert(strcmp(buf, "12.345") == 0);
}
