#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int t=0;
	int Y=0,M=0,D=0;
	int i, j;
	int op=0;
	fp >> t;
	for (i = 0; i < t; i++) {
		fp >> Y >> M >> D;
		op = 0;
		
		for (j = 1582; j < Y; j++) {
			if ((j % 4 == 0 && j % 100 != 0) || j % 400 == 0) {
				D += 366;
			}
			else {
				D += 365;
			}
		}
		for (j = 1; j < M; j++) {
			if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12) {
				D += 31;
			}
			else if (j == 2) {
				if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0) {
					D += 29;
				}
				else {
					D += 28;
				}
			}
			else {
				D += 30;
			}
		}
		
		op = D % 7;
		if (op == 1) {
			cout << "5" << endl;
		}
		else if (op == 2) {
			cout << "6" << endl;
		}
		else if (op == 3) {
			cout << "0" << endl;
		}
		else if (op == 4) {
			cout << "1" << endl;
		}
		else if (op == 5) {
			cout << "2" << endl;
		}
		else if (op == 6) {
			cout << "3" << endl;
		}
		else if (op == 0) {
			cout << "4" << endl;
		}
		
	}

	fp.close();
}