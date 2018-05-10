#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");

	int test_case = 0;
	int i;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		string s = "", s1 = "", s2 = "", s3 = "", s4 = "", checksum = "";
		fp >> s;
		int j, len = s.length(), k[3] = { 0, }, num[9] = { 0, };
		int bar_count = 0, count = 0, sum = 0, csnumber = 10, e = 0, number = 0;
		for (j = 0; j < len; j++) {
			if (s[j] == '-') {
				bar_count++;
				if (bar_count == 1) { k[0] = j; }
				if (bar_count == 2) { k[1] = j; }
				if (bar_count == 3) { k[2] = j; }
			}
		}
		s1 = s.substr(0, k[0]);
		s2 = s.substr(k[0] + 1, k[1] - k[0] - 1);
		s3 = s.substr(k[1] + 1, k[2] - k[1] - 1);
		s4 = s.substr(k[2] + 1, len - k[2] - 1);
		for (j = 0; j < s1.length(); j++) { if (!isdigit(s1[j]))count++; }
		for (j = 0; j < s2.length(); j++) { if (!isdigit(s2[j]))count++; }
		for (j = 0; j < s3.length(); j++) { if (!isdigit(s3[j]))count++; }
		for (j = 0; j < s4.length(); j++) { if (!isdigit(s4[j])&&s4[j]!='X')count++; }
		if(len!=13) { cout << 0 << endl; }//숫자는 10자리가 되야됨
		else if (bar_count != 3) { cout << 0 << endl; }
		else if (count != 0) { cout << 0 << endl; }
		else if (s1.length() == 0 || s2.length() == 0 || s3.length() == 0 || s4.length() == 0) {
			cout << 0 << endl;
		}
		else if (s1.length() > 5 || s2.length() > 7 || s3.length() > 6 || s4.length() > 1) {
			cout << 0 << endl;
		}
		else if (s4[0] == 'X' || isdigit(s4[0]) ) {
			checksum = s1 + s2 + s3 + s4;
			checksum = checksum.substr(0, 9);
			for (j = 0; j < 9; j++) {
				num[j] = checksum[j]-48;
				num[j] = num[j] * csnumber;
				csnumber--;
				sum += num[j];
			}
			while (e < sum) {
				e += 11;
			}
			number = e - sum;
			if (number == 10 && s4[0] == 'X') { cout << 1 << endl; }
			else if(number >=0 &&number<=9) { 
				number += 48;
				if (number == s4[0]) { cout << 1 << endl; }
				else cout << 0 << endl;
			}
		}
		else cout << 1 << endl;
	}
	fp.close();
	return 0;
}