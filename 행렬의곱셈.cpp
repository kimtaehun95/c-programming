#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int i, j, k, l;
	int test_case = 0;
	int r = 0, s = 0, t = 0;
	int a[100][100] = { 0, };
	int b[100][100] = { 0, };
	int c[100][100] = { 0, };
	int sum = 0;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> r >> s >> t;
		for (j = 0; j < r; j++) {
			for (k = 0; k < s; k++) {
				fp >> a[j][k];
			}
		}

		for (j = 0; j < s; j++) {
			for (k = 0; k < t; k++) {
				fp >> b[j][k];
			}
		}
		for (j = 0; j < r; j++) {
			for (k = 0; k < t; k++) {
				for (l = 0; l < s; l++) {
					sum += a[j][l] * b[l][k];
				}
				c[j][k] = sum;
				sum = 0;
				cout << c[j][k] << " ";
			}
			cout << endl;
		}

	}

	fp.close();
}