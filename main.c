#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *c;

	c = "{%#.5o}\n";

	/*printf("RES: %d\n", */ft_printf(c, 2);
	/*printf("RES: %d\n",  */  printf(c, 2);
}
