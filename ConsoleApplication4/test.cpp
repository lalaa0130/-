#include <iostream>
#include <list>
#include "test.h"



void C_TEST::inputPath(const char* strPath)
{
	std::list<int> listData{};
	int nData{};
	bool bRead = false;
	int nIndex{};
	for (const char* p = strPath; *p != '\0'; p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			bRead = true;
			nData = nData * 10 + *p - '0';
		}
		else
		{
			if (bRead)
			{
				nIndex++;
				if (nIndex == 3)
					nIndex = 0;
				else if (m_nLength < nData)
					m_nLength = nData;

				listData.push_back(nData);

				bRead = false;
				nData = 0;
			}
		}
	}

	m_nLength++;
	m_ppNode = new int* [m_nLength] {};
	for (int i = 0; i < m_nLength; i++)
	{
		m_ppNode[i] = new int[m_nLength] {};
	}

	m_pNodeInfo = new S_NODE[m_nLength]{};
	auto iter = listData.begin();
	while(iter != listData.end())
	{
		int nDst = *iter;
		iter++;
		int nSrc = *iter;
		iter++;
		int nLength = *iter;
		iter++;

		m_ppNode[nDst][nSrc] = nLength;
		m_ppNode[nSrc][nDst] = nLength;

		m_pNodeInfo[nDst].eState = E_NODE;
		m_pNodeInfo[nSrc].eState = E_NODE;
	}
}

void C_TEST::inputGates(int nCount, ...)
{
	va_list argP{};
	__va_start(&argP, nCount);
	intputArg(E_GATE, nCount, argP);
	__crt_va_end(argP);
}

void C_TEST::inputSummits(int nCount, ...)
{
	va_list argP{};
	__va_start(&argP, nCount);
	intputArg(E_SUMMIT, nCount, argP);
	__crt_va_end(argP);
}

void C_TEST::intputArg(E_STATE eState, int nCount, va_list argP)
{
	for (int i = 0; i < nCount; i++)
	{
		int nData = __crt_va_arg(argP, int);
		m_pNodeInfo[nData].eState = eState;
	}
}

void C_TEST::traversal(int nId , int nParent)
{
	for (int i = 0; i < m_nLength; i++)
	{
		if (m_pNodeInfo[i].eState == E_SUMMIT)
		{
			printf("%d ", m_ppNode[nId][i]);
			printf("µµÂø \n");
		}
		else if (m_ppNode[nId][i] != 0 && !m_pNodeInfo[i].isVisit && i != nParent)
		{
			printf("%d ", m_ppNode[nId][i]);
			traversal(i , nId);
		}
	}
	m_pNodeInfo[nId].isVisit = true;
}

void C_TEST::print()
{
	for (int i = 0; i < m_nLength; i++)
	{
		for (int j = 0; j < m_nLength; j++)
		{
			printf("%2d ", m_ppNode[i][j]);
		}
		printf("\n");
	}
}

void C_TEST::run()
{
	for (int i = 0; i < m_nLength; i++)
	{
		printf("%d ", m_pNodeInfo[i].eState);
	}
	printf("\n");

	int nNode = 1;
	m_pNodeInfo[3].isVisit = true;

	traversal(1 , 1);
}

