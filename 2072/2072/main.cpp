/*
... iss Crew
... Made By Mukho
... 2020-08-13 THU
... 2072 D1

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QSEhaA5sDFAUq&categoryId=AV5QSEhaA5sDFAUq&categoryType=CODE
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
	readFile.open("input.txt");

	// 전체 테스트 케이스 수를 저장
	readFile >> T;

	// 각 숫자를 입력받고, 처리 후 저장함.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// 입력
		int arr[10] = {}; // 테스트 케이스 10개를 저장할 배열
		for(int i=0;i<10;i++)
			readFile >> arr[i]; // 입력

		// 처리
		int sum = 0; // 홀수만 더할 변수
		for (int i = 0; i < 10; i++)
			if (arr[i] % 2 == 1)
				sum += arr[i];

		// 결과 출력
		cout << "#" << test_case << " " << sum << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}