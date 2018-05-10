#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int i, j, k, t = 0,n=0;
	int arr[101] = { 0 };
	int count[101] = { 0 };
	int b, c, temp = 0;

	fp >> t;
	for (i = 0; i < t; i++) {
		fp >> n;
		for (j = 0; j < 101; j++) {//배열을 먼처 0으로 초기화시켜주어야 첫케이스가 0의연속일경우 에러가안남
			count[j] = 0;
			arr[j] = 0;
		}
		for (j = 0; j < n; j++) {
			fp >> arr[j];
		}
		
		for (b = 0; b < n; b++) {
			for (c = 0; c < n; c++) {
				if (arr[b] < arr[c]) {
					temp = arr[b];
					arr[b] = arr[c];
					arr[c] = temp;
				}

			}
		}
		for (j = 0; j < n; j++) {
			count[arr[j]]++;
		}

		for (k = 0; k < n; k++) {
		
			if (arr[k] != arr[k + 1]) {
				cout << arr[k] << " " << count[arr[k]] << " ";
			}			
		}
		if ((arr[n - 1] == arr[n])) {
			cout << arr[n - 1] << " " << count[arr[n - 1]] << " ";
		}
		
	
		cout << endl;
	}
	fp.close();
}