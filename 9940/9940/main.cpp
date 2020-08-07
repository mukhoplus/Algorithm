/*
... iss Crew
... Made By Mukho
... 2020-08-07 FRI
... 9940 D3

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXHx23oq0REDFAXR&categoryId=AXHx23oq0REDFAXR&categoryType=CODE
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
		int N; // n번째 테스트 케이스
		readFile >> N; // 입력
		string result = "Yes"; // 결과를 출력할 str 변수. 수열이면 Yes, 아니면 No(default).
		int sum = 0; // 수열의 합을 계산할 변수
		int* sy = new int[N]; // 수열 동적할당

		// 처리
		// 최적화를 위한 마지막 몸부림 || 하아.. 왜 loop 탈출하면 정답이 아닌건데?
		for (int i = 0; i < N; i++)
		{
			readFile >> sy[i]; // 수열에 N만큼 숫자 입력
			sum += sy[i];
			if (sy[i] < 1 || sy[i] > N)
				result = "No";
		}
		if (sum != (N * (N + 1) / 2))
			result = "No";

		// 결과 출력
		cout << "#" << test_case << " " << result << endl;
		delete []sy;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}