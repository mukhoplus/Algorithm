/*
... iss Crew
... Made By Mukho
... 2020-08-09 SUN
... 9317 D3

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW-hOY5KeEIDFAVg&categoryId=AW-hOY5KeEIDFAVg&categoryType=CODE
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int test_case; // 테스트할 테스트의 번호를 저장할 변수
	int T; // 전체 test case 수

	// test case를 불러올 파일 객체 열기
	ifstream readFile;
	readFile.open("sample_input.txt");

	// 전체 테스트 케이스 수를 저장
	readFile >> T;

	// 각 숫자를 입력받고, 처리 후 저장함.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// 입력
		int N; // 테스트 케이스 문자열의 길이
		string correctStr; // 따라 적어야 하는 문자열
		string inputStr; // 따라 적은 문자열
		readFile >> N >> correctStr >> inputStr;

		// 처리
		int correctChar = 0; // 맞게 받아 적은 문자의 개수
		for (int i = 0; i < N; i++)
			if (correctStr[i] == inputStr[i])
				correctChar++;

		// 결과 출력
		cout << "#" << test_case << " " << correctChar << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}