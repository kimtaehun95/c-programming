#include<stdio.h>

int binom(int, int);
int main()
{
	int n, r;

	printf("이항 계수를 구하고 싶은 두 수 입력 : ");
	scanf_s("%d %d", &n, &r);

	printf("%dC%d = %d\n", n, r, binom(n, r));

	return 0;
}
int binom(int n, int r)
{
	if (n < r) {
		printf("앞의 수가 더 크게 입력하세요.\n");
		return 0;
	}
	if (r == 0 || n == r) return 1;
	else 
		return binom(n - 1, r - 1) + binom(n - 1, r);
	
}