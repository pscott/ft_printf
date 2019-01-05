#include <stdio.h>
#include <math.h>

/*int		pow(int num, int exp)
{
	int res;

	res = 1;
	if (exp == 0)
		return (res);
	if (num == 0)
		return (0);
	if (exp > 0)
	{
		while (exp)
		{
			res *= num;
			exp--;
		}
	}
	if (exp < 0)
	{
		while (exp)
		{
			res *= num;
			exp++;
		}
	}
	return (res);
}*/

/*void	disseque(float f, int& sign, int& exposant, long& mantisse)
{
	struct dissq {
		unsigned man1: 16;
		unsigned man2: 7;
		unsigned exp: 8;
		int sign: 1;
	} fb;

	fb = *(dissq*)&f;
	exposant = fb.exposant - 127;
	sign = fb.sign;
	mantisse = 0x800000 | fb.man1 | (long(fb.man2)) << 16;
	printf("%f\n", sign * (mantisse / 0x800000) * pow(2, exposant));
}*/

typedef union {
	float f;
	struct 	{
		unsigned int mant: 23;
		unsigned int exp: 8;
		unsigned int sign: 1;
	} parts;
} float_cast;

int	main(void)
{
	int	before;
	int after;

	float_cast d1 = { .f = 4.1234};

	printf("SIGN: %x\n", d1.parts.sign);
	printf("MANT: %x\n", d1.parts.mant);
	printf("EXP: %x\n", d1.parts.exp - 127);
	before = pow(2, d1.parts.exp - 127);
	printf("before: %d\n", before);
	d1.f = d1.f - pow(2, d1.parts.exp - 127);
	printf("SIGN: %d\n", d1.parts.sign);
	printf("MANT: %d\n", d1.parts.mant);
	printf("EXP: %d\n", d1.parts.exp - 127);
	after = pow(10, 127 - d1.parts.exp) / pow(2, 127 - d1.parts.exp);
	printf("AFTER: %d\n", after);
}
