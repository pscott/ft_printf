#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *c;

	c = "{%-010p}\n";

	ft_printf(c, 123);
	   printf(c, 123);
}
