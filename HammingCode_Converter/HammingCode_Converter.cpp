//�ع��ڵ� ��ȯ��
#include <iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;




int main() {
	string data;
	string datadata;  // �Է¹��� data
	int p[100] = { 0, }; // p[]
	int leng = 0, aa = 0, lang = 0; //leng = �Է¹��� data ����, aa = 2�� �ŵ����� ����
	int i = 0, j = 0, k = 0;
	int sum = 0;



	cout << "�ع��ڵ�� ��ȯ��ų �����͸� �Է��Ͻÿ�." << endl;
	cin >> data;
	leng = data.length();
	datadata = data;

	//��Ʈ ���� ���� P�� ���� ���ϱ�
	for (int i = 1; i < leng; i++) {
		if (pow(2, i) >= leng + i + 1) {
			aa = i;
			break;
		}
	}

	
	for (int j = 0; j < aa; j++) {
		data.insert(((int)pow(2, j)) - 1, "0");
	}
	lang = data.length();
	cout << "lang: " << lang << endl;
	//P[] ����
	for (int k = 1; k <= aa; k++) {  //P�� �� ������
		int start = ((int)pow(2, k - 1));
		int end = k;
		int T = 0;
		int w;
		cout << "k= " << k << endl;
		for (w = (((int)pow(2, k - 1)) - 1); w < lang; ) {
			cout << "w:" << w << endl;

			for (T = 0; T < start; T++) {
				if (w < lang) {
					cout << "sumdata: " << data[w] << endl;
					sum += (data[w++] - 48);
				}
				else {
					break;
				}
			}

			w += start;
			T = 0;
		}
		cout << "sum: " << sum << endl;
		//XOR ���
		if (sum % 2 == 0) {
			p[k] = 0;
		}
		else {
			p[k] = 1;
		}
		sum = 0;
	}
	//p[i]
	for (int i = 1; i <= aa; i++) {
		//cout << "p[i]: " << p[i] << endl;
		printf("p[%d]: %d\n", i, p[i]);
	}

	//�ع��ڵ�� ��ȯ
	for (int i = 1; i <= aa; i++) {
		data.replace(((int)pow(2, i - 1)) - 1, 1, to_string(p[i]));
	}


	
	cout << "<result>" << endl;
	cout << "Input: " << datadata << endl;
	cout << "Hamming Code: " << data << endl;


}

