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
		string s = "",s1 = "", s2 = "", s3 = "", s4 = "";
		fp >> s;
		string number[99] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
		"Twenty","Twenty_One","Twenty_Two","Twenty_Three","Twenty_Four","Twenty_Five","Twenty_Six","Twenty_Seven","Twenty_Eight","Twenty_Nine",
		"Thirty","Thirty_One","Thirty_Two","Thirty_Three","Thirty_Four","Thirty_Five","Thirty_Six","Thirty_Seven","Thirty_Eight","Thirty_Nine",
		"Forty","Forty_One","Forty_Two","Forty_Three","Forty_Four","Forty_Five","Forty_Six","Forty_Seven","Forty_Eight","Forty_Nine",
		"Fifty","Fifty_One","Fifty_Two","Fifty_Three","Fifty_Four","Fifty_Five","Fifty_Six","Fifty_Seven","Fifty_Eight","Fifty_Nine",
		"Sixty","Sixty_One","Sixty_Two","Sixty_Three","Sixty_Four","Sixty_Five","Sixty_Six","Sixty_Seven","Sixty_Eight","Sixty_Nine",
		"Seventy","Seventy_One","Seventy_Two","Seventy_Three","Seventy_Four","Seventy_Five","Seventy_Six","Seventy_Seven","Seventy_Eight","Seventy_Nine",
		"Eighty","Eighty_One","Eighty_Two","Eighty_Three","Eighty_Four","Eighty_Five","Eighty_Six","Eighty_Seven","Eighty_Eight","Eighty_Nine",
		"Ninety","Ninety_One","Ninety_Two","Ninety_Three","Ninety_Four","Ninety_Five","Ninety_Six","Ninety_Seven","Ninety_Eight","Ninety_Nine",
		 };
		int j,l,count=0;
		char k[2] = {'0','\0'};
		int len = s.length();
		while (s.length() > 0) {
			int len = s.length();
			if (len == 1) {
				s1 = s;
				for (l = 1; l < 10; l++) {
					if (s1[0] - 48 == l) {
						s2.append(number[l - 1]);
					}
					s3.insert(0, s2);
					s2 = "";
				}
				s.clear();
			}
			else if (len == 2) {
				s1 = s;
				j = (s1[0] - 48) * 10 + (s1[1] - 48);
				for (l = 1; l < 100; l++) {
					if (j == l) {
						s2.append(number[l - 1]);
					}
					s3.insert(0, s2);
					s2 = "";
				}
				s.clear();
			}
			else {
				s1 = s.substr(len - 3, 3);
				j = (s1[1] - 48) * 10 + (s1[2] - 48);
				s2.append(&k[0]);
				k[0]++;
				for (l = 1; l < 10; l++) {
					if (s1[0] - 48 == l) {
						s2.append(number[l - 1]);
						s2.append(" Hundred");
					}
				}
				for (l = 1; l < 100; l++) {
					if (j == l) {
						s2.append(" ");
						s2.append(number[l-1]);
					}
				}
				s.erase(len - 3, 3);
				s3.insert(0, s2);
				s2 = "";
			}
		}
		
		for (l = 1; l < s3.length(); l++) {
			if (s3[l] == '0'&&isalpha(s3[l - 1])) {
				s3.replace(l, 1, " Thousand ");
			}
			if (s3[l] == '1'&&isalpha(s3[l - 1])) {
				s3.replace(l, 1, " Million ");
			}
			if (s3[l] == '2'&&isalpha(s3[l - 1])) {
				s3.replace(l, 1, " Billion ");
			}
			if (s3[l] == ' '&&isalpha(s3[l + 1])) {
				s3.replace(l, 1, "_");
			}			
		}
		for (l = 0; l < s3.length(); l++) {
			if (s3[l] == '0') {
				s3.erase(l, 1);
			}
		}
		for (l = 0; l < s3.length(); l++) {
			if (s3[l] == '1') {
				s3.erase(l, 1);
			}
		}
		for (l = 0; l < s3.length(); l++) {
			if (s3[l] == '2') {
				s3.erase(l, 1);
			}
		}
		for (l = 0; l < s3.length(); l++) {
			if (s3[l] == '3') {
				s3.erase(l, 1);
			}
		}
		for (l = 0; l < s3.length(); l++) {
			if (s3[l] == ' '&&!isalpha(s3[l+1])) {
				s3.erase(l, 1);
			}
		}
		for (l = 1; l < s3.length(); l++) {
			if (s3[l-1] == '_' && !isalpha(s3[l - 1])) {
				s3.erase(l-1, 1);
			}break;
		}
		for (l = 0; l < s3.length(); l++) {
			if (s3[l] == ' ' && isalpha(s3[l + 1])&& isalpha(s3[l - 1])) {
				s3.replace(l, 1,"_");
			}
		}
		cout << s3 << endl;

	}
	fp.close();
	return 0;
}