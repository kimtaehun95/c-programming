#include <iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");

	int test_case=0;
	int i, j, k, sum=0;
	int n = 0, count = 0, max = 0;
	int arr[100][100] = { 0, }, arr1[200] = { 0, }, l = 0;
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> n;
		l = 0;
		count = 0;
		max = 0;
		for (j = 0; j < 100; j++) {
			for (k = 0; k < 100; k++) {
				arr[j][k] = 0;
			}
		}
		for (j = 0; j < 200; j++) {
			arr1[j] = 0;
		}
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				fp >> arr[j][k];
			}
		}
		while (l != n) {
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					if (j == k + l || j == k - (n - l)) {
						sum+=arr[j][k];
					}
				}
			}
			arr1[count] = sum;
			count++;
			l++;
			sum = 0;
		}
		l = 0;
		while (l != n) {
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					if (j == -k + (n - 1) - l || j == -k + (n - 1) + (n - l)) {
						sum+=arr[j][k];
					}
				}
			}
			arr1[count] = sum;
			count++;
			l++;
			sum = 0;
		}
		max = arr1[0];
		for (j = 1; j < count; j++) {
			max = max >= arr1[j] ? max : arr1[j];
		}
		cout <<max<< endl;
		
	}
	fp.close();
}