#include<stdio.h>

int binsearch(int arr[], int start, int end, int search)
{
	int middle = 0;

	if (start > end)
		return -1;

	middle = (start + end) / 2;

	if (arr[middle] == search)
	{
		return middle;
	}
	else if (search < arr[middle])
	{
		return binsearch(arr, start, middle - 1, search);
	}
	else
		return binsearch(arr, middle + 1, end, search);
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 11, 13 };
	int res,n=0;
	printf("찾을 수 입력 = ");
	scanf_s("%d", &n);
	res = binsearch(arr, 0, sizeof(arr) / sizeof(int), n);

	if (res == -1)
	{
		printf("탐색 실패!\n");
	}
	else {
		for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n%d번째에 있습니다.\n ", res+1);
	}
	return 0;
}