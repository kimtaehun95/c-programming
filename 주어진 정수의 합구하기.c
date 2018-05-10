#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *fp;
	int i, j;
	int t, a, b;
	int sum = 0;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &t);

	for (i = 0; i<t; i++)
	{
		fscanf(fp, "%d", &a);

		for (j = 0; j<a; j++)
		{
			fscanf(fp, "%d ", &b);
			sum = sum + b;
		}
		printf("%d\n", sum);
		sum = 0;
	}
	fclose(fp);
}