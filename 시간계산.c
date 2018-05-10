#include <stdio.h>
#include <stdlib.h>


void main(void)
{
	FILE *fp;
	int t;
	int n;
	int H, M, S, h, m, s;
	int a, b, c,d=0;
	int A=0, B=0, C=0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf_s(fp,"%d", &t);
	for (int i = 0; i < t; i++)
	{
		fscanf_s(fp,"%d", &n);
		
		for (int j = 0; j < n; j++)
		{
			fscanf_s(fp, "%d %d %d %d %d %d", &H, &M, &S, &h, &m, &s);
			
			c = s - S;
			a = h - H;
			b = m - M;
			if (a < 0) {
				a += 24;
			}
				if (c < 0) {
					c += 60;
					b -= 1;
				}
				if (b < 0) {

					b += 60;
					a -= 1;
				}
				if ((c < 0) && (b < 0)) {
					c += 60;
					b += 59;
					a -= 1;
				}
			
			A += a;
			B += b;
			C += c;
		}
		B += C / 60;
		A += B / 60;
		d = A / 24;
		C %= 60;
		B %= 60;
		A %= 24;

		printf("%d %d %d %d\n", d, A, B, C);
		A = B = C = d = 0;
	}
	fclose(fp);
}
