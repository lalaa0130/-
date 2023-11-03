#pragma once

class C_TEST
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
	};

private:
	int** m_ppNode;
	S_NODE* m_pNodeInfo;
	int m_nLength;

private: 
	void intputArg(E_STATE eState, int nCount, va_list argP);
	void traversal(int nId , int nParent);

public:
	C_TEST() = default;
	void inputPath(const char* strPath);
	void inputGates(int nCount , ...);
	void inputSummits(int nCount, ...);
	void print();
	void run();
};