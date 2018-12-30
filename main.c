#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *c;

	c = "%*d\n";

	/*printf("RES: %d\n", */ft_printf(c, -21, 20);
	/*printf("RES: %d\n",  */  printf(c, -21, 20);
}
