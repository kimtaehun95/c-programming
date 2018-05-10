#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	int t=0,j,k,i;
	unsigned int n = 0;
	int arr[31] = {0};
	int count = 0;
	fp.open("input.txt");
	fp >> t;
	for (i = 0; i < t; i++) {
		fp >> n;
		for (j = sizeof(arr)/sizeof(int)-1; j>=0;j--) {			
			arr[j] = n % 2;
			n /= 2;
		}
		n = arr[0];
		for (j = 1; j <= sizeof(arr) / sizeof(int) - 1; j++) {
			
			n = n*2+arr[j];
		}
		
		for (k = 0; k < sizeof(arr) / sizeof(int); k++) {
			if (arr[k] == 1) {
				count++;
			}
		}
		if (count % 2 == 0) {
			cout << n<<endl;
		}
		else if (count%2==1) {
		
			cout << n+2147483648<<endl;
		}
		count = 0;
	}
	fp.close();
}