#include <iostream>
#include <string>
#include<fstream>
using namespace std;


int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	string s;
	string s1 = "";
	int test_case = 0, num = 0;
	int i, j;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> num;
		fp >> s;
		s1 = "";
		for (j = 0; j < s.length(); j++) {
			if (isupper(s[j]))
				s[j] = (((s[j] - 65) + num) % 26) + 65;
			else if (islower(s[j]))
				s[j] = (((s[j] - 97) + num) % 26) + 97;
			s1+=s[j];
		}
		cout <<s1<< endl;
	
	}

	fp.close();
}



