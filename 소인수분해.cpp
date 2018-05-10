#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int test_case = 0;
	int i, num;
	int j, k=2;
	int c1=1, c2=0;
	int count = 0;
	int arr[10000] = { 0, };
	

	fp >> test_case;

	for (i = 0; i < test_case; i++) {
		fp >> num;
		for (j = 0; j < 10000; j++) {
			arr[j] = 0;
		}
		while (num != 1) {
				if (num%k == 0) {
					++count;
					arr[count - 1] = k;
					num = num / k;
				}
				else {
					++k;
				}
		}
		k = 2;
		for (j = 0; j < count; j++) {
			if (arr[j] != arr[j + 1]) {
				c2++;
			}
		}
		cout << c2 << " ";
		c2 = 0;
		for (j = 0; j < count; j++) {
			while (arr[j] == arr[j + 1]) {
				j++;
				c1++;
			}
			cout << arr[j] << " " << c1<<" ";
			c1 = 1;
		}
		count = 0;

		cout << endl;

	}
	fp.close();
}
