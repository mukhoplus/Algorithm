/*
... iss Crew
... Made By Mukho
... 2020-08-12 WEN
... 10505 D3

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXNP4CvauaMDFAXS&categoryId=AXNP4CvauaMDFAXS&categoryType=CODE*/

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
		int N; // 정수의 개수
		readFile >> N;

		// N 크기의 int형 배열 동적할당
		int* arr;
		arr = new int[N];
		int temp = 0 ;//  평균 소득을 계산하기 위해 사용할 임시변수

		// N만큼 입력 받음
		for (int i = 0; i < N; i++)
		{
			readFile >> arr[i];
			temp += arr[i];
		}

		// 처리
		double avg = temp / N; // 평균 소득
		int count = 0; // 평균 소득 이하를 세기 위한 변수

		// 평균 이하의 소득을 가진 사람들의 수 출력
		for (int i = 0; i < N; i++)
			if (arr[i] <= avg)
				count++;

		// 결과 출력
		cout << "#" << test_case << " " << count << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}