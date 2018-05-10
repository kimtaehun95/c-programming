#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

int main(void) {
	fstream fp;
	int t;

	fp.open("input.txt");

	fp >> t;

	while (t--) {
		int data;
		const uint umax = 0xffffffff;
		vector<uint> arr;
		
		fp >> data;

		for (uint k = 1;; k *= 2) {
			for (uint l = k;; l *= 3) {
				for (uint m = l;; m *= 5) {
					arr.push_back(m);
					if (m>umax / 5) break;
				}
				if (l>umax / 3) break;
			}
			if (k>umax / 2) break;
		}
		sort(arr.begin(), arr.end());

		cout << arr[data - 1] << endl;
		
	}


	return 0;
}

