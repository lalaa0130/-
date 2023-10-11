#pragma once
#include<stdio.h>

class C_GRAPH
{
private:
	bool m_arData[8][8];

public:
	C_GRAPH();
	void BFS(int nId);
	void print();
};