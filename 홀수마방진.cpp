#include <iostream>

using namespace std;
#define MAX_SIZE 19
void magic(int n)
{
	int square[MAX_SIZE][MAX_SIZE], k, l;

	if ((n % 2 == 0) || (n < 0)) {
		cout << "잘못입력함" << endl;
		return;
	}
	for (k = 0; k < n; k++) {
		for (l = 0; l < n; l++) {
			square[k][l] = 0;
		}
	}

	square[0][(n - 1) / 2] = 1;// 첫 행의 중간값을 1로 만듬

	int key = 2;//마방진에 들어갈 값
				//현재 위치
	int i = 0;
	int j = (n - 1) / 2;

	while (key <= n*n) {
		//왼쪽 대각선으로의 이동
		if (i - 1 < 0)
			k = n - 1;//행을 벗어났을 경우 가장 아래의 행으로 이동
		else
			k = i - 1;//행이 벗어나지 않았다면 대각선 위쪽으로 이동
		if (j - 1 < 0)
			l = n - 1;//열을 벗어났을 경우 가장 끝(오른쪽)의 열로 이동
		else
			l = j - 1;//열이 벗어나지 않았다면 대각선 위쪽으로 이동
		if (square[k][l])
			i = (i + 1);//대각선 위쪽에 숫자가 있다면 아래로 이동
		else {//숫자가 없다면 그곳으로 이동
			i = k;
			j = l;
		}

		square[i][j] = key;
		key++;
	}
	//마방진 출력
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

	


