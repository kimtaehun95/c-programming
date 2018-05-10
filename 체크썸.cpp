#include<iostream>
#include<fstream>

using namespace std;
int facto(int n)
{
	if (n == 0) return 1;
	else  return 2 * facto(n - 1);
}
int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int test_case;
	int i, j;
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, checksum = 0, k = 0, sum = 0;
	unsigned int num;
	int bit[32] = { 0, };

	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> num;
		for (j = 0; j < 32; j++) {
			bit[j] = 0;
		}
		num1 = 0;
		num2 = 0;
		num3 = 0;
		num4 = 0;
		sum = 0;
		checksum = 0;
		k = 0;
		for (j = 0; j < 32; j++) {
			if (num % 2 != 0) {
				bit[j] = 1;
				num /= 2;
			}
			else { bit[j] = 0; num /= 2; }
		}
		for (j = 0; j < 8; j++) { num1 += facto(k)*bit[j]; k++; }
		k = 0;
		for (j = 8; j < 16; j++) { num2 += facto(k)*bit[j]; k++; }
		k = 0;
		for (j = 16; j < 24; j++) { num3 += facto(k)*bit[j]; k++; }
		k = 0;
		for (j = 24; j < 32; j++) { num4 += facto(k)*bit[j]; k++; }
		sum = num2 + num3 + num4;//실제데이터의합
		while (sum >= 256) { sum -= 256; };
		checksum = 255 - sum;
		if (checksum == num1) { cout << "1"; }
		else { cout << "0"; }
		cout << endl;
	}
	
	fp.close();
}