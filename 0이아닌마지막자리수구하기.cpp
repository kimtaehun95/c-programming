#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");

	int test_case = 0, num = 0;
	int i, j, k = 0;
	long long n1 = 0, last_number = 0, last_number1 = 0;//값의 범위 넓혀주기
	int two_count = 0, five_count = 0, ten_count = 0, zero_count = 0;
	
	fp >> test_case;
	for (i = 0; i < test_case; i++) {
		fp >> num;
		two_count = 0;
		five_count = 0;
		zero_count = 0;
		ten_count = 0;
		last_number = 1;
		last_number1 = 1;
		k = 0;
		for (j = 0; j < num; j++) {
			fp >> n1;
		
			while (n1 % 10 == 0) {
				n1 /= 10;
				ten_count++;
			}
			while (n1 % 2 == 0) {
				n1 /= 2;
				two_count++;
			}

			while (n1 % 5 == 0) {
				n1 /= 5;
				five_count++;
			}
			n1 %= 10;
			last_number *= n1;
			last_number %= 10;
		}
		
		zero_count = two_count >= five_count ? five_count : two_count;

		if (two_count > five_count) {
			for (j = 0; j < two_count - five_count; j++) {
				last_number1 *= 2;
				last_number1 %= 10;
			}
			
		}
		else if (two_count < five_count) {
			for (j = 0; j < five_count - two_count; j++) {
				last_number1 *= 5;
				last_number1 %= 10;
			}
			
		}
		else  {
			last_number1 = 1;
		}
		last_number = (last_number1*last_number) % 10;
		
		cout << last_number << " ";
		cout << zero_count+ten_count << "\n";
	}
	fp.close();
}