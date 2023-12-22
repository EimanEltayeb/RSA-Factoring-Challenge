#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void factorize(char *line)
{
	long long int num, y, x;

	num = atoi(line);
	while (x < num)
	{
		if (num % x == 0)
			break;
		else
			x++;
	}
	y = num / x;
	printf("%llu=%llu*%llu\n", num, y, x);
}

/**
 * 
*/
int main(int argc, char **argv)
{
	FILE *f;
	char *line;
	int i = 0;
	size_t n = 0;
	ssize_t l = 0;

	f = fopen(argv[1], "r");
	if (f == NULL)
		exit(EXIT_FAILURE);
	
	while (1)
	{
		l = getline(&line, &n, f);
		if (l == -1)
			break;
		factorize(line);
	}
	free(line);
	fclose(f);
	return (0);
}
