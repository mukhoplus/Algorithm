/*
... iss Crew
... Made By Mukho
... 2020-08-15 SAT
... 7829 D4

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWtInr3auH0DFASy&categoryId=AWtInr3auH0DFASy&categoryType=CODE
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
		int result; // 결과
		int P; // test case 약수의 개수
		readFile >> P;
		
		vector<int> arr; // 약수를 입력받을 vecter
		for (int i = 0; i < P; i++)
		{
			int temp; // 입력용 임시 변수
			readFile >> temp;  // 입력
			arr.push_back(temp); // vector에 삽입
		}
		sort(arr.begin(), arr.end()); // 정렬

		// 처리
		if (P % 2 != 0) // 약수의 개수가 홀수이면, 
			result = arr[(P - 1) / 2] * arr[(P - 1) / 2]; // 정중앙의 정수 제곱
		else // 약수의 개수가 홀수이면
			result = arr[0] * arr[P-1]; // 맨 앞과 맨 뒤의 정수 곱

		// 결과 출력
		cout << "#" << test_case << " " << result << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}