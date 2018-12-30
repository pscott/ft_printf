//missing header

#include "ft_printf.h"

void	wildcard(t_arg *specs, int value)
{
	if (value < 0)
		specs->left = 1;
	specs->width = 1;
	if (value == -2147483647)
		specs->width_len = 0;
	else
		specs->width_len = value >= 0 ? value : -value;
	specs->wc--;
}
