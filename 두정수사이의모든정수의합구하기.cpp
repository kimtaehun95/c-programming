#include <iostream>
#include <fstream>
using namespace std;
int sum_numbers(int s, int t)
{
	int i, sum=0;

	for (i = s; i <= t; i++) {
		sum += i;
	}
	return sum;
}
int main(void) 
{
	ifstream fp;
	fp.open("input.txt");
	int t = 0, i;
	int num1 = 0, num2 = 0;
	
	fp >> t;
	for (i = 0; i < t; i++) {
		fp >> num1 >> num2;
		cout << sum_numbers(num1,num2)<<"\n";	
	}
	cout << endl;

	fp.close();
}