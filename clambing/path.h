#pragma once

#include<iostream>

class C_PATH
{
private:
	enum E_STATE
	{
		E_NULL,
		E_NODE,
		E_GATE,
		E_SUMMIT
	};

private:
	struct S_NODE
	{
		bool isVisit;
		E_STATE eState;
		int nMaxLength;
		bool isRoot;
	};

private:
	int m_nGateCount;
	int m_nLength;
	S_NODE* m_pNodeInfo;
	int** m_ppNode;




public:
	C_PATH() = default;
	void inputPath(const char* strPath);
	void inputGate(int nCount, ...);
	void inputSummits(int nCounts, ...);

	void print();
	void findPath(int nId,int nRootId);
	void run();
	void cleanup();
};