#include<stdio.h>

int binom(int, int);
int main()
{
	int n, r;

	printf("���� ����� ���ϰ� ���� �� �� �Է� : ");
	scanf_s("%d %d", &n, &r);

	printf("%dC%d = %d\n", n, r, binom(n, r));

	return 0;
}
int binom(int n, int r)
{
	if (n < r) {
		printf("���� ���� �� ũ�� �Է��ϼ���.\n");
		return 0;
	}
	if (r == 0 || n == r) return 1;
	else 
		return binom(n - 1, r - 1) + binom(n - 1, r);
	
}