#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	int t=0;
	int i;
	int s;
	int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf_s(fp, "%d", &t);
	for (i = 0; i < t; i++) {
		fscanf_s(fp, "%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

		s = ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));

		if (s > 0) {
			printf("%d 1\n", s);
		}
		else if (s < 0) {
			printf("%d -1\n", -s);
		}
		else {
			printf("%d 0\n", s);
		}
		s = 0;
	}
	fclose(fp);
}