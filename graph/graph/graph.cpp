#include "graph.h"
#include<queue>

C_GRAPH::C_GRAPH() : 
	m_arData{
		{0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0,0},
		{0,1,0,0,1,1,0,0},
		{0,1,0,0,1,0,1,0},
		{0,0,1,1,0,1,0,1},
		{0,0,1,0,1,0,0,1},
		{0,0,0,1,0,0,0,1},
		{0,0,0,0,1,1,1,0}}
{
}

void C_GRAPH::BFS(int nId)
{
	bool isPush[8]{};
	std::queue<int> queBuffer{};
	std::queue<int> queResult{};


	queBuffer.push(nId);
	isPush[nId] = true;

	while (!queBuffer.empty())
	{
		int nCount = queBuffer.size();

		for (int i = 0; i < nCount; i++)
		{

			int nId = queBuffer.front();
			queResult.push(nId);
			queBuffer.pop();

			for (int i = 1; i < 8; i++)
			{
				if (m_arData[nId][i]&& !isPush[i])
				{
					queBuffer.push(i);
					isPush[i] = true;
				}

			}
		}
		printf("±íÀÌ\n");
	}

	while (!queResult.empty())
	{
		printf("%d ", queResult.front());
		queResult.pop();
	}
}

void C_GRAPH::print()
{

}
