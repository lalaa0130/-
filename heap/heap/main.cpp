// heap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "heap.h"

int main()
{
	C_HEAP cHeap{};

	cHeap.init();

	cHeap.add(new S_NODE{ 2 });
	cHeap.add(new S_NODE{ 8 });
	cHeap.add(new S_NODE{ 6 });
	S_NODE* pNode = new S_NODE{ 14};
	cHeap.add(pNode);
	printf("%d,%d\n", pNode->nData, pNode->nId);
	cHeap.add(new S_NODE{ 12});
	cHeap.add(new S_NODE{ 18});
	cHeap.add(new S_NODE{ 10});
	cHeap.add(new S_NODE{ 4 });
	cHeap.add(new S_NODE{ 16});
	//1 2 4 3 7 9 5 6 8
	cHeap.print();
	printf("%d,%d\n", pNode->nData, pNode->nId);

	cHeap.changeData(5, 3);
	cHeap.print();

	for (int i = 0; i < 9; i++)
	{
		cHeap.pop();
		cHeap.print();
	}
	//2 3 6 4 16 18 10 14 8

}

