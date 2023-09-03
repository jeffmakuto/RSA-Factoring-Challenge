#include "factors.h"

/**
 * main - entry point
 * @argc: number of arguments passed
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS else EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	long long flag = 1, div, mod, num, count;
	ssize_t bytes_read;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	factorize(file);

	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * factorize - find and print factors of numbers from a file.
 * @file: pointer to the file containing numbers to be processed
 */
void factorize(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	long long flag, div, mod, num, count;

	while ((bytes_read = getline(&line, &len, file)) != -1)
	{
		flag = 1, div = 2;
		num = atoll(line);
		while (flag)
		{
			mod = num % div;
			if (!mod)
			{
				count = num / div;
				printf("%lld=%lld*%lld\n", num, count, div);
				flag = 0;
			}
			div++;
		}
	}

	free(line);
}
