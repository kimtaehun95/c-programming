#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");

	int test_case = 0, n = 0, k = 0;
	int arr[256] = { 0, };
	int arr1[256] = { 0, };
	int i, j=0, l=0,a=0;
	int sum = 0,k1=0;

	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> n;
		for (j = 0; j < n; j++) {
			fp >> arr[j];
		}
		fp >> k;
		k1 = k;
		j = 0;
		while (k1 != n+1) {
			for (a = l; a < k1; a++) {
				sum += arr[a];
			}
			arr1[j] = sum;
			l++;
			k1++;
			j++;
			sum = 0;
		}
		k1 = 0;
		cout << j << " ";
		for (l = 0; l < j; l++) {
			cout << arr1[l]/k << " ";
		}
		l = 0;
		cout << endl;
		
	}
	fp.close();

}