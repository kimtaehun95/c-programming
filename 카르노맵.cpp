#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int sopnum=0;
	int exp=0;
	string s="" ;//간소화된 식을 출력하기 위한 스트링 변수
	int sop[17] = { 0, };//카르노맵을 만들기위해 입력받을 sop를 저장할 배열
	int xy[4][4] = { 0, };//카르노맵을 구현하기위한 배열
	int i=0,j=0,k=0, sopcount=0;
	
	cout << "카르노맵의 차수 입력 = ";
	cin >> exp;
	
	while (1) { //sop을 입력받기위한 반복문
		cout << "sop 입력 (입력완료시 1000입력)=";
		cin >> sopnum;
		if (sopnum == 1000)break;
		sop[k] = sopnum;//입력받은 sop를 배열에 저장
		k++;
		sopcount++;//총입력받은 sop 개수 count
	}

	//2x2 카르노맵일 경우
	if (exp == 2) {
		for (k = 0; k < sopcount; k++) { // 카르노맵 구현
			if (sop[k] == 0) { xy[0][0] = 1; }
			else if (sop[k] == 1) { xy[0][1] = 1; }
			else if (sop[k] == 2) { xy[1][0] = 1; }
			else if (sop[k] == 3) { xy[1][1] = 1; }
		}
		cout << "--2 x 2 카르노 맵--" << endl;
		for (i = 0; i < exp; i++) {
			for (j = 0; j < exp; j++) {
				cout << xy[i][j] << " ";
			}
			cout << endl;
		}
		//간소화 식 16가지
		if (xy[0][0] == 1 && xy[0][1] == 0 && xy[1][0] == 0 && xy[1][1] == 0) { s = "x`y`"; }
		else if (xy[0][0] == 0 && xy[0][1] == 1 && xy[1][0] == 0 && xy[1][1] == 0) { s = "x`y"; }
		else if (xy[0][0] == 0 && xy[0][1] == 0 && xy[1][0] == 1 && xy[1][1] == 0) { s = "xy`"; }
		else if (xy[0][0] == 0 && xy[0][1] == 0 && xy[1][0] == 0 && xy[1][1] == 1) { s = "xy"; }
		else if (xy[0][0] == 1 && xy[0][1] == 1 && xy[1][0] == 0 && xy[1][1] == 0) { s = "x`"; }
		else if (xy[0][0] == 1 && xy[1][0] == 1 && xy[0][1] == 0 && xy[1][1] == 0) { s = "y`"; }
		else if (xy[0][0] == 0 && xy[1][0] == 1 && xy[0][1] == 0 && xy[1][1] == 1) { s = "x"; }
		else if (xy[0][0] == 0 && xy[1][0] == 0 && xy[0][1] == 1 && xy[1][1] == 1) { s = "y"; }
		else if (xy[0][0] == 1 && xy[1][1] == 1 && xy[1][0] == 0 && xy[0][1] == 0) { s = "x`y` + xy"; }
		else if (xy[0][0] == 0 && xy[1][1] == 0 && xy[1][0] == 1 && xy[0][1] == 1) { s = "x`y + xy`"; }
		else if (xy[0][0] == 1 && xy[1][1] == 0 && xy[1][0] == 1 && xy[0][1] == 1) { s = "x` + y`"; }
		else if (xy[0][0] == 1 && xy[1][1] == 1 && xy[1][0] == 0 && xy[0][1] == 1) { s = "x` + y"; }
		else if (xy[0][0] == 1 && xy[1][1] == 1 && xy[1][0] == 1 && xy[0][1] == 0) { s = "x + y`"; }
		else if (xy[0][0] == 0 && xy[1][1] == 1 && xy[1][0] == 1 && xy[0][1] == 1) { s = "x + y"; }
		else if (xy[0][0] == 1 && xy[1][1] == 1 && xy[1][0] == 1 && xy[0][1] == 1) { s = "1"; }
		else if (xy[0][0] == 0 && xy[1][1] == 0 && xy[1][0] == 0 && xy[0][1] == 0) { s = "0"; }
		cout << "간소화 식 = " << s << endl;
	}
	//3x3카르노맵일 경우
	else if (exp == 3) {
		for (k = 0; k < sopcount; k++) {// 카르노맵 구현
			if (sop[k] == 0) { xy[0][0] = 1; }
			else if (sop[k] == 1) { xy[0][1] = 1; }
			else if (sop[k] == 2) { xy[0][3] = 1; }
			else if (sop[k] == 3) { xy[0][2] = 1; }
			else if (sop[k] == 4) { xy[1][0] = 1; }
			else if (sop[k] == 5) { xy[1][1] = 1; }
			else if (sop[k] == 6) { xy[1][3] = 1; }
			else if (sop[k] == 7) { xy[1][2] = 1; }
		}
		cout << "--3x3 카르노맵--" << endl;
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 4; k++) {
				cout << xy[j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
		
	}
	//4x4카르노맵일 경우
	else if (exp == 4) {
		
	}
	
	
	return 0;
}