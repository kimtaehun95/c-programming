#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int test_case = 0;
	int i, j, k;
	int key = 0;
	int len = 0, alphacount = 0;
	int count[26] = { 0, };
	double kai = 0, min = 0;
	double alphapercent[26] = { '\0', }, kaisquare[26] = {'\0',}, alpha[26] = { 8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074 };
	char alphaupper[26] = { '\0', }, alphalower[26] = { '\0', };
	string s = "";
	string s1 = "";
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> s;
		key = 0;
		s1 = "";
		len = s.length();
		alphacount = 0;
		kai = 0;
		min = 0;
		for (j = 0; j < 26; j++) {
			count[j] = 0;
			alphapercent[j] = 0;
			kaisquare[j] = 0;
		}
		for (j = 1; j < 26; j++) { alphaupper[0] = 65; alphaupper[j] = alphaupper[j - 1] + 1; }
		for (j = 1; j < 26; j++) { alphalower[0] = 97; alphalower[j] = alphalower[j - 1] + 1; }
		for (j = 0; j < len; j++) {
			if (isalpha(s[j])) {
				alphacount++;
				for (k = 0; k < 26; k++) {
					if (s[j] == alphaupper[k] || s[j] == alphalower[k]) { 
						count[k] += 1; 
					}//문장각각의알파벳의빈도수
				}
			}
		}
		
		for (j = 0; j < 26; j++) {
			alphapercent[j] = ((double)count[j] / (double)alphacount) * 100;
		}//암호문에서나타나는알파벳의빈도백분율
		for (j = 0; j < 26; j++) {
			for (k = 0; k < 26; k++) {
				kai += ((alphapercent[(k + j) % 26])*(alphapercent[(k + j) % 26])) / alpha[k];
			}
			kaisquare[j] = kai;
			kai = 0;
		}//각각의key값에해당하는 카이제곱값
		min = kaisquare[0];
		for (j = 0; j < 26; j++) {
			min = min < kaisquare[j] ? min : kaisquare[j];
		}
		k = 0;
		for (j = 0; j < 26; j++) {
			if (min == kaisquare[j]) { 
				key = j;
				break;
			}
		}
		
		for (j = 0; j < len; j++) {
			if (isupper(s[j]))
				s[j] = (((s[j] - 65) + (26 - key)) % 26) + 65;
			else if (islower(s[j]))
				s[j] = (((s[j] - 97) + (26 - key)) % 26) + 97;
			s1 += s[j];
		}
		cout << s1;
		cout << endl;
	}


	fp.close();
}