#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int i,j,k;
	int t = 0, n = 0;

	fp >> t;
	for (i = 0; i < t; i++)
	{
		fp >> n;
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (j==(n/2)&&j == k) {
					cout << "O";
				}
				else if (j == (n / 2) && j != k) {
					cout << "+";
				}
				else if (k == (n / 2) && j != k) {
					cout << "I";
				}
				else if (j == -k + (n - 1) && j != k) {
					cout << "*";
				}
				else {
					cout << ".";
				}
			}
			cout << endl;
		}
	}

}