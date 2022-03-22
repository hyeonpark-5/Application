//해밍코드 변환기
#include <iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;




int main() {
	string data;
	string datadata;  // 입력받은 data
	int p[100] = { 0, }; // p[]
	int leng = 0, aa = 0, lang = 0; //leng = 입력받은 data 길이, aa = 2의 거듭제곱 개수
	int i = 0, j = 0, k = 0;
	int sum = 0;



	cout << "해밍코드로 변환시킬 데이터를 입력하시오." << endl;
	cin >> data;
	leng = data.length();
	datadata = data;

	//비트 수에 따른 P의 개수 구하기
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
	//P[] 계산기
	for (int k = 1; k <= aa; k++) {  //P가 몇 개인지
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
		//XOR 계산
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

	//해밍코드로 변환
	for (int i = 1; i <= aa; i++) {
		data.replace(((int)pow(2, i - 1)) - 1, 1, to_string(p[i]));
	}


	
	cout << "<result>" << endl;
	cout << "Input: " << datadata << endl;
	cout << "Hamming Code: " << data << endl;


}

