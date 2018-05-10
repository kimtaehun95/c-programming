#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");

	int test_case;
	int i;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		int row, col, g, gold=0;
		char lg[100][100] = { 0, };
		char newlg[100][100] = { 0, };
		int j, k, celcount = 0, gcelcount = 0;
		fp >> row >> col >> g;
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				fp >> lg[j][k];
				newlg[j][k] = lg[j][k];
			}
		}
		while (gold != g) {
			for (j = 0; j < row; j++) {
				for (k = 0; k < col; k++) {
					if (j == 0 && k == 0) {
						if (lg[j][k + 1] == 'O')celcount++;
						if (lg[j + 1][k + 1] == 'O')celcount++;
						if (lg[j + 1][k] == 'O')celcount++;
					}
					else if (j == 0 && k == col - 1) {
						if (lg[j][k - 1] == 'O')celcount++;
						if (lg[j + 1][k - 1] == 'O')celcount++;
						if (lg[j + 1][k] == 'O')celcount++;
					}
					else if (j == row - 1 && k == 0) {
						if (lg[j][k + 1] == 'O')celcount++;
						if (lg[j - 1][k + 1] == 'O')celcount++;
						if (lg[j - 1][k] == 'O')celcount++;
					}
					else if (j == row - 1 && k == col - 1) {
						if (lg[j][k - 1] == 'O')celcount++;
						if (lg[j - 1][k - 1] == 'O')celcount++;
						if (lg[j - 1][k] == 'O')celcount++;
					}
					else if (j == 0 && (k != col - 1 || k != 0)) {
						if (lg[j][k + 1] == 'O')celcount++;
						if (lg[j + 1][k + 1] == 'O')celcount++;
						if (lg[j + 1][k] == 'O')celcount++;
						if (lg[j + 1][k - 1] == 'O')celcount++;
						if (lg[j][k - 1] == 'O')celcount++;
					}
					else if (j == row - 1 && (k != col - 1 || k != 0)) {
						if (lg[j][k - 1] == 'O')celcount++;
						if (lg[j - 1][k - 1] == 'O')celcount++;
						if (lg[j - 1][k] == 'O')celcount++;
						if (lg[j - 1][k + 1] == 'O')celcount++;
						if (lg[j][k + 1] == 'O')celcount++;
					}
					else if (k == 0 && (j != row - 1 || j != 0)) {
						if (lg[j][k + 1] == 'O')celcount++;
						if (lg[j + 1][k + 1] == 'O')celcount++;
						if (lg[j + 1][k] == 'O')celcount++;
						if (lg[j - 1][k] == 'O')celcount++;
						if (lg[j - 1][k + 1] == 'O')celcount++;
					}
					else if (k == col - 1 && (j != row - 1 || j != 0)) {
						if (lg[j + 1][k] == 'O')celcount++;
						if (lg[j + 1][k - 1] == 'O')celcount++;
						if (lg[j][k - 1] == 'O')celcount++;
						if (lg[j - 1][k - 1] == 'O')celcount++;
						if (lg[j - 1][k] == 'O')celcount++;
					}
					else {
						if (lg[j][k + 1] == 'O')celcount++;
						if (lg[j + 1][k + 1] == 'O')celcount++;
						if (lg[j + 1][k] == 'O')celcount++;
						if (lg[j + 1][k - 1] == 'O')celcount++;
						if (lg[j][k - 1] == 'O')celcount++;
						if (lg[j - 1][k - 1] == 'O')celcount++;
						if (lg[j - 1][k] == 'O')celcount++;
						if (lg[j - 1][k + 1] == 'O')celcount++;
					}
					if (lg[j][k] == 'O') {
						if (celcount <= 1)newlg[j][k] = 'X';
						else if (celcount == 2 || celcount == 3)newlg[j][k] = 'O';
						else if (celcount >= 4)newlg[j][k] = 'X';
					}
					else if (lg[j][k] == 'X') {
						if (celcount == 3)newlg[j][k] = 'O';
						else newlg[j][k] = 'X';
					}
					celcount = 0;
				}
			}
			for (j = 0; j < row; j++) {
				for (k = 0; k < col; k++) {
					lg[j][k] = newlg[j][k];
				}
			}
			gold++;
		}
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				if (newlg[j][k] == 'O') gcelcount++;
			}
		}
		cout << gcelcount << endl;
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				cout << newlg[j][k];
			}
			cout << endl;
		}
	}
	fp.close();
	return 0;
}