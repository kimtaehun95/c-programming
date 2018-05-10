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
		int connectfour[6][7] = { 0, };
		int j, k, l, c;
		int number[42] = { 0, }, snumber, rownumber = 6;
		int hlcount = 0, hrcount = 0, vucount = 0, vdcount = 0, lucount = 0, ldcount = 0, rucount = 0, rdcount = 0;
		for (j = 0; j < 6; j++) {
			for (k = 0; k < 7; k++) {
				connectfour[j][k] = 0;
			}
		}
		fp >> snumber;
		for (j = 0; j < snumber; j++) {
			fp >> number[j];
			if (j % 2 == 0) {
				while (rownumber > 0) {
					if (connectfour[rownumber - 1][number[j] - 1] == 0){
						c = rownumber;
						connectfour[rownumber-1][number[j] - 1] = 1; break;
					}
					else { rownumber--; }
				}
				rownumber = 6;
			}
			else if (j % 2 == 1) {
				while (rownumber > 0) {
					if (connectfour[rownumber-1][number[j] - 1] == 0) {
						c = rownumber;
						connectfour[rownumber-1][number[j] - 1] = 2; break;
					}
					else { rownumber--; }
				}
				rownumber = 6;
			}
		}
		for (k = number[j - 1] - 2; k >= 0; k--) { if (connectfour[c - 1][k] == connectfour[c - 1][number[j - 1] - 1]) { hlcount++; } else break; }
		for (k = number[j - 1] ; k <= 6; k++) { if (connectfour[c - 1][k] == connectfour[c - 1][number[j - 1] - 1]) { hrcount++; } else break; }
		for (k = c - 2; k >= 0; k--) { if (connectfour[k][number[j - 1] - 1] == connectfour[c - 1][number[j - 1] - 1]) { vucount++; }else break; }
		for (k = c; k <= 5; k++) { if (connectfour[k][number[j - 1] - 1] == connectfour[c - 1][number[j - 1] - 1]) { vdcount++; } else break; }
		for (k = c - 2,l= number[j - 1] - 2; k >= 0&&l>=0; k--,l--) { if (connectfour[k][l] == connectfour[c - 1][number[j - 1] - 1]) { lucount++; } else break; }
		for (k = c, l = number[j - 1] - 2; k <= 5 && l >= 0; k++, l--) { if (connectfour[k][l] == connectfour[c - 1][number[j - 1] - 1]) { ldcount++; } else break; }
		for (k = c,l= number[j - 1]; k <= 5&&l<=6; k++,l++) { if (connectfour[k][l] == connectfour[c - 1][number[j - 1] - 1]) { rdcount++; } else break; }
		for (k = c-2, l = number[j - 1]; k >= 0 && l <= 6; k--, l++) { if (connectfour[k][l] == connectfour[c - 1][number[j - 1] - 1]) { rucount++; } else break; }
		if (hlcount+hrcount >= 3 || vucount + vdcount >= 3 || rdcount + lucount >= 3 || rucount + ldcount >= 3)
			cout << connectfour[c - 1][number[j - 1] - 1] << endl;
		else 
			cout << 0 << endl;
	}
	fp.close();
	return 0;
}