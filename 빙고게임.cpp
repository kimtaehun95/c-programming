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
		int bingo[5][5] = { 0, };
		int check[5][5] = { 0, };
		check[2][2] = 1;
		int j, k, ch = 0, l, m;
		int number[75] = { 0, }, chnum = 0, checknum = 0;
		int vucount = 0, vdcount = 0, hlcount = 0, hrcount = 0, rdcount = 0, lucount = 0, rucount = 0, ldcount = 0;
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				fp >> bingo[j][k];
			}
		}
		for (j = 0; j < 75; j++) {
			fp >> number[j];
		}
		while (ch < 75) {
			for (j = 0; j < 5; j++) {
				for (k = 0; k < 5; k++) {
					if (number[ch] == bingo[j][k]) { 
						check[j][k] = 1;
						for (l = j - 1; l >= 0; l--) { if (check[l][k] == 1) { vucount++; } else break; }
						for (l = j + 1; l <= 4; l++) { if (check[l][k] == 1) { vdcount++; } else break; }
						for (l = k - 1; l >= 0; l--) { if (check[j][l] == 1) { hlcount++; } else break; }
						for (l = k + 1; l <= 4; l++) { if (check[j][l] == 1) { hrcount++; } else break; }
						for (l = k - 1, m = j - 1; l >= 0 && m >= 0; l--, m--) { if (check[m][l] == 1) { lucount++; } else break; }
						for (l = k + 1, m = j - 1; l <= 4 && m >= 0; l++, m--) { if (check[m][l] == 1) { ldcount++; } else break; }
						for (l = k + 1, m = j + 1; l <= 4 && m <= 4; l++, m++) { if (check[m][l] == 1) { rdcount++; } else break; }
						for (l = k - 1, m = j + 1; l >= 0 && m <= 4; l--, m++) { if (check[m][l] == 1) { rucount++; } else break; }
						if (hlcount + hrcount == 4 || vucount + vdcount == 4 || rdcount + lucount == 4 || rucount + ldcount == 4) {
							chnum =ch; 
							checknum = 1; break;
						}
						else if ((j == 0 && k == 0)|| (j == 0 && k == 4)|| (j == 4 && k == 0)|| (j == 4 && k == 4)) {
							if (check[0][0] == 1 && check[0][4] == 1 && check[4][0] == 1 && check[4][4] == 1) { 
								chnum = ch;
								checknum = 1; break;
							}
						}
						vucount = 0; vdcount = 0; hlcount = 0; hrcount = 0; rdcount = 0; lucount = 0; rucount = 0; ldcount = 0;
					}
					if (checknum == 1)break;
				}
				if (checknum == 1)break;
			}
			if (checknum == 1)break;
			ch++;
		}
		cout << chnum+1 << endl;
	}
	fp.close();
	return 0;
}