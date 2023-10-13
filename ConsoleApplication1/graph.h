#pragma once
#include<set>
#include<map>
#include<stdio.h>


class C_GRAPH
{
public:
	struct S_NODE
	{
		int nId;
		std::set<S_NODE*> setChild;
		bool isVisit;
	};

private:
	std::map<int, S_NODE*> m_mapNode;

private:
	void printNode(S_NODE* pNode);

public:
	C_GRAPH() = default;
	bool create(int nId);
	bool linkNode(int nIdDst,int nIdSrc);
	void DFS(int nId);
	void print();

};
