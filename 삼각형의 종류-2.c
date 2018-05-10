#include<stdio.h>
#include<stdlib.h>

int dist2(int, int, int, int);
int main()
{
	FILE *fp;
	int x1=0, x2=0, x3=0, y1=0, y2=0, y3=0;
	int t=0;
	int a, b, c, d, s;
	
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf_s(fp, "%d", &t);
	for (int i = 0; i < t; i++) {
		fscanf_s(fp, "%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

		a = dist2(x1, y1, x2, y2);
		b = dist2(x2, y2, x3, y3);
		c = dist2(x1, y1, x3, y3);
		s = ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));//key point
		if (s == 0)
			printf("0\n");
		else {
			if (a > c) {
				d = a;
				a = c;
				c = d;
			}
			if (b > c) {
				d = b;
				b = c;
				c = d;
			}
			if (c == a + b)
				printf("1\n");
			else if (c > a + b)
				printf("2\n");
			else if (c < a + b)
				printf("3\n");
		}
		s = 0;//key point
	}
	fclose(fp);
}

int dist2(int x1, int y1, int x2, int y2)
{
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}