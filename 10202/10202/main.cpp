/*
... iss Crew
... Made By Mukho
... 2020-08-07 FRI
... 10202 D5

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXMCa8EaVioDFAWv&categoryId=AXMCa8EaVioDFAWv&categoryType=CODE
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
		int stringNum; // 글자 수
		string strA, strB, strC; // 입력받을 글자를 저장할 string 변수 3개
		readFile >> stringNum >> strA >> strB >> strC; // 입력

		// 처리
		int count = 0; // 몇회 교환하면 전부 같은 문자열이 되는지 저장하는 변수
		
		for (int i = 0; i < stringNum; i++)
		{
			bool isSameAB = true;
			bool isSameAC = true;
			bool isSameBC = true;

			// 각 자릿수의 문자가 다르면 count를 1 증가시킴.
			if (strA[i] != strB[i])
				isSameAB = false;
			if (strA[i] != strC[i])
				isSameAC = false;
			if (strB[i] != strC[i])
				isSameBC = false;

			if (isSameAB && isSameAC && isSameBC) // 전부 같은 경우(TTT or TT*, *는 삼단논법에 의해 T)
				continue; // 바꿀 필요가 없음.
			else if (!isSameAB && !isSameAC && !isSameBC) // 전부 다른 경우(FFF or FF*, *는 삼단논법에 의해 F)
				count += 2; // 2개의 문자를 바꿔줘야 함.
			else // 2개의 문자가 같고 1개만 문자가 다른 경우(TFF)
				count += 1; // 1개의 문자를 바꿔줘야 함.
		}

		// 결과 출력
		cout << "#" << test_case << " " << count << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}