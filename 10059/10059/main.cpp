/*
... iss Crew
... Made By Mukho
... 2020-08-05 WEN
... 10059 D3

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXK6YRNaKq0DFAU3&categoryId=AXK6YRNaKq0DFAU3&categoryType=CODE
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int totalCase; // 전체 test case 수

	// test case를 불러올 파일 객체 열기
	ifstream readFile;
	readFile.open("sample_input.txt");

	// 전체 테스트 케이스 수를 저장
	readFile >> totalCase;

	// 각 숫자를 입력받고, 처리 후 저장함.
	for (int i = 1; i <= totalCase; i++)
	{
		// 입력
		string number; // 4자리 숫자를 입력받을 변수
		readFile >> number; // 파일에서 4자리 변수를 불러와 저장

		int dateArr[2] = {}; // 앞 2자리와 뒷 2자리를 처리할 배열
		string temp = ""; // 문자열을 정수로 바꾸기 전 저장할 임시 배열
		// 앞 2자리 저장 후 int형으로 저장
		temp += number[0];
		temp += number[1];
		dateArr[0] = stoi(temp);

		temp = "";
		// 뒷 2자리 저장 후 int형으로 저장
		temp += number[2];
		temp += number[3];
		dateArr[1] = stoi(temp);

		// 처리
		bool firstCanMM = false, secondCanMM = false; // 각 숫자가 MM 표기가 가능한지 알려주는 boolean 변수
		string result; // 결과를 출력할 변수

		// MM 표기가 가능한가?
		if (dateArr[0] >= 1 && dateArr[0] <= 12)
			firstCanMM = true;
		if (dateArr[1] >= 1 && dateArr[1] <= 12)
			secondCanMM = true;

		if (firstCanMM == true && secondCanMM == true)
			result = "AMBIGUOUS";
		else if (firstCanMM == true && secondCanMM == false)
			result = "MMYY";
		else if (firstCanMM == false && secondCanMM == true)
			result = "YYMM";
		else
			result = "NA";

		// 결과 출력
		cout << "#" << i << " " << result << endl;
	}

	// 파일 객체 닫기
	readFile.close();
	return 0;
}