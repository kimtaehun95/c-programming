#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE *fp;
	int t, i;
	int a = 0, b = 0, c = 0;
	fopen_s(&fp,"input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf_s(fp, "%d", &t);
	for (i = 0; i<t; i++)
	{
		fscanf_s(fp, "%d %d %d", &a, &b, &c);


		if (a + b <= c)
			printf("0\n");
		else {
			if ((a == b) && (a == c) && (b == c))
				printf("1\n");
			else if ((a*a) + (b*b) == (c*c))
				printf("2\n");
			else if (((a == b) && (a != c)&&(b!=c))||((c==b)&&(b!=a)))
				printf("3\n");
			else
				printf("4\n");
		}
	}
	fclose(fp);
}