#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	int t = 0, n = 0;
	int i, j,k;
	int sum = 0;
	int x[sizeof(int)*100] = { 0 }, y[sizeof(int) * 100] = { 0 };
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) exit(1);
	fscanf_s(fp, "%d", &t);
	for (i = 0; i < t; i++)
	{
		fscanf_s(fp, "%d", &n);
		for (j = 0; j < n;j++)
		{
			fscanf_s(fp, "%d %d", &x[j], &y[j]);
			
		}
		x[n] = x[0];//key point
		y[n] = y[0];
		for (k = 0; k < n; k++)
		{
			sum += (x[k] + x[k + 1])*(y[k + 1] - y[k]);

		}
		if (sum > 0)
			printf("%d 1\n",sum);
		else if (sum < 0)
			printf("%d -1\n",-sum);
		sum = 0;
		
		
	}
	fclose(fp);
}