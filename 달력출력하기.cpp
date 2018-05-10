#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int i;
	int test_case = 0, y = 0, m = 0;
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31,30,31,30,31 };
	int firstday = 0;
	int day=1;
	int D = 1;
	int j,k;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> y >> m;
		D = 1;
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
			arr[1] = 29;
		}
		else {
			arr[1] = 28;
		}
		for (j = 1582; j < y; j++) {
			if ((j % 4 == 0 && j % 100 != 0) || j % 400 == 0) {
				D += 366;
			}
			else {
				D += 365;
			}
		}
		for (j = 1; j < m; j++) {
			if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12) {
				D += 31;
			}
			else if (j == 2) {
				if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
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
		D = D % 7;
		if (D == 1) {
			firstday=5;
		}
		else if (D == 2) {
			firstday = 6;
		}
		else if (D == 3) {
			firstday = 0;
		}
		else if (D == 4) {
			firstday = 1;
		}
		else if (D == 5) {
			firstday = 2;
		}
		else if (D == 6) {
			firstday = 3;
		}
		else if (D == 0) {
			firstday = 4;
		}
		cout << y <<" "<<m<<" "<< endl;
		for (j = 0; j < firstday; j++) {
			cout << "0" << " ";
		}
		for (k = 1; k <= arr[m - 1]; k++) {
			cout << k << " ";
			firstday++;
			if (firstday == 7) {
				firstday = 0;
				cout << "\n";
			}
		}
		if (firstday != 0) {
			while (firstday != 7) {
				cout << "0" << " ";
				firstday++;
			}
			cout << endl;
		}
		
		
	}
	fp.close();
}