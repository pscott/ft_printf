//header

#include "ft_printf.h"

LL	choose_value(t_arg *specs, LL value)
{
	if (specs->l == 2)
		value = value;
	else if (specs->l == 1)
		value = (L)value;
	else if (specs->h == 2)
		value = (signed char)value;
	else if (specs->h == 1)
		value = (short int)value;
	else
		value = (int)value;
	return (value);
}
