#include<stdio.h>
int count = 0;
void hanoi(int, char, char, char);

int main()
{
	int n;
	printf("�ϳ���ž�� ������ ���� = ");
	scanf_s("%d", &n);

	hanoi(n, 'A', 'C', 'B');

	printf("�ű� Ƚ�� = %d\n", count);
	return 0;

}
void hanoi(int n, char from, char to, char aux)
{
	
	if (n == 1)
		printf("1���� ������ %c���� %c�� �ű��.\n", from, to);
	else {
		hanoi(n - 1, from, aux, to);
		printf("%d���� ������ %c���� %c�� �ű��.\n", n, from, to);
		hanoi(n - 1, aux, to, from);
	}
	count++;
	
}