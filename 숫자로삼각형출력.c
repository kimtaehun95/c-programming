#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *fp;
	int t, n;
	int a=0,b=0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) exit(1);
	fscanf_s(fp, "%d", &t);
	for (int i = 0; i < t; i++)
	{
		fscanf_s(fp, "%d", &n);
		for (int j = 0; j < n; j++)
		{
			++a;
			printf("%d", a);
			
			for (int k = 0; k < j; k++)
			{
				b +=(n-1-k);				
				printf(" %d", b);
			}
			b = a+1;
			printf("\n");
		}
		a = 0;
	}
	fclose(fp);
}
