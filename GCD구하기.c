#include <stdio.h>
int GCD(int, int);
int main()
{
	int n1, n2;
	printf("�ִ������� ���ϰ� ���� �� ���� �Է� :");
	scanf_s("%d %d", &n1, &n2);

	printf("%d �� %d �� �ִ� ����� = %d\n", n1, n2, GCD(n1, n2));
	return 0;
}
int GCD(int n1, int n2)
{
	if (n1%n2 == 0)
		return n2;
	if(n1>n2)
		return GCD(n2, n1%n2);
	else {
		if (n2%n1 == 0)
			return n1;
		else
			return GCD(n1, n2%n1);
	}
}