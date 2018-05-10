#include <stdio.h>
#include <stdlib.h>


void main(void)
{
	FILE *fp;
	int i, j;
	int t, a, v;
	int max = 0, min = 0, num;
	fopen_s(&fp,"input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf_s(fp, "%d", &t);
	for (i = 0; i < t; i++)
	{
		fscanf_s(fp, "%d", &a);
		fscanf_s(fp, "%d", &v);
		max = min = v;
		for (j = 1; j < a; j++)
		{
			fscanf_s(fp, "%d", &num);
			max = max > num ? max : num;
			min = min < num ? min : num;
		}
		printf("%d %d\n", max, min);

	}
	fclose(fp);
}