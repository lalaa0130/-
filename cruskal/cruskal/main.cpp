// cruskal.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include"kruskal.h"


int main()
{
	C_KRUSKAL cKruskal{};

	cKruskal.add(7,4,13);
	cKruskal.add(7, 1, 12);
	cKruskal.add(7, 5, 73);
	cKruskal.add(4, 1, 28);
	cKruskal.add(4, 2, 24);
	cKruskal.add(2, 1, 67);
	cKruskal.add(1, 5, 17);
	cKruskal.add(2, 5, 62);
	cKruskal.add(5, 6, 45);
	cKruskal.add(5, 3, 20);
	cKruskal.add(6, 3, 37);

	cKruskal.makeKruskalNode();
	//cKruskal.print();
}

