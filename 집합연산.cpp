#include <iostream>
#include <fstream>

using namespace std;

#define MAX_SIZE 132
void sort(int set[], int n) {
	int temp,a,b;
	for (b = 0; b < n; b++){
		for (a = 1; a < n; a++) {
			if (set[a-1] > set[a]) {
				temp = set[a-1];
				set[a-1] = set[a];
				set[a] = temp;
			}
		}
	}
}
void zero(int arr[]) {
	int i;
	for (i = 0; i < MAX_SIZE; i++) {
		arr[i] = 0;
	}
}
void add(int set1[], int set2[], int set3[], int size1, int size2) {
	int j, k,a=0,size3;

	for (j = 0; j < size1; j++) {
		for (k = 0; k < size2; k++) {
			if (set1[j] == set2[k]) {
				set3[a] = set1[j];
				a++;
			}
		}
	}


	cout << a << " ";
	size3 = a;
	sort(set3, size3);
	for (j = 0; j < size3; j++) {
		cout << set3[j] << " ";
	}

	a = 0;
}
void uni(int set1[], int set2[], int set3[], int size1, int size2){
	int j, k,a = 0;
	for (j = 0; j < size1; j++) {
		set3[j] = set1[j];
	}
	a = size1;
	for (j = 0; j < size2; j++) {
		for (k = 0; k < size1; k++) {
			if (set2[j] == set1[k])
				break;
		}//같은 값이 없으면 k=size1
		if(k==size1)
		set3[a++] = set2[j];//set3에 set2의 원소를 넣음
	}
	cout << a << " ";
	
	sort(set3, a);
	for (j = 0; j < a; j++) {
		cout << set3[j] << " ";
	}

	a = 0;
	
}
void differ(int set1[], int set2[], int set3[], int size1, int size2){
	int j, k, a = 0;
	
	for (j = 0; j < size1; j++) {
		for (k = 0; k < size2; k++) {
			if (set1[j] == set2[k])
				break;
		}//같은 값이 없으면 k=size2
		if (k == size2)
			set3[a++] = set1[j];//set3에 set2의 원소를 넣음
	}
	cout << a << " ";

	sort(set3, a);
	for (j = 0; j < a; j++) {
		cout << set3[j] << " ";
	}
	
	a = 0;

}
int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int t = 0, n = 0;
	int i, j,a=0;
	int set1[MAX_SIZE] = { 0 }, set2[MAX_SIZE] = { 0 }, set3[MAX_SIZE] = { 0 };
	int size1 = 0, size2 = 0, size3 = 0;
	int size = 0;
	
	fp >> t;
	for (i = 0; i < t; i++) {
		zero(set1);
		zero(set2);
		zero(set3);
		fp >> size;
		for (j = 0; j < size; j++) {
			fp >> set1[j];
		}
		size1 = size;

		fp >> size;
		for (j = 0; j < size; j++) {
			fp >> set2[j];
		}
		size2 = size;

		sort(set1, size1);
		sort(set2, size2);
		
		add (set1, set2, set3, size1, size2);
		cout << endl;
		uni (set1, set2, set3, size1, size2);
		cout << endl;
		differ(set1, set2, set3, size1, size2);
		cout << endl;
	}
	fp.close();
}
