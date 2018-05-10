#include <stdio.h>
#include <stdlib.h>


void main(void)
{
	FILE *fp;
	int i, j;
	int t, a, v = 1;
	int num, r;
	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &t);
	for (i = 0; i < t; i++)
	{
		fscanf(fp, "%d", &a);

		for (j = 1; j <= a; j++)
		{
			fscanf(fp, "%d", &num);
			r = num % 10;
			v = (v*r) % 10;

		}
		printf("%d\n", v);
		v = 1;

	}
	fclose(fp);
}