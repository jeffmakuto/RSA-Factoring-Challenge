#include "main.h"

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
	fclose(file);
	exit(EXIT_SUCCESS);
}
