
#include <stdio.h>
#include "printf.h"

int main(void)
{
	int number = 54;
	char *str = "Bonjour";
	int *ptr;
	ptr = &number;

	int returnedprintf;
	int returnedft_printf;

	returnedft_printf = ft_printf("%d %i %u %c %s %p %x %X %%\n", 1, -1, 4294967296, 'q', str, ptr, 4294967295, 4294967295);
	returnedprintf = ft_printf("%d %i %u %c %s %p %x %X %%\n", 1, -1, 4294967296, 'q', str, ptr, 4294967295, 4294967295);
	//printf("%d\n", returnedft_printf);
	printf("My return : %d\nPrintf return : %d\n", returnedft_printf, returnedprintf);

	return (0);
}
