#include <iostream>

using namespace std;
#define MAX_SIZE 19
void magic(int n)
{
	int square[MAX_SIZE][MAX_SIZE], k, l;

	if ((n % 2 == 0) || (n < 0)) {
		cout << "�߸��Է���" << endl;
		return;
	}
	for (k = 0; k < n; k++) {
		for (l = 0; l < n; l++) {
			square[k][l] = 0;
		}
	}

	square[0][(n - 1) / 2] = 1;// ù ���� �߰����� 1�� ����

	int key = 2;//�������� �� ��
				//���� ��ġ
	int i = 0;
	int j = (n - 1) / 2;

	while (key <= n*n) {
		//���� �밢�������� �̵�
		if (i - 1 < 0)
			k = n - 1;//���� ����� ��� ���� �Ʒ��� ������ �̵�
		else
			k = i - 1;//���� ����� �ʾҴٸ� �밢�� �������� �̵�
		if (j - 1 < 0)
			l = n - 1;//���� ����� ��� ���� ��(������)�� ���� �̵�
		else
			l = j - 1;//���� ����� �ʾҴٸ� �밢�� �������� �̵�
		if (square[k][l])
			i = (i + 1);//�밢�� ���ʿ� ���ڰ� �ִٸ� �Ʒ��� �̵�
		else {//���ڰ� ���ٸ� �װ����� �̵�
			i = k;
			j = l;
		}

		square[i][j] = key;
		key++;
	}
	//������ ���
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << square[i][j] << " ";
		}
		cout << endl;
	}
}
int main(void)
{
	int n = 0;
	cin >> n;

	magic(n);

	return 0;
}

	


