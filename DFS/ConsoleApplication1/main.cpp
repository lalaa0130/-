// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include"graph.h"


int main()
{
	C_GRAPH cGraph{};

	cGraph.create(0);
	cGraph.create(100);
	cGraph.create(200);
	cGraph.create(300);
	cGraph.create(400);
	cGraph.create(500);
	cGraph.create(600);
	cGraph.create(700);
	cGraph.create(800);

	if (!cGraph.create(0))
		printf("fail\n");

	cGraph.linkNode(0, 100);
	cGraph.linkNode(200, 100);
	cGraph.linkNode(200, 300);
	cGraph.linkNode(200, 400);
	cGraph.linkNode(300, 100);
	cGraph.linkNode(300, 400);
	cGraph.linkNode(300, 500);
	cGraph.linkNode(500, 700);
	cGraph.linkNode(500, 600);
	cGraph.linkNode(800, 600);


	//cGraph.print();
	cGraph.DFS(100);
}



