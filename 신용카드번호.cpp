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
		string s = "";
		int j, checksum = 0, rechecksum = 0;
		int sum1 = 0, sum2 = 0, sum3 = 0;
		fp >> s;
		if (s[0] != '3' && s[0] != '4' && s[0] != '5' && s[0] != '6') { cout << 0 << endl; }
		else if (s[0] == '3'&&(s.length()==15||s.length()==14)) { 
			if (s.length() == 15) {
				checksum = s[14]-48;
				for (j = 13; j >= 0; j--) {
					if (j % 2 == 1) {
						if (2 * (s[j] - 48) >= 10) {
							sum1 += 2 * (s[j] - 48) - 9;
						}
						else if (2 * (s[j] - 48) < 10) {
							sum1 += 2 * (s[j] - 48);
						}
					}
					else if (j % 2 == 0) {
						sum2 += s[j] - 48;
					}
				}
				sum3 = sum1 + sum2;
				rechecksum = (sum3 + checksum) % 10;
				if (rechecksum == 0) {
					cout << 1 << endl;
				}
				else cout << 0 << endl;
			}
			else if (s.length() == 14) {
				checksum = s[13]-48;
				for (j = 12; j >= 0; j--) {
					if (j % 2 == 0) {
						if (2 * (s[j] - 48) >= 10) {
							sum1 += 2 * (s[j] - 48) - 9;
						}
						else if (2 * (s[j] - 48) < 10) {
							sum1 += 2 * (s[j] - 48);
						}
					}
					else if (j % 2 == 1) {
						sum2 += s[j] - 48;
					}
				}
				sum3 = sum1 + sum2;
				rechecksum = (sum3 + checksum) % 10;
				if (rechecksum == 0) {
					cout << 1 << endl;
				}
				else cout << 0 << endl;
			}
		}
		else if ((s[0] == '5'||s[0] == '6') && s.length() == 16) {
			if (s[0]=='5') {
				checksum = s[15] - 48;
				for (j = 14; j >= 0; j--) {
					if (j % 2 == 0) {
						if (2 * (s[j] - 48) >= 10) {
							sum1 += 2 * (s[j] - 48) - 9;
						}
						else if (2 * (s[j] - 48) < 10) {
							sum1 += 2 * (s[j] - 48);
						}
					}
					else if (j % 2 == 1) {
						sum2 += s[j] - 48;
					}
				}
				sum3 = sum1 + sum2;
				rechecksum = (sum3 + checksum) % 10;
				if (rechecksum == 0) {
					cout << 1 << endl;
				}
				else cout << 0 << endl;
			}
			else if (s[0]=='6') {
				checksum = s[15] - 48;
				for (j = 14; j >= 0; j--) {
					if (j % 2 == 0) {
						if (2 * (s[j] - 48) >= 10) {
							sum1 += 2 * (s[j] - 48) - 9;
						}
						else if (2 * (s[j] - 48) < 10) {
							sum1 += 2 * (s[j] - 48);
						}
					}
					else if (j % 2 == 1) {
						sum2 += s[j] - 48;
					}
				}
				sum3 = sum1 + sum2;
				rechecksum = (sum3 + checksum) % 10;
				if (rechecksum == 0) {
					cout << 1 << endl;
				}
				else cout << 0 << endl;
			}
		}
		else if (s[0] == '4' && (s.length() == 13 || s.length() == 16)) {
			if (s.length() == 13) {
				checksum = s[12] - 48;
				for (j = 11; j >= 0; j--) {
					if (j % 2 == 1) {
						if (2 * (s[j] - 48) >= 10) {
							sum1 += 2 * (s[j] - 48) - 9;
						}
						else if (2 * (s[j] - 48) < 10) {
							sum1 += 2 * (s[j] - 48);
						}
					}
					else if (j % 2 == 0) {
						sum2 += s[j] - 48;
					}
				}
				sum3 = sum1 + sum2;
				rechecksum = (sum3 + checksum) % 10;
				if (rechecksum == 0) {
					cout << 1 << endl;
				}
				else cout << 0 << endl;
			}
			else if (s.length() == 16) {
				checksum = s[15] - 48;
				for (j = 14; j >= 0; j--) {
					if (j % 2 == 0) {
						if (2 * (s[j] - 48) >= 10) {
							sum1 += 2 * (s[j] - 48) - 9;
						}
						else if (2 * (s[j] - 48) < 10) {
							sum1 += 2 * (s[j] - 48);
						}
					}
					else if (j % 2 == 1) {
						sum2 += s[j] - 48;
					}
				}
				sum3 = sum1 + sum2;
				rechecksum = (sum3 + checksum) % 10;
				if (rechecksum == 0) {
					cout << 1 << endl;
				}
				else cout << 0 << endl;
			}
		}
		else cout << 0 << endl;
	}
	fp.close();
	return 0;
}