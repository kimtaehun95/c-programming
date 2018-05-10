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
		
		for (int j = 1; j < sqrt(num); j++)//제곱근 전까지만 약수를 구한다.
											
		{
			
			if (num%j == 0) {
				count++;
				sum += j+(num / j);//구하려는 숫자를 구한 약수로 나눈 몫은 구한 약수에 대응되는 다른 약수이다.
			
			}
			
		}
		printf("%d %d\n", (count*2)-1,sum-num);//j가 1부터 시작되면 자기 자신의 수까지 포함시킨다.
		count = 0;
		sum = 0;
	}
	fclose(fp);
}