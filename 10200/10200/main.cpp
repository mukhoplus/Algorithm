/*
... iss Crew
... Made By Mukho
... 2020-08-04 TUE
... 10200 D3

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXMCXV_qVgkDFAWv&categoryId=AXMCXV_qVgkDFAWv&categoryType=CODE
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int totalCase; // 전체 test case 수
	
	// test case를 불러올 파일 객체 열기
	ifstream readFile;
	readFile.open("sample_input.txt");

	// 결과를 저장할 파일 객체 열기
	ofstream writeFile;
	writeFile.open("sample_output.txt");

	// 전체 테스트 케이스 수를 저장
	readFile >> totalCase;

	// 각 숫자를 입력받고, 처리 후 저장함.
	for (int i = 1; i <= totalCase; i++)
	{
		// 입력
		int subCase, numA, numB; // 인원 수, A 구독자 수, B 구독자 수
		readFile >> subCase >> numA >> numB;

		// 처리
		int resultMax, resultMin; // 최대 중복 구독자 수, 최소 중복 구독자 수
		resultMax = numA > numB ? numB : numA; // 최대 중복 구독자 수 = 두 숫자 중 작은 숫자

		// 최소 중복 구독자 수
		if ((numA + numB) > subCase)
			resultMin = (numA + numB) - subCase;
		else
			resultMin = 0;
		
		// 저장
		writeFile << "#" << i << " " << resultMax << " " << resultMin << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	writeFile.close();
	return 0;
}