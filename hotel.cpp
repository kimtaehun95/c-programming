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
		int row, col, num, count = 0,c=0;
		int hotelnum[99][99] = { 0, };
		fp >> row >> col >> num;
		int j, k;
		for (j = 0; j < col; j++) {
			for (k = 0; k < row; k++) {
				count++;
				if (count == num) {
					hotelnum[j][k] = (k+1) * 100 + (j+1);
					cout << hotelnum[j][k] << endl;
					c = 1; break;
				}
			}
			if (c == 1)break;
		}
		

	}
	
}