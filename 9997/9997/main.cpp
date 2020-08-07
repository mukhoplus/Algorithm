/*
... iss Crew
... Made By Mukho
... 2020-08-07 FRI
... 9997 D3

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXIvNBzKapEDFAXR&categoryId=AXIvNBzKapEDFAXR&categoryType=CODE
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
	readFile.open("1_input.txt");

	// 전체 테스트 케이스 수를 저장
	readFile >> T;

	// 각 숫자를 입력받고, 처리 후 저장함.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// 입력
		int degree; // 각도
		readFile >> degree; // 입력
		
		// 처리
		string result = ""; // 결과를 출력할 str 변수
		int hh = degree / 30; // hh를 저장할 변수. 30degree 당 1시간
		int mm = degree % 30 * 2; // mm를 저장할 변수. 1degree 당 2분

		result += to_string(hh); // hh 추가
		result += " "; // hh과 mm를 구분할 공백 추가
		result += to_string(mm); // mm 추가
		
		// 결과 출력
		cout << "#" << test_case << " " << hh << " " << mm << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}