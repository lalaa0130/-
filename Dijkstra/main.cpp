
#include <iostream>
#include"dijkstra.h"

int main()
{
	C_DIJKSTRA cDijkstra{};

	cDijkstra.addNode(1, 2, 3);
	cDijkstra.addNode(1, 3, 4);
	cDijkstra.addNode(3, 2, 5);
	cDijkstra.addNode(2, 4, 10);
	cDijkstra.addNode(4, 3, 8);
	cDijkstra.addNode(5, 3, 5);
	cDijkstra.addNode(4, 5, 6);
	cDijkstra.addNode(5, 7, 4);
	cDijkstra.addNode(4, 7, 7);
	cDijkstra.addNode(2, 6, 9);
	cDijkstra.addNode(4, 6, 10);
	cDijkstra.addNode(4, 8, 3);
	cDijkstra.addNode(7, 8, 5);
	cDijkstra.addNode(6, 8, 2);

	cDijkstra.print();
	cDijkstra.make(1,6);
}

