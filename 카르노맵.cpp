#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int sopnum=0;
	int exp=0;
	string s="" ;//����ȭ�� ���� ����ϱ� ���� ��Ʈ�� ����
	int sop[17] = { 0, };//ī������� ��������� �Է¹��� sop�� ������ �迭
	int xy[4][4] = { 0, };//ī������� �����ϱ����� �迭
	int i=0,j=0,k=0, sopcount=0;
	
	cout << "ī������� ���� �Է� = ";
	cin >> exp;
	
	while (1) { //sop�� �Է¹ޱ����� �ݺ���
		cout << "sop �Է� (�Է¿Ϸ�� 1000�Է�)=";
		cin >> sopnum;
		if (sopnum == 1000)break;
		sop[k] = sopnum;//�Է¹��� sop�� �迭�� ����
		k++;
		sopcount++;//���Է¹��� sop ���� count
	}

	//2x2 ī������� ���
	if (exp == 2) {
		for (k = 0; k < sopcount; k++) { // ī����� ����
			if (sop[k] == 0) { xy[0][0] = 1; }
			else if (sop[k] == 1) { xy[0][1] = 1; }
			else if (sop[k] == 2) { xy[1][0] = 1; }
			else if (sop[k] == 3) { xy[1][1] = 1; }
		}
		cout << "--2 x 2 ī���� ��--" << endl;
		for (i = 0; i < exp; i++) {
			for (j = 0; j < exp; j++) {
				cout << xy[i][j] << " ";
			}
			cout << endl;
		}
		//����ȭ �� 16����
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
		cout << "����ȭ �� = " << s << endl;
	}
	//3x3ī������� ���
	else if (exp == 3) {
		for (k = 0; k < sopcount; k++) {// ī����� ����
			if (sop[k] == 0) { xy[0][0] = 1; }
			else if (sop[k] == 1) { xy[0][1] = 1; }
			else if (sop[k] == 2) { xy[0][3] = 1; }
			else if (sop[k] == 3) { xy[0][2] = 1; }
			else if (sop[k] == 4) { xy[1][0] = 1; }
			else if (sop[k] == 5) { xy[1][1] = 1; }
			else if (sop[k] == 6) { xy[1][3] = 1; }
			else if (sop[k] == 7) { xy[1][2] = 1; }
		}
		cout << "--3x3 ī�����--" << endl;
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 4; k++) {
				cout << xy[j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
		
	}
	//4x4ī������� ���
	else if (exp == 4) {
		
	}
	
	
	return 0;
}