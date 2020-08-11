/*
... iss Crew
... Made By Mukho
... 2020-08-11 TUE
... 1926 D2

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PTeo6AHUDFAUq&categoryId=AV5PTeo6AHUDFAUq&categoryType=CODE
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int test_case; // 테스트할 테스트의 번호를 저장할 변수
	int N; // 정수 N

	// test case를 불러올 파일 객체 열기
	ifstream readFile;
	readFile.open("input.txt");

	// 정수를 저장
	readFile >> N;

	// 각 숫자를 입력받고, 처리 후 저장함.
	for (test_case = 1; test_case <= N; ++test_case)
	{
		// 처리, 결과 출력
		int temp = test_case; // 숫자를 계산하기 위한 임시 변수
		int count = 0; // 박수칠 횟수를 저장할 변수

		while (temp != 0) // 앞자리부터 숫자 확인
		{
			if (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9) // 해당 자리수가 3, 6, 9일 경우
				count++; // 박수칠 횟수 1 증가
			temp /= 10; // 다음 자리수로 변경
		}

		// 단계가 바뀔 때 마다 공백 출력
		if (test_case > 1)
			cout << ' ';

		// 3, 6, 9가 없을 경우 해당 숫자를 출력
		if (count == 0)
			cout << test_case;
		// 3, 6, 9가 있을 경우 해당 개수만큼 박수('-')를 출력
		else
			for (int i = 0; i < count; i++)
				cout << '-';
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}