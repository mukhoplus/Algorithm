/*
... iss Crew
... Made By Mukho
... 2020-08-06 THU
... 10032 D3

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXJZ6_6KCLcDFAU3&categoryId=AXJZ6_6KCLcDFAU3&categoryType=CODE
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
		int snackNum, peopleNum; // 과자 수, 사람 수
		readFile >> snackNum >> peopleNum;

		// 처리
		int temp = snackNum % peopleNum;
		int result;
		if (temp != 0 || snackNum < peopleNum)
			result = 1;
		else
			result = 0;

		// 결과 출력
		cout << "#" << test_case << " " << result << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}