#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int test_case;
	int i;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		int row, col, j, k, num, l, m, r, c;
		fp >> row >> col;
		char puzzle[100][100] = { "", };
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				fp >> puzzle[j][k];
			}
		}
		fp >> num;
		for (j = 0; j < num; j++) {
			string oword ="", checkword = "";
			fp >> oword;
			int noncheck = 0,vucheck = 8, vdcheck = 8, lucheck = 8, rucheck = 8, hrcheck = 8, hlcheck = 8, ldcheck = 8, rdcheck = 8;
			for (l = 0; l < row; l++) {
				for (m = 0; m < col; m++) {
					if (oword[0] == puzzle[l][m]) {
						for (c = m; c <= col; c++) { checkword += puzzle[l][c]; if (oword == checkword) { hrcheck = 2; break; } }
						if (hrcheck == 2) { cout << l + 1 << " " << m + 1 << " " << 2 << endl; break; }
						checkword = "";
						for (c = m; c >= 0; c--) { checkword += puzzle[l][c]; if (oword == checkword) { hlcheck = 6; break; } }
						if (hlcheck == 6) { cout << l + 1 << " " << m + 1 << " " << 6 << endl; break; }
						checkword = "";
						for (r = l; r <= row; r++) { checkword += puzzle[r][m]; if (oword == checkword) { vdcheck = 4; break; } }
						if (vdcheck == 4) { cout << l + 1 << " " << m + 1 << " " << 4 << endl; break; }
						checkword = "";
						for (r = l; r >= 0; r--) { checkword += puzzle[r][m]; if (oword == checkword) { vucheck = 0; break; } }
						if (vucheck == 0) { cout << l + 1 << " " << m + 1 << " " << 0 << endl; break; }
						checkword = "";
						for (r = l, c = m; r <= row, c >= 0; r++, c--) { checkword += puzzle[r][c]; if (oword == checkword) { ldcheck = 5; break; } }
						if (ldcheck == 5) { cout << l + 1 << " " << m + 1 << " " << 5 << endl; break; }
						checkword = "";
						for (r = l, c = m; r <= row, c <= col; r++, c++) { checkword += puzzle[r][c]; if (oword == checkword) { rdcheck = 3; break; } }
						if (rdcheck == 3) { cout << l + 1 << " " << m + 1 << " " << 3 << endl; break; }
						checkword = "";
						for (r = l, c = m; r >= 0, c <= col; r--, c++) { checkword += puzzle[r][c]; if (oword == checkword) { rucheck = 1; break; } }
						if (rucheck == 1) { cout << l + 1 << " " << m + 1 << " " << 1 << endl; break; }
						checkword = "";
						for (r = l, c = m; r >= 0, c >= 0; r--, c--) { checkword += puzzle[r][c]; if (oword == checkword) { lucheck = 7; break; } }
						if (lucheck == 7) { cout << l + 1 << " " << m + 1 << " " << 7 << endl; break; }
						checkword = "";
					}
				}
				if (vucheck == 0)break;
				if (rucheck == 1)break;
				if (hrcheck == 2)break;
				if (rdcheck == 3)break;
				if (vdcheck == 4)break;
				if (ldcheck == 5)break;
				if (hlcheck == 6)break;
				if (lucheck == 7)break;
			}
			if (hrcheck != 2 && hlcheck != 6 && vdcheck != 4 && vucheck != 0 && ldcheck != 5 && rdcheck != 3 && rucheck != 1 && lucheck != 7) {
				cout << -1 << endl;
			}
		}
	}
	fp.close();
	return 0;
}