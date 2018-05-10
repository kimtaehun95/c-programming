#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int facto(int num, int n)
{
	if (n == 0) return 1;
	else return num*facto(num,n-1);
}
int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int test_case = 0;
	int i,j;
	int k = 0;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		string n = "";
		int num[32] = { 0, }, trans[32] = { 0, };
		int a = 0, l = 0;
		int tnumber = 0, exp = 0;
		fp >> k;
		fp >> n;
		fp >> a;
		int len = n.length();
		for (j = 0; j < len; j++) {
			num[j] = n[j];
			if (num[j] >= 48 && num[j] < 97) { num[j] -= 48; }
			else if (num[j] >= 97 && num[j] < 103) { num[j] -= 87; }
		}
		for (j = len - 1; j >= 0; j--) {//입력받은숫자를 10진수로 변경
			tnumber += num[j] * facto(k, exp);
			exp++;
		}
		if (a == 10) { cout << tnumber; }
		else {
			while (tnumber > 0) {
				trans[l] = tnumber%a;
				tnumber /= a;
				l++;
			}
			for (j = l - 1; j >= 0; j--) {
				if (trans[j] >= 10 && trans[j] <= 15) { trans[j] += 87; cout << (char)trans[j]; }
				else { cout << trans[j]; }
			}
		}
		cout << endl;

	}
	fp.close();
}