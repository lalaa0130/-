#pragma once
#include<map>
#include<set>
#include<stdio.h>
#include<queue>

class C_KRUSKAL
{
private:
	struct S_NODE
	{
		int nId;
		std::map<S_NODE*, int> mapChildren;
		S_NODE* pParent;
	};

	struct S_KRUSKAL
	{
		S_NODE* p1;
		S_NODE* p2;
		int nLength;
		bool operator()(S_KRUSKAL sDst, S_KRUSKAL sSrc);
	};
private:
	std::map<int, S_NODE*> m_mapGraph;
	std::map<int, std::set<int>> m_mapkruskal;

	void swap(int& nDst, int& nSrc);

public:
	C_KRUSKAL() = default;
	void add(int nDst, int nSrc, int nLength);
	S_NODE* insertNode(int nId);
	void makeKruskalNode();
	void print();
	void KRUS(S_NODE* pNode);
};