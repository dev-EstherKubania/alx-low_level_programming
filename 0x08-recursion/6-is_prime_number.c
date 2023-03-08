#include "main.h"

/**
 * is_prime_number - says if an integer is a prime number or not
 * @n: number to evaluate
 *
 * Return: 1 if n is a prime number, 0 if not
 */
int is_prime_number(int n)
{
	 if (n <= 1) {
        return 0;  // 1 is not a prime number
    }
    if (n <= 3) {
        return 1;  // 2 and 3 are prime numbers
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;  // numbers divisible by 2 or 3 are not prime
}
