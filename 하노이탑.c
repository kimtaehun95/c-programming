#include<stdio.h>
int count = 0;
void hanoi(int, char, char, char);

int main()
{
	int n;
	printf("하노이탑의 원반의 개수 = ");
	scanf_s("%d", &n);

	hanoi(n, 'A', 'C', 'B');

	printf("옮긴 횟수 = %d\n", count);
	return 0;

}
void hanoi(int n, char from, char to, char aux)
{
	
	if (n == 1)
		printf("1개의 원반을 %c에서 %c로 옮긴다.\n", from, to);
	else {
		hanoi(n - 1, from, aux, to);
		printf("%d개의 원반을 %c에서 %c로 옮긴다.\n", n, from, to);
		hanoi(n - 1, aux, to, from);
	}
	count++;
	
}