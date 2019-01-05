#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *c;

	c = "{%ll#x}\n";
	/*printf("RES: %d\n", */ft_printf(c, 4294967296);
	/*printf("RES: %d\n",  */  printf(c, 4294967296);
}
