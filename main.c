#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *c;

	c = "Salut le %0p\n";

	ft_printf(c, NULL);
	   printf(c, NULL);
}
