#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream fp;
	fp.open("input.txt");
	int i, j, a;
	int t = 0,n=0;
	int s = 0, b = 0, num = 0;
	int num1, num2, num3, num4, count=0,temp;
	int a1=0, a2=0, a3=0, a4=0;
	int arr[10000] = { 0 };
	fp >> t;
	for (i = 0; i < t; i++)
	{
		fp >> n;
		for (a = 0; a < 10000; a++) {//각각의 네자리 숫자를 판별하고 판단하여 누적시키기려면 이 곳에서 초기화
			arr[a] = 0;
		}
		
		for (j = 0; j < n; j++) {
			fp >> num >> s >> b;
			num1 = num % 10;
			num2 = ((num / 10) % 10);
			num3 = ((num / 100) % 10);
			num4 = (num / 1000);
			//네자리 숫자의 각각의 자릿수를 비교하기위해
			if (s == 0 && b == 0) {
				continue;
			}
			else if (s == 0 && b == 1) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if ((num4 == a3) || (num4 == a2) || (num4 == a1)) {
						arr[a] += 1;
					}
					else if ((num3 == a4) || (num3 == a2) || (num3 == a1)) {
						arr[a] += 1;
					}
					else if ((num2 == a4) || (num2 == a3) || (num2 == a1)) {
						arr[a] += 1;
					}
					else if ((num1 == a3) || (num1 == a2) || (num1 == a4)) {
						arr[a] += 1;
					}
				}
			}
			else if (s == 0 && b == 2) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					//두 볼이 같은 수와 같지 않은 수 구분
					//두 볼이 같을 때
					if ((num4 == num3) || (num4 == num2) || (num4 == num1) || (num3 == num2) || (num3 == num1) || (num2 == num1)) {
						if ((num4 == a2)&&(num3==a1)) {
							arr[a] += 1;
						}
						else if ((num4 == a3) && (num2 == a1)) {
							arr[a] += 1;
						}
						else if ((num4 == a3) && (num1 == a2)) {
							arr[a] += 1;
						}
						else if ((num3 == a1) && (num2 == a4)) {
							arr[a] += 1;
						}
						else if ((num3 == a4) && (num1 == a2)) {
							arr[a] += 1;
						}
						else if ((num2 == a4) && (num1 == a3)) {
							arr[a] += 1;
						}
					}
					//두 볼이 다를 때
					else {
						if ((num4 == a3) || (num4 == a2) || (num4 == a1)) {
							if (((num3 == a4) || (num3 == a2) || (num3 == a1))) {
								arr[a] += 1;
							}
							else if (((num2 == a4) || (num2 == a1) || (num2 == a3))) {
								arr[a] += 1;
							}
							else if (((num1 == a4) || (num1 == a2) || (num1 == a3))) {
								arr[a] += 1;
							}
						}
						else if ((num3 == a4) || (num3 == a2) || (num3 == a1)) {
							if ((num2 == a4) || (num2 == a3) || (num2 == a1)) {
								arr[a] += 1;
							}
							else if ((num1 == a4) || (num1 == a3) || (num1 == a2)) {
								arr[a] += 1;
							}
						}
						else if (((num2 == a3) || (num2 == a4) || (num2 == a1)) && ((num1 == a4) || (num1 == a2) || (num1 == a3))) {
							arr[a] += 1;
						}
					}
				}
			}
			else if (s == 0 && b == 3) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					//3개의 볼이 같은 수와 3개의 볼 중 2개만 같은 수와 3개의 볼 모두 다른 수 구분
					//3개의 볼이 같을 때
					if (((num4 == num3) && (num4 == num2))||((num4 == num3) && (num4 == num1))||((num4 == num1) && (num4 == num2))||((num3 == num2) && (num3 == num1))) {
						break;
					}
					//3개중 2개의 볼이 같을 때
					if ((num4 == num3) || (num4 == num2) || (num3 == num2)) {
						if (num4 == num3) {
							if ((num4 == a2) && (num4 == a1) && ((num2 == a4) || (num2 == a3))) {
								arr[a] += 1;
							}
							else if ((num4 == a2) && (num4 == a1) && ((num1 == a4) || (num1 == a3))) {
								arr[a] += 1;
							}
						}
						else if (num4 == num2) {
							if ((num4 == a3) && (num4 == a1) && ((num3 == a4) || (num3 == a2))) {
								arr[a] += 1;
							}
							else if ((num4 == a3) && (num4 == a1) && ((num1 == a4) || (num1 == a2))) {
								arr[a] += 1;
							}
						}
						else if (num3 == num2) {
							if ((num3 == a4) && (num3 == a1) && ((num4 == a3) || (num4 == a2))) {
								arr[a] += 1;
							}
						}
					}
					else if ((num4 == num3) || (num4 == num1) || (num3 == num1)) {			
						if (num4 == num1) {
							if ((num4 == a3) && (num4 == a2) && ((num3 == a4) || (num3 == a1))) {
								arr[a] += 1;
							}
							else if ((num4 == a3) && (num4 == a2) && ((num2 == a4) || (num2 == a1))) {
								arr[a] += 1;
							}
						}
						else if (num3 == num1) {
							if ((num3 == a4) && (num3 == a2) && ((num4 == a3) || (num4 == a1))) {
								arr[a] += 1;
							}
						}
					}
					else if ((num3 == num2) || (num3 == num1) || (num2 == num1)) {
						if (num3 == num2) {
							if ((num3 == a4) && (num3 == a1) && ((num1 == a3) || (num1 == a2))) {
								arr[a] += 1;
							}
						}
						else if (num3 == num1) {
							if ((num3 == a4) && (num3 == a2) && ((num2 == a3) || (num2 == a1))) {
								arr[a] += 1;
							}
						}
						else if (num2 == num1) {
							if ((num2 == a4) && (num2 == a3) && ((num3 == a2) || (num3 == a1))) {
								arr[a] += 1;
							}
							if ((num2 == a4) && (num2 == a3) && ((num4 == a2) || (num4 == a1))) {
								arr[a] += 1;
							}
						}
					}
					//3개 모두 다를 때
					if ((num4 == a3) || (num4 == a2) || (num4 == a1)) {
						if (((num3 == a4) || (num3 == a2) || (num3 == a1)) && ((num2 == a3) || (num2 == a4) || (num2 == a1))) {
							arr[a] += 1;
						}
						else if (((num3 == a4) || (num3 == a2) || (num3 == a1)) && ((num1 == a3) || (num1 == a4) || (num1 == a2))) {
							arr[a] += 1;
						}
						else if (((num1 == a4) || (num1 == a2) || (num1 == a3)) && ((num2 == a3) || (num2 == a4) || (num2 == a1))) {
							arr[a] += 1;
						}
					}
					else if ((num3 == a4) || (num3 == a2) || (num3 == a1)) {
						if (((num2 == a3) || (num2 == a4) || (num2 == a1)) && ((num1 == a3) || (num1 == a4) || (num1 == a2))) {
							arr[a] += 1;
						}
					}
				}
			}
			else if (s == 0 && b == 4) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if ((num4 == a3) || (num4 == a2) || (num4 == a1)) {
						if ((num3 == a4) || (num3 == a2) || (num3 == a1)) {
							if ((num2 == a4) || (num2 == a3) || (num2 == a1)) {
								if ((num1 == a4) || (num1 == a3) || (num1 == a2)) {
									arr[a] += 1;
								}
							}
						}
					}

				}
			}
			else if (s == 1 && b == 0) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if (num4 == a4) {
						arr[a] += 1;
					}
					if (num3 == a3) {
						arr[a] += 1;
					}
					if (num2 == a2) {
						arr[a] += 1;
					}
					if (num1 == a1) {
						arr[a] += 1;
					}
				}
			}
			else if (s == 1 && b == 1) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if (num4 == a4) {
						if ((num3 == a2) || (num3 == a1)) {
							arr[a] += 1;
						}
						else if ((num2 == a3) || (num2 == a1)) {
							arr[a] += 1;
						}
						else if ((num1 == a3) || (num1 == a2)) {
							arr[a] += 1;
						}
					}

					else if (num3 == a3) {
						if ((num4 == a2) || (num4 == a1)) {
							arr[a] += 1;
						}
						else if ((num2 == a4) || (num2 == a1)) {
							arr[a] += 1;
						}
						else if ((num1 == a4) || (num1 == a2)) {
							arr[a] += 1;
						}
					}
					else if (num2 == a2) {
						if ((num4 == a3) || (num4 == a1)) {
							arr[a] += 1;
						}
						else if ((num3 == a4) || (num3 == a1)) {
							arr[a] += 1;
						}
						else if ((num1 == a4) || (num1 == a3)) {
							arr[a] += 1;
						}
					}
					else if (num1 == a1) {
						if ((num4 == a2) || (num4 == a3)) {
							arr[a] += 1;
						}
						else if ((num2 == a4) || (num2 == a3)) {
							arr[a] += 1;
						}
						else if ((num3 == a4) || (num3 == a2)) {
							arr[a] += 1;
						}
					}
				}
			}
			else if (s == 1 && b == 2) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if ((num4 == a4) || (num3 == a3) || (num2 == a2) || (num1 == a1)) {
						if (num4 == a4) {
							if ((num3 == num2) || (num3 == num1)||(num2==num1)) {
								break;
							}
							else if ((num3 == a2) && ((num2 == a3) || (num2 == a1))) {
								arr[a] += 1;
							}
							else if ((num3 == a1) && (num2 == a3)) {
								arr[a] += 1;
							}
							else if ((num3 == a1) && ((num1 == a3) || (num1 == a2))) {
								arr[a] += 1;
							}
							else if ((num3 == a2) && (num1 == a3)) {
								arr[a] += 1;
							}
							else if ((num2 == a1) && ((num1 == a3) || (num1 == a2))) {
								arr[a] += 1;
							}
							else if ((num2 == a3) && (num1 == a2)) {
								arr[a] += 1;
							}
						}
						else if (num3 == a3) {
							if ((num4 == num2) || (num4 == num1)||(num2==num1)) {
								break;
							}
							else if ((num4 == a2) && ((num2 == a4) || (num2 == a1))) {
								arr[a] += 1;
							}
							else if ((num4 == a1) && (num2 == a4)) {
								arr[a] += 1;
							}
							else if ((num4 == a1) && ((num1 == a4) || (num1 == a2))) {
								arr[a] += 1;
							}
							else if ((num4 == a2) && (num1 == a4)) {
								arr[a] += 1;
							}
							else if ((num2 == a1) && ((num1 == a4) || (num1 == a2))) {
								arr[a] += 1;
							}
							else if ((num2 == a4) && (num1 == a2)) {
								arr[a] += 1;
							}
						}
						else if (num2 = a2) {
							if ((num4 == num3) || (num4 == num1) || (num3 == num1)) {
								break;
							}
							else if ((num4 == a3) && ((num3 == a4) || (num3 == a1))) {
								arr[a] += 1;
							}
							else if ((num4 == a1) && (num3 == a4)) {
								arr[a] += 1;
							}
							else if ((num4 == a1) && ((num1 == a3) || (num1 == a4))) {
								arr[a] += 1;
							}
							else if ((num4 == a3) && (num1 == a4)) {
								arr[a] += 1;
							}
							else if ((num3 == a1) && ((num1 == a3) || (num1 == a4))) {
								arr[a] += 1;
							}
							else if ((num3 == a4) && (num1 == a2)) {
								arr[a] += 1;
							}
						}
						else if (num1 = a1) {
							if ((num4 == num3) || (num4 == num2) || (num3 == num2)) {
								break;
							}
							else if ((num4 == a3) && ((num3 == a4) || (num3 == a1))) {
								arr[a] += 1;
							}
							else if ((num4 == a2) && (num3 == a4)) {
								arr[a] += 1;
							}
							else if ((num4 == a2) && ((num1 == a3) || (num1 == a4))) {
								arr[a] += 1;
							}
							else if ((num4 == a3) && (num1 == a4)) {
								arr[a] += 1;
							}
							else if ((num3 == a2) && ((num2 == a3) || (num2 == a4))) {
								arr[a] += 1;
							}
							else if ((num3 == a4) && (num2 == a3)) {
								arr[a] += 1;
							}
						}

					}

				}
			}
			else if (s == 1 && b == 3) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if (num4 == a4) {
						if ((num3 == num2) || (num3 == num1) || (num2 == num1)) {
							break;
						}
						else if (num3 == a2){
							if ((num1 == a3) && (num2 == a1)) {
								arr[a] += 1;
							}
						}
						else if (num3 == a1) {
							if ((num1 == a2) && (num2 == a3)) {
								arr[a] += 1;
							}
						}
					}
					else if (num3 == a3) {
						if ((num4 == num2) || (num4 == num1) || (num2 == num1)) {
							break;
						}
						else if (num4 == a2) {
							if ((num1 == a4) && (num2 == a1)) {
								arr[a] += 1;
							}
						}
						else if (num4 == a1) {
							if ((num1 == a2) && (num2 == a4)) {
								arr[a] += 1;
							}
						}
					}
					else if (num2 == a2) {
						if ((num3 == num4) || (num3 == num1) || (num4 == num1)) {
							break;
						}
						else if (num4 == a3) {
							if ((num1 == a4) && (num3 == a1)) {
								arr[a] += 1;
							}
						}
						else if (num4 == a1) {
							if ((num1 == a3) && (num3 == a4)) {
								arr[a] += 1;
							}
						}
					}
					else if (num1 == a1) {
						if ((num3 == num4) || (num3 == num2) || (num2 == num4)) {
							break;
						}
						if (num4 == a2) {
							if ((num3 == a4) && (num2 == a3)) {
								arr[a] += 1;
							}
						}
						else if (num4 == a3) {
							if ((num3 == a2) && (num2 == a4)) {
								arr[a] += 1;
							}
						}
					}

				}
			}
			else if (s == 2 && b == 0) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					//두 스트라이크가 같을 때와 다를 때 구분
					//2개의 스트라이크가 같을 때
					if ((num4 == num3) || (num4 == num2) || (num4==num1) || (num3==num2) || (num3==num1) || (num2==num1)) {
						if ((num4 == num3) && (num4 == a4) && (num3 == a3)) {
							arr[a] += 1;
						}
						else if ((num4 == num2) && (num4 == a4) && (num2 == a2)) {
							arr[a] += 1;
						}
						else if ((num4 == num1) && (num4 == a4) && (num1 == a1)) {
							arr[a] += 1;
						}
						else if ((num3 == num2) && (num3 == a3) && (num2 == a2)) {
							arr[a] += 1;
						}
						else if ((num3 == num1) && (num3 == a3) && (num1 == a1)) {
							arr[a] += 1;
						}
						else if ((num2 == num1) && (num2 == a2) && (num1 == a1)) {
							arr[a] += 1;
						}
					}
					//2개의 스트라이크가 다를 때
					else {
						if ((num4 == a4) && (num3 == a3)) {
							arr[a] += 1;
						}
						else if ((num4 == a4) && (num2 == a2)) {
							arr[a] += 1;
						}
						else if ((num4 == a4) && (num1 == a1)) {
							arr[a] += 1;
						}
						else if ((num3 == a3) && (num2 == a2)) {
							arr[a] += 1;
						}
						else if ((num3 == a3) && (num1 == a1)) {
							arr[a] += 1;
						}
						else if ((num2 == a2) && (num1 == a1)) {
							arr[a] += 1;
						}
					}
				}

			}
			else if (s == 2 && b == 1) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if (num4==num3||num4==num2||num4==num1||num3==num2||num3==num1||num2==num1) {
						break;
					}
					else {
						if ((num4 == a4) && (num3 == a3) && ((num2 == a1) || (num1 == a2))) {
							arr[a] += 1;
						}
						else if ((num4 == a4) && (num2 == a2) && ((num3 == a1) || (num1 == a3))) {
							arr[a] += 1;
						}
						else if ((num4 == a4) && (num1 == a1) && ((num3 == a2) || (num2 == a3))) {
							arr[a] += 1;
						}
						else if ((num3 == a3) && (num2 == a2) && ((num4 == a1) || (num1 == a4))) {
							arr[a] += 1;
						}
						else if ((num3 == a3) && (num1 == a1) && ((num4 == a2) || (num2 == a4))) {
							arr[a] += 1;
						}
						else if ((num2 == a2) && (num1 == a1) && ((num4 == a3) || (num3 == a4))) {
							arr[a] += 1;
						}
					}
				}
			}
			else if (s == 2 && b == 2) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if ((num4==num3)||(num4==num2)||(num3==num2)||(num3==num1)||(num2==num1)) {
						break;
					}
					else {
						if ((num4 == a4) && (num3 == a3) && (num2 == a1) && (num1 == a2)) {
							arr[a] += 1;
						}
						else if ((num4 == a4) && (num3 == a1) && (num2 == a2) && (num1 == a3)) {
							arr[a] += 1;
						}
						else if ((num4 == a4) && (num3 == a2) && (num2 == a3) && (num1 == a1)) {
							arr[a] += 1;
						}
						else if ((num4 == a1) && (num3 == a3) && (num2 == a2) && (num1 == a4)) {
							arr[a] += 1;
						}
						else if ((num4 == a2) && (num3 == a3) && (num2 == a4) && (num1 == a1)) {
							arr[a] += 1;
						}
						else if ((num4 == a3) && (num3 == a4) && (num2 == a2) && (num1 == a1)) {
							arr[a] += 1;
						}
					}
				}
			}
			else if (s == 3 && b == 0) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if ((num4 == a4) && (num3 == a3) && (num2 == a2)) {
						arr[a] += 1;
					}
					else if ((num4 == a4) && (num3 == a3) && (num1 == a1)) {
						arr[a] += 1;
					}
					else if ((num4 == a4) && (num1 == a1) && (num2 == a2)) {
						arr[a] += 1;
					}
					else if ((num1 == a1) && (num3 == a3) && (num2 == a2)) {
						arr[a] += 1;
					}
				}
			}
			else if (s == 3 && b == 1) {
				break;
			}
			else if (s == 4 && b == 0) {
				for (a = 0; a < 10000; a++) {
					a1 = a % 10;
					a2 = ((a / 10) % 10);
					a3 = ((a / 100) % 10);
					a4 = (a / 1000);
					if ((num4 == a4)&&(num3 == a3)&&(num2 == a2)&&(num1 == a1)) {
						arr[a] += 1; break;
					}
				}
			}

		}
		//출력하는 부분
		for (a = 0; a < 10000; a++) {
			if (arr[a] == n) {
				count++;
				temp = a;
			}
		}

		if (count == 1) {//찾고자하는수가 1개일때
			cout << temp;
		}
		else if (count > 1) {//찾고자하는수가 여러개일때
			cout << "-1";
		}
		else if (count == 0) {//찾고자하는수가 없을때
			cout << "-2";
		}

		count = 0;
		cout << endl;
	}
	fp.close();
}