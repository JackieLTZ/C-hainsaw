#include <stdio.h>

void cF(int min, int max, int step);

int main()
{
	int fahr, celsius;
	int min, max, step;

	min = 0;
	max = 300;
	step = 20;

	fahr = min;
	puts("Fahr to celsius table:");
	while (fahr <= max)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr += step;
	}

	printf("\n");
	printf("\n");

	puts("Celsius to fahr table:");
	cF(min, max, step);

	return 0;
}

void cF(int min, int max, int step)
{
	int celsius, fahr;

	for (celsius = min; celsius <= max; celsius += step)
	{
		fahr = (9 * celsius) / 5 + 32;
		printf("%d\t%d\n", celsius, fahr);
	}
}