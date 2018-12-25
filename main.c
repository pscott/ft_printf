#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *c;

	c = "Salut le %p\n";

	ft_printf(c, c);
	   printf(c, c);
}
