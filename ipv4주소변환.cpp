#include<iostream>
#include<fstream>
#include<string>

using namespace std;
long long facto(long long n) {
	if (n == 0)return 1;
	else return 2 * facto(n - 1);
}
int main(void)
{
	ifstream fp;
	fp.open("input.txt");

	int test_case = 0;
	int i;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		string s = "", s1 = "", s2 = "", s3 = "", s4 = "";
		int num1=0, num2=0, num3=0, num4=0;
		long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		long long Num1[8] = { 0, }, Num2[8] = { 0, }, Num3[8] = { 0, }, Num4[8] = { 0, };
		int Num5[32] = { 0, };
		int num = 0, j, count = 0, pcount[3] = { 0, };
		fp >> num;
		if (num == 1) {
			fp >> s;
			int len = s.length();
			for (j = 0; j < len; j++) {
				if (s[j] == '.') { 
					count++;
					if (count == 1) { pcount[0] = j; }
					if (count == 2) { pcount[1] = j; }
					if (count == 3) { pcount[2] = j; }
				}
			}
			s1 = s.substr(0, pcount[0]);
			s2 = s.substr(pcount[0]+1, pcount[1]-pcount[0]-1);
			s3 = s.substr(pcount[1]+1, pcount[2]-pcount[1]-1);
			s4 = s.substr(pcount[2]+1, len - pcount[2] - 1);
			if (s1.length() == 1) { num1 = s1[0] - 48; }
			if (s2.length() == 1) { num2 = s2[0] - 48; }
			if (s3.length() == 1) { num3 = s3[0] - 48; }
			if (s4.length() == 1) { num4 = s4[0] - 48; }
			if (s1.length() == 2) { num1 = (s1[0] - 48) * 10 + (s1[1] - 48); }
			if (s2.length() == 2) { num2 = (s2[0] - 48) * 10 + (s2[1] - 48); }
			if (s3.length() == 2) { num3 = (s3[0] - 48) * 10 + (s3[1] - 48); }
			if (s4.length() == 2) { num4 = (s4[0] - 48) * 10 + (s4[1] - 48); }
			if (s1.length() == 3) { num1 = (s1[0] - 48) * 100 + (s1[1] - 48) * 10 + (s1[2] - 48); }
			if (s2.length() == 3) { num2 = (s2[0] - 48) * 100 + (s2[1] - 48) * 10 + (s2[2] - 48); }
			if (s3.length() == 3) { num3 = (s3[0] - 48) * 100 + (s3[1] - 48) * 10 + (s3[2] - 48); }
			if (s4.length() == 3) { num4 = (s4[0] - 48) * 100 + (s4[1] - 48) * 10 + (s4[2] - 48); }
			for (j = 0; j < 8; j++) {
				Num1[j] = num1 % 2;
				num1 /= 2;
				sum1 += Num1[j] * facto(j + 24);
			}
			
			for (j = 0; j < 8; j++) {
				Num2[j] = num2 % 2;
				num2 /= 2;
				sum2 += Num2[j] * facto(j + 16);
			}
			
			for (j = 0; j < 8; j++) {
				Num3[j] = num3 % 2;
				num3 /= 2;
				sum3 += Num3[j] * facto(j + 8);
			}
			
			for (j = 0; j < 8; j++) {
				Num4[j] = num4 % 2;
				num4 /= 2;
				sum4 += Num4[j] * facto(j);
			}
			sum5 = sum1 + sum2 + sum3 + sum4;
			cout << sum5 << endl;
		}
		else if (num == 2) {
			fp >> sum5;
			for (j = 0; j < 32; j++) {
				Num5[j] = sum5 % 2;
				sum5 /= 2;
			}
			for (j = 0; j < 8; j++) {
				sum4 += Num5[j] * facto(j);
			}
			for (j = 8; j < 16; j++) {
				sum3 += Num5[j] * facto(j-8);
			}
			for (j = 16; j < 24; j++) {
				sum2 += Num5[j] * facto(j-16);
			}
			for (j = 24; j < 32; j++) {
				sum1 += Num5[j] * facto(j-24);
			}
			cout << sum1 << "." << sum2 << "." << sum3 << "." << sum4  << endl;
		}
	}
	fp.close();
	return 0;
}
