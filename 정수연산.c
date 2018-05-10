#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *fp;
	int i;
	int n, a, b, c, d, e;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &n);

	for (i = 0; i<n; i++)
	{
		fscanf(fp, "%d %d", &a, &b);

		if (a>b) {
			c = a - b;
			d = a;
		}
		else
		{
			c = b - a;
			d = b;
		}

		if (a == b) {
			e = 1;
		}
		else {
			e = 0;
		}

		printf("%d %d %d %d %d %d %d %d\n", a + b, a - b, c, a*b, a / b, a%b, d, e);
	}
	fclose(fp);
}