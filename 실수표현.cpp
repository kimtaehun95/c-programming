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
			if (s[j] != '.'&&s[j] != 'e'&&s[j] != 'E'&&isdigit(s[j]) == 0&&s[j]!='+'&&s[j] != '-') { err = 1; break; }//�������ƴѹ��ڰ����ð��
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
		else if (countd == 1 && counte==0 && count == 1 && dotp < atp) { cout << "0"; }//�����ΰ����������ʰ�Ҽ����ڿ���ȣ�������°��
		else if (countd == 1 && counte == 1 && dotp > exp) { cout << "0"; }//�����ΰ��Ҽ������پտ��������
		else if (countd >= 2 || counte >= 2 || count >= 2) { cout << "0"; }//�Ҽ���,�����ζǴ�+,-��2���̻��ΰ��
		else if (count == 1 && isdigit(s[atp + 1]) == 0) { cout << "0"; }//��ȣ�������������������������
		else if (countd == 1 && s.substr(dotp + 1, exp - dotp - 1).length() == 0 && s.substr(0, dotp).length() == 0) {
			cout << "0";
		}//�����οͽǼ��εѴٻ����Ѱ��
		else if (countd == 0 && counte == 0) { cout << "0";}//�Ҽ����������εѴٻ����Ѱ��
		else if (countd == 0 && counte == 1 && s.substr(0, exp).length() == 0) {cout << "0";}//�����δ����������� �����οͽǼ��ΰ������Ȱ��
		else if (counte == 1 && s.substr(exp+1, len).length() == 0) {cout << "0";}//�����δ����������������ʴ°��
		else cout << "1";

		cout << endl;
	}
	fp.close();
}