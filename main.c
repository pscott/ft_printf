#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *c;

	c = "{%.40}\n";

	ft_printf(c, 123);
	   printf(c, 122);
}
