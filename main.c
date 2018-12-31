#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *c;
	char *d;

	d = "{%#-15x}\n";
	c = "{%05.*d}\n";

//	/*printf("RES: %d\n", */ft_printf(c, 20, -15, 50);
							   ft_printf(c, -4, 42);
	/*printf("RES: %d\n",  */  printf(c, -4, 42);
}
