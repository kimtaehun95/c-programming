#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	int t;
	ifstream input("input.txt");
	input >> t;
	while (t--) {
		string arr;
		int n;
		input >> arr >> n;
		int h = (arr[0] - '0') * 10 + (arr[1] - '0');
		int m = (arr[3] - '0') * 10 + (arr[4] - '0');
		int t = arr[5] == 'A';
		if (h == 12) h = 0;
		h += n / 60;
		m += n % 60;
		if (m >= 60) {
			m -= 60;
			h++;
		}
		else if (m<0) {
			h--;
			m += 60;
		}
		if (h > 11) {
			t = ((h / 12) % 2) ? !t : t;
			h -= (h / 12) * 12;
		}
		else if (h < 0) {
			t = (((-h) / 12) % 2) ? t : !t;
			h += ((-h) / 12 + 1) * 12;
		}
		if (h == 0)h += 12;
		arr[5] = (t) ? 'A' : 'P';
		cout << h / 10 << h % 10 << ':' << m / 10 << m % 10 << arr[5] << arr[6] << endl;
	}
}