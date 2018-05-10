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
		string s = "", s1 = "", s2 = "", s3 = "", s4 = "";
		fp >> s;
		int len = s.length(), acount = 0, wcount = 0;
		int j, k = 0,l;
		string alpa[26] = { ".-", "-..." ,"-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		while (s.length() > 0) {
			j = s.find("#");
			if (j < 0) {//#이 존재하지않을때
				s1 = s;
				while (s1.length() > 0) {
					k = s1.find("|");
					if (k < 0) {
						for (l = 0; l < 26; l++) {
							if (s1 == alpa[l]) {
								char word[2] = { l + 65,'\0' };
								s4.append(&word[0]);
							}
						}
						s1.clear();
					}
					else if (k == 0) {
						s1.erase(0, 1);
					}
					else {
						s2 = s1.substr(0, k);
						for (l = 0; l < 26; l++) {
							if (s2 == alpa[l]) {
								char word[2] = { l + 65,'\0' };
								s4.append(&word[0]);
							}
						}
						s1.erase(0, k);
					}
				}
				s.clear();
			}
			else if (j == 0) {//#이 맨앞에있을때
				s.erase(0, 1);
				s4.append("_");
			}
			else {//#이가운데있을때
				s2 = s.substr(0, j);
				while (s2.length() > 0) {
					k = s2.find("|");
					if (k < 0) {
						for (l = 0; l < 26; l++) {
							if (s2 == alpa[l]) {
								char word[2] = { l + 65,'\0' };
								s4.append(&word[0]);
							}
						}
						s2.clear();
					}
					else if (k == 0) {
						s2.erase(0, 1);
					}
					else {
						s3 = s2.substr(0, k);
						for (l = 0; l < 26; l++) {
							if (s3 == alpa[l]) {
								char word[2] = { l + 65,'\0' };
								s4.append(&word[0]);
							}
						}
						s2.erase(0, k);
					}
				}
				s.erase(0, j);
			}
		}
		cout << s4 << endl;
	}
	fp.close();
	return 0;
}