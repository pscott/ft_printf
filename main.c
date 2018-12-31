#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *c;
	char *d;

	c = "{%25llx}\n";

	/*printf("RES: %d\n", */ft_printf(c, LONG_MAX);
	/*printf("RES: %d\n",  */  printf(c, LONG_MAX);
}
