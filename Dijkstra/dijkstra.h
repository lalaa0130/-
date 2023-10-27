#pragma once

#include<map>
#include<iostream>
#include<list>

class C_DIJKSTRA
{
private:
	struct S_NODE
	{
		int nId;
		std::map<S_NODE* , int> children;
	
		bool isVisit;
		bool isLogic;
		S_NODE* pParent;
		int nTotalLength;
	};


private:
	std::map<int, S_NODE*> m_mapNode;
	S_NODE* createNode(int nId);
	S_NODE* newNode(int nId);
	S_NODE* popMinNode(std::list<S_NODE*>& list);

public:
	C_DIJKSTRA() = default;

	void addNode(int nDst, int nSrc, int nLength);
	void print();
	void printNode(int nId);

	void make(int nId);

};