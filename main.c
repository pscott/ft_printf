#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *c;

	c = "{% ld}\n";

	/*printf("RES: %d\n", */ft_printf(c, 2147483648);
	/*printf("RES: %d\n",  */  printf(c, 2147483648);
}
