#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *d;
	char *c;

	d = "{%s}\n";
	c = "salut";
	/*printf("RES: %d\n", */ft_printf(d, c);
	/*printf("RES: %d\n",  */  printf(d, c);
}
