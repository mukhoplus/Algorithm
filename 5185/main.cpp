/*
... iss Crew
... Made By Mukho
... 2020-08-24 MON
... 5185. [파이썬 S/W 문제해결 구현] 1일차 - 이진수(D2)

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int test_case; // 테스트할 테스트의 번호를 저장할 변수
	int T; // 테스트 케이스 수 T

	// test case를 불러올 파일 객체 열기
	ifstream readFile;
	readFile.open("sample_input.txt");

	// 테스트 케이스 수를 저장
	readFile >> T;

	// 각 숫자를 입력받고, 처리 후 저장함.
	for (test_case = 1; test_case <= T; ++test_case) {
		// 입력 
		int N; // 자리 수
		string hexStr; // 16진수
		readFile >> N;
		readFile >> hexStr;

		// 처리
		string bnsStr = ""; // 2진수
		for (int i = 0; i < N; i++) {
			switch (hexStr[i]) {
			case '0':
				bnsStr += "0000";
				break;
			case '1':
				bnsStr += "0001";
				break;
			case '2':
				bnsStr += "0010";
				break;
			case '3':
				bnsStr += "0011";
				break;
			case '4':
				bnsStr += "0100";
				break;
			case '5':
				bnsStr += "0101";
				break;
			case '6':
				bnsStr += "0110";
				break;
			case '7':
				bnsStr += "0111";
				break;
			case '8':
				bnsStr += "1000";
				break;
			case '9':
				bnsStr += "1001";
				break;
			case 'A':
				bnsStr += "1010";
				break;
			case 'B':
				bnsStr += "1011";
				break;
			case 'C':
				bnsStr += "1100";
				break;
			case 'D':
				bnsStr += "1101";
				break;
			case 'E':
				bnsStr += "1110";
				break;
			case 'F':
				bnsStr += "1111";
				break;
			}
		}

		// 출력
		cout << "#" << test_case << " " << bnsStr << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}