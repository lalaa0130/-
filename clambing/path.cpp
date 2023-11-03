#include "path.h"
#include <list>

void C_PATH::inputPath(const char* strPath)
{
	std::list<int> listData{};
	int nData{};
	bool isRead = false;

	int nIndex{};
	for (const char* p = strPath; *p != '\0'; p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			isRead = true;
			nData = nData * 10 + (*p - '0');
		}
		else
		{
			if (isRead)
			{
				nIndex++;
				if (nIndex == 3)
				{
					nIndex = 0;
				}
				else if (m_nLength < nData)
					m_nLength = nData;

				listData.push_back(nData);

				//printf("%d\n", nData);
				nData = 0;
				isRead = false;
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
	while (iter != listData.end())
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

void C_PATH::inputGate(int nCount, ...)
{
	m_nGateCount = nCount;
	va_list argP{};
	__va_start(&argP, nCount);
	for (int i = 0; i < nCount; i++)
	{
		int nData = __crt_va_arg(argP, int);
		printf("%d ", nData);
		m_pNodeInfo[nData].eState = E_GATE;
	}
	printf("\n");
	
	__crt_va_end(argP);
}

void C_PATH::inputSummits(int nCounts, ...)
{
	va_list argP{};
	__va_start(&argP, nCounts);
	for (int i = 0; i < nCounts; i++)
	{
		int nData = __crt_va_arg(argP, int);
		printf("%d ", nData);
		m_pNodeInfo[nData].eState = E_SUMMIT;
	}
	printf("\n");

	__crt_va_end(argP);
}


void C_PATH::print()
{
	for (int i = 0; i < m_nLength; i++)
	{
		for (int j = 0; j < m_nLength; j++)
		{
			printf("%2d", m_ppNode[i][j]);
		}
		printf("\n");
	}


}


void C_PATH::findPath(int nId, int nRootId)
{
	if (m_pNodeInfo[nId].eState == E_SUMMIT)
	{
		printf("max Intensity: %d\n", m_pNodeInfo[nId].nMaxLength);
		return;
	}

	for (int j = 0; j < m_nLength; j++)
	{
		if (m_ppNode[nId][j] != 0)
		{
			if (nId == nRootId)
			{
				m_pNodeInfo[j].isVisit = false;
				m_pNodeInfo[nId].nMaxLength = m_ppNode[nId][j];
			}
			if (!m_pNodeInfo[j].isVisit && m_pNodeInfo[j].eState == E_NODE || m_pNodeInfo[j].eState == E_SUMMIT && m_pNodeInfo[j].eState != E_GATE)
			{
				m_pNodeInfo[j].isVisit = true;
				//자식노드 순회  
				m_pNodeInfo[j].nMaxLength = m_pNodeInfo[nId].nMaxLength;
				if (m_ppNode[nId][j] > m_pNodeInfo[nId].nMaxLength)
				{
					m_pNodeInfo[j].nMaxLength = m_ppNode[nId][j];
					m_pNodeInfo[nId].nMaxLength = m_ppNode[nId][j];
				}
				printf("%d -> ", j);
				findPath(j,nRootId);
			}
		}
	}
}

void C_PATH::run()
{
	for (int i = 0; i < m_nLength; i++)
	{
		if (m_pNodeInfo[i].eState == E_GATE)
		{
			
				cleanup();
				printf("Gate %d : ", i);
				findPath(i,i);
		}
	}


}

void C_PATH::cleanup()
{
	for (int i = 0; i < m_nLength; i++)
	{
		m_pNodeInfo[i].isVisit = false;
		m_pNodeInfo[i].nMaxLength = 0;
	}
}
