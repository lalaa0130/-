// clambing.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include"path.h"


int main()
{
	C_PATH cPath{};
	cPath.inputPath("{ [1, 2, 3] , [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]}");

	cPath.print();
	cPath.inputGate(2, 1,3);
	cPath.inputSummits(1, 5);
	cPath.run();
}

