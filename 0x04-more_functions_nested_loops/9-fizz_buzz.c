#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the numbers from 1 to 100
 * 3 multiples print Fizz
 * 5 multiples print Buzz
 * 3 & 5  multiples print FizzBuzz
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	char a[] = "Fizz";
	char b[] = "Buzz";
	char ab[] = "FizzBuzz";

	for (i = 1; i <= 100; i++)
	{
		if (i == 100)
			printf("%s", b);
		else if ((i % 3 == 0) && (i % 5 == 0))
			printf("%s ", ab);
		else if (i % 3 == 0)
			printf("%s ", a);
		else if (i % 5 == 0)
			printf("%s ", b);
		else
			printf("%d ", i);
	}
	printf("\n");
	return (0);
}
TASK 10 – 10-print_
