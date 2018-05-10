#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int t = 0, i;
	int temp = 0;
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, y1 = 0, y2 = 0, y3 = 0, y4 = 0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf_s(fp, "%d", &t);
	for (i = 0; i < t; i++)
	{
		fscanf_s(fp, "%d %d %d %d", &x1, &y1, &x2, &y2);
		fscanf_s(fp, "%d %d %d %d", &x3, &y3, &x4, &y4);
		
		if (x1 == x2) {
			if (x3 > x4) {//오름차순정리 key point
				temp = x3;
				x3 = x4;
				x4 = temp;
			}
			temp = 0;
			if (y1 > y2) {
				temp = y1;
				y1 = y2;
				y2 = temp;
			}
			temp = 0;
			if ((x3 <= x1) && (x1 <= x4)) {
				if ((y1 <= y3) && (y3 <= y2)) {
					if ((y3 == y2) || (y3 == y1) || (x1 == x3) || (x1 == x4)) {
						printf("2\n");
					}
					else
						printf("1\n");
				}
				else
					printf("0\n");
			}
			else
				printf("0\n");
		}
		else if(y1==y2) {
			
			if (x1 > x2) {
				temp = x1;
				x1 = x2;
				x2 = temp;
			}
			temp = 0;
			if (y3 > y4) {
				temp = y3;
				y3 = y4;
				y4 = temp;
			}
			temp = 0;
			if ((y3 <= y1) && (y1 <= y4)) {
				if ((x1 <= x3) && (x3 <= x2)) {
					if ((y1 == y3) || (y4 == y1) || (x1 == x3) || (x2 == x3)) {
						printf("2\n");
					}
					else
						printf("1\n");
				}
				else
					printf("0\n");
			}
			else
				printf("0\n");
		}
	}

	
	fclose(fp);
}
