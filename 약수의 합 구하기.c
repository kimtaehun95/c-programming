#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	FILE *fp;
	int t = 0,num=0;
	int count = 0,sum=0;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) exit(1);
	fscanf_s(fp, "%d", &t);
	for (int i = 0; i < t; i++)
	{
		fscanf_s(fp, "%d", &num);
		
		for (int j = 1; j < sqrt(num); j++)//������ �������� ����� ���Ѵ�.
											
		{
			
			if (num%j == 0) {
				count++;
				sum += j+(num / j);//���Ϸ��� ���ڸ� ���� ����� ���� ���� ���� ����� �����Ǵ� �ٸ� ����̴�.
			
			}
			
		}
		printf("%d %d\n", (count*2)-1,sum-num);//j�� 1���� ���۵Ǹ� �ڱ� �ڽ��� ������ ���Խ�Ų��.
		count = 0;
		sum = 0;
	}
	fclose(fp);
}