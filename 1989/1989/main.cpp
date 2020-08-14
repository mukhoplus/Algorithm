/*
... iss Crew
... Made By Mukho
... 2020-08-14 FRI
... 1989 D2

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PyTLqAf4DFAUq&categoryId=AV5PyTLqAf4DFAUq&categoryType=CODE
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
		string input; // 테스트 케이스를 저장할 문자열
		readFile >> input; // 입력

		// 처리
		int result = 1; // 결과 출력용 변수. 회문이면 1, 회문이 아니면 0
		int size = input.size() - 1; // 회문 검사용 변수

		for (int i = 0; i < signed(input.size() / 2); i++)
		{
			if (input[i] == input[size]) // 같으면 계속 비교
				size--;
			else // 회문이 아닌 경우 반복문을 탈출하고 result를 0으로 바꿈
			{
				result = 0;
				break;
			}
		}
		// 결과 출력
		cout << "#" << test_case << " " << result << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}