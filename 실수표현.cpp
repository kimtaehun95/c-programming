#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int test_case = 0;
	int i, j;
	int countd = 0, counte = 0, dotp = 0, len = 0, exp = 0, err = 0, count = 0, atp = 0;
	string s="";
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> s;
		len = s.length();
		countd = 0;
		counte = 0;
		count = 0;
		dotp = 0;
		exp = 0;
		atp = 0;
		err = 0;
		for (j = 0; j < len; j++) {
			if (s[j] != '.'&&s[j] != 'e'&&s[j] != 'E'&&isdigit(s[j]) == 0&&s[j]!='+'&&s[j] != '-') { err = 1; break; }//정수가아닌문자가나올경우
			else if (s[j] == '.') {
				countd++;
				dotp = j;
			}
			else if (s[j] == 'e' || s[j] == 'E') {
				counte++;
				exp = j;
			}
			else if (s[j] == '+' || s[j] == '-') {
				count++;
				atp = j;
			}
		}

		if (err == 1) { cout << "0"; }
		else if (countd == 1 && counte==0 && count == 1 && dotp < atp) { cout << "0"; }//지수부가존재하지않고소수점뒤에부호가나오는경우
		else if (countd == 1 && counte == 1 && dotp > exp) { cout << "0"; }//지수부가소수점보다앞에있을경우
		else if (countd >= 2 || counte >= 2 || count >= 2) { cout << "0"; }//소수점,지수부또는+,-가2개이상인경우
		else if (count == 1 && isdigit(s[atp + 1]) == 0) { cout << "0"; }//부호다음에정수가나오지않을경우
		else if (countd == 1 && s.substr(dotp + 1, exp - dotp - 1).length() == 0 && s.substr(0, dotp).length() == 0) {
			cout << "0";
		}//정수부와실수부둘다생략한경우
		else if (countd == 0 && counte == 0) { cout << "0";}//소수점과지수부둘다생략한경우
		else if (countd == 0 && counte == 1 && s.substr(0, exp).length() == 0) {cout << "0";}//지수부는존재하지만 정수부와실수부가생략된경우
		else if (counte == 1 && s.substr(exp+1, len).length() == 0) {cout << "0";}//지수부다음정수가나오지않는경우
		else cout << "1";

		cout << endl;
	}
	fp.close();
}