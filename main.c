#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *d;
	long double c;

	d = "{%Lf}\n";
	c = 0.124;
	/*printf("RES: %d\n", */ft_printf(d, c);
	/*printf("RES: %d\n",  */  printf(d, c);
}
