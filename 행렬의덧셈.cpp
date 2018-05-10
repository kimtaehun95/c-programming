#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int i, j, k;
	int test_case=0;
	int row = 0, col = 0;
	int a[100][100] = { 0, };
	int b[100][100] = { 0, };
	int c[100][100] = { 0, };
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> row >> col;
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				fp >> a[j][k];
			}
		}

		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				fp >> b[j][k];
			}
		}
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				c[j][k] = a[j][k] + b[j][k];
				cout << c[j][k]<<" ";
			}
			cout << endl;
		}

	}

	fp.close();
}
