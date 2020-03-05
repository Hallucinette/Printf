#include "libprintf.h"

int main(int ac, char const **argv)
{
	char *p = "123";
	char *c = "ra4g4dfg65ser1d";

	//my_printf("AZERTY %s %d %c\n", "QWERTY", 214748364, 'q');
	//printf("AZERTY %s %i %c\n", "QWERTY", 0x12, 'q');
	//printf("AZERTY %s %d %c\n", "QWERTY", 0x12, 'q');

	printf("   printf: %p\n", c);
	my_printf("my_printf: %p\n", c);

	return 0;
}