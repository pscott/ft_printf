#include "ft_printf.h"

int main(void)
{
	printf("My num: %s\n", convert(0, 16, "0123456789abcdef"));
	return (1);
}
