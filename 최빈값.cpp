#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int t = 0,i,j,n=0;
	int arr[101] = { 0 };
	int count[101] = { 0 };
	int a, b, temp = 0;
	int cnt=1,cnt1=0,max=0;
	fp >> t;
	for (i = 0; i < t; i++)
	{
		fp >> n;
		for (j = 0; j < 101; j++) {
			count[j] = 0;
			arr[j] = 0;
		}
		max = count[0];
		cnt1 = 0;
		for (j = 0; j < n; j++) {
			fp >> arr[j];
		}
		for (a = 0; a < n; a++) {
			for (b = 0; b < n; b++) {
				if (arr[a] < arr[b]) {
					temp = arr[b];
					arr[b] = arr[a];
					arr[a] = temp;
				}
			}
		}
		
		for (j = 0; j < n; j++) {
			if (arr[j] == arr[j + 1]) {
				cnt++;
			}
			else if (arr[j] != arr[j + 1]) {
				count[j] = cnt;
				cnt = 1;
			}
			if (arr[n - 1] == arr[n]) {//0의 연속일경우
				count[j] = cnt-1;//arr[n]번째의 0은 뺴줘야한다.
			}
			
		}
		cnt = 1;
		
		for(j = 0; j < n; j++) {
			if (max < count[j]) {
				max = count[j];
			}
	
		}
		for (j = 0; j < n; j++) {
			if (max == count[j]) {
				cnt1++;
			}
		}
		cout << cnt1 << " "<<max<<" ";
		
		for (j = 0; j < n; j++) {
			if (max == count[j]) {
				cout << arr[j] << " ";
			}
		}
		
		cout << endl;
	}
	fp.close();
}