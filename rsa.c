#include "factors.h"

/**
 * is_prime - check if a number is prime.
 * @num: The number to check for primality.
 * Return: 1 if prime, 0 if not prime.
 */
int is_prime(long long num)
{
	long long i;

	if (num <= 1)
		return (0);
	if (num <= 3)
		return (1);
	if (num % 2 == 0 || num % 3 == 0)
		return (0);

	for (i = 5; i * i <= num; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return (0);
	}
	return (1);
}

/**
 * prime_factors - find and print the two prime factors of a number.
 * @num: the number for which prime factors are to be found and printed.
 */
void prime_factors(long long num)
{
	long long p, q;

	for (p = 2; p <= num; p++)
	{
		if (num % p == 0 && is_prime(p))
		{
			q = num / p;
			if (is_prime(q))
			{
				printf("%lld=%lld*%lld\n", num, q, p);
				return;
			}
		}
	}
}

/**
 * main - entry point
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	long long num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((bytes_read = getline(&line, &len, file)) != -1)
	{
		num = atoll(line);
		prime_factors(num);
	}
	free(line);
	fclose(file);

	exit(EXIT_SUCCESS);
}

