#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	int t=0, i, j;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0,x=0,y=0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf_s(fp, "%d", &t);
	for (i = 0; i < t; i++)
	{
		fscanf_s(fp,"%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x, &y);
		
		int A = 0, B = 0;

		if ((x1 <= x) && (x <= x2) && (y1 <= y) && (y <= y2)) {
			A = 0;
			B = 0;
		}		
		else {
			if (x < x1) {
				if (y < y1) {
					A = (x1 - x)*(x1 - x) + (y1 - y)*(y1 - y);
					B = (x1 - x) + (y1 - y);
				}
				else if (y > y2) {
					A = (x1 - x)*(x1 - x) + (y2 - y)*(y2 - y);
					B = (x1 - x) + (y - y2);
				}
				else {
					A = (x1 - x)*(x1 - x);
					B = (x1 - x);
				}
			}
			else if ((x1 < x) && (x < x2)) {
				if (y < y1) {
					A = (y1 - y)*(y1 - y);
					B = (y1 - y);
				}
				else {
					A = (y - y2)*(y - y2);
					B = (y - y2);
				}
			
			}
			else if (x2 < x) {
				if (y < y1) {
					A = (x - x2)*(x - x2) + (y1 - y)*(y1 - y);
					B = (x - x2) + (y1 - y);
				}
				else if (y > y2) {
					A = (x - x2)*(x - x2) + (y - y2)*(y - y2);
					B = (x - x2) + (y - y2);
				}
				else {
					A = (x - x2)*(x - x2);
					B = (x - x2);
				}
			}
			else {
				if (y < y1) {
					A = (y1 - y)*(y1 - y);
					B = (y1 - y);
				}
				else if (y > y2) {
					A = (y - y2)*(y - y2);
					B = (y - y2);
				}
				
			}
		}
		printf("%d %d\n", A, B);
	
	}
	fclose(fp);
}