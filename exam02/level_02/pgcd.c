#include "stdio.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	hcd;
	int	count;

	count = 1;
	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a > 0 && b > 0)
		{
			while (a != b)
			{
				if (a > b)
				{
					a = a - b;
					printf("a %d\n", a);
				}
				else
				{
					b = b - a;
					printf("b %d\n", b);
				}
			}
			printf("answer  %d\n", a);
		}
	}
	printf("\n");
	return (0);
}