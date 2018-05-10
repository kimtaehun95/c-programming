#include <stdio.h>

int fibo(int);

int main()
{
	int n=0;

	printf("피보나치수열의 개수 입력 = ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf(" %d", fibo(i));
	}
	printf("\n");
	

	return 0;
}
int fibo(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);


}