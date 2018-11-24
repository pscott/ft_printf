#include "ft_printf.h"

int	addingNumbers(int nHowMany, ... )
{
	int	nSum = 0;

	va_list intArgumentPointer;
	int		i;

	va_start(intArgumentPointer, nHowMany);
	i = 0;
	while (i < nHowMany)
	{
		nSum += va_arg(intArgumentPointer, int);
		i++;
	}
	va_end(intArgumentPointer);

	return (nSum);
}

void	print_int(int nHowMany, ... )
{
	va_list intArgumentPointer;
	int		i;

	va_start(intArgumentPointer, nHowMany);
	i = 0;
	while (i < nHowMany)
	{
		ft_putnbr(va_arg(intArgumentPointer, int));
		ft_putchar('\n');
		i++;
	}
	va_end(intArgumentPointer);
}

int		ft_printf(const char restrict *format, ...)
{
}

int	main(void)
{
	/*printf("\n 10 + 20 = %d ", addingNumbers(2, 10, 20));*/
	ft_printf("%d, %d, %d\n", -12, -13, 14);
	printf("%d, %d, %d\n", -12, -13, 14);
	return (0);
}

// need to create struct, put all info in it, then (maybe) use pointer funcions to print the struct with specs, then rince and repeat !
