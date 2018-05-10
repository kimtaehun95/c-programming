#include<iostream>
#include<fstream>

using namespace std;

int facto(int n) {
	if (n == 0) return 1;
	else return 2 * facto(n - 1);
}

int main(void)
{
	ifstream fp;
	fp.open("input.txt");

	int test_case = 0, number = 0, hamming_code = 0;
	int i;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> number>>hamming_code;
		int p = 0, p1 = 0, p2 = 0, p4 = 0, p8 = 0, p16 = 0, j, k=0, hammingnum = 0,num = 0;
		int p1_count = 0, p2_count = 0, p4_count = 0, p8_count = 0, p16_count = 0;
		int bin[32] = { 0, }, bino[32] = { 0, };
		int n1=0;
		if (number == 0) {
			
			for (j = 0; j < 32; j++) {
				if (j == 0 || j == 1 || j == 3 || j == 7 || j == 15 || j == 31) { bin[j] = p; }
				else { bin[j] = hamming_code % 2; hamming_code /= 2; }
			}
			for (j = 0; j < 32; j++) {
				if (j % 2 == 0) {
					if (bin[j] == 1) { p1_count++;  }	
				}
				
				else if (j == 1) {
					n1 = 3; k = 1;
					while (k < 32) {
						if (k == n1) { k+=2; n1 += 4; }
						else if (bin[k] == 1) { p2_count++;   k++; }
						else k++;
					}
				}
				else if (j == 3) {
					n1 = 7; k = 3;
					while (k < 32) {
						if (k == n1) { k += 4; n1 += 8; }
						else if (bin[k] == 1) { p4_count++; k++; }
						else k++;
					}
				}
				else if (j == 7) {
					n1 = 15; k = 7;
					while (k < 32) {
						if (k == n1) { k += 8; }
						else if (bin[k] == 1) { p8_count++; k++; }
						else k++;
					}
				}
				else if (j == 15) {
					k = 15;
					while (k < 32) {
						if (bin[k] == 1) { p16_count++; k++; }
						else k++;
					}
				}
			}
			p1 = p1_count % 2 == 0 ? 0 : 1;
			p2 = p2_count % 2 == 0 ? 0 : 1;
			p4 = p4_count % 2 == 0 ? 0 : 1;
			p8 = p8_count % 2 == 0 ? 0 : 1;
			p16 = p16_count % 2 == 0 ? 0 : 1;
			for (j = 0; j < 32; j++) {
				if (j == 0) { bin[j] = p1; }
				else if (j == 1) { bin[j] = p2; }
				else if (j == 3) { bin[j] = p4; }
				else if (j == 7) { bin[j] = p8; }
				else if (j == 15) { bin[j] = p16; }
			}
		
			for (j = 0; j < 32; j++) {
				hammingnum += bin[j] * facto(j);
				
			}
			cout << hammingnum << endl;
		
		}
		else if (number == 1) {
			for (j = 0; j < 32; j++) {//해밍코드
				bin[j] = hamming_code % 2; hamming_code /= 2;
			}
			
			for (j = 0; j < 32; j++) {
				if (j % 2 == 0) {
					if (bin[j] == 1) { p1_count++; }
				}

				else if (j == 1) {
					n1 = 3; k = 1;
					while (k < 32) {
						if (k == n1) { k+=2; n1 += 4; }
						else if (bin[k] == 1) { p2_count++;   k++; }
						else k++;
					}
				}
				else if (j == 3) {
					n1 = 7; k = 3;
					while (k < 32) {
						if (k == n1) { k += 4; n1 += 8; }
						else if (bin[k] == 1) { p4_count++;  k++; }
						else k++;
					}
				}
				else if (j == 7) {
					n1 = 15; k = 7;
					while (k < 32) {
						if (k == n1) { k += 8; }
						else if (bin[k] == 1) { p8_count++; k++; }
						else k++;
					}
				}
				else if (j == 15) {
					k = 15;
					while (k < 32) {
						if (bin[k] == 1) { p16_count++; k++; }
						else k++;
					}
				}
			}
			p1 = p1_count % 2 == 0 ? 0 : 1;
			p2 = p2_count % 2 == 0 ? 0 : 1;
			p4 = p4_count % 2 == 0 ? 0 : 1;
			p8 = p8_count % 2 == 0 ? 0 : 1;
			p16 = p16_count % 2 == 0 ? 0 : 1;
			if (p1 == 1) { num += 1; }
			if (p2 == 1) { num += 2; }
			if (p4 == 1) { num += 4; }
			if (p8 == 1) { num += 8; }
			if (p16 == 1) { num += 16; }
			if (num != 0) { bin[num - 1] = 1; }
			j = 0;
			k = 0;
			while (j<32) {//해밍코드를 실제데이터로
				if (j == 0 || j == 1 || j == 3 || j == 7 || j == 15 || j == 31) { j++; }
				else { bino[k] = bin[j]; k++; j++; }
			}

			for (j = 0; j < 32; j++) {
				hammingnum += bino[j] * facto(j);
			
			}
			
			cout<<hammingnum << endl;
		}
	}
	fp.close();
	return 0;
}