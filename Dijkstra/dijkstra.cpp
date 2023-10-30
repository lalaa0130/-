#include "dijkstra.h"

C_DIJKSTRA::S_NODE* C_DIJKSTRA::createNode(int nId)
{
	S_NODE* pNode = new S_NODE{};
	pNode->nId = nId;
	return pNode;
}

C_DIJKSTRA::S_NODE* C_DIJKSTRA::newNode(int nId)
{
	auto pairResult = m_mapNode.insert({ nId, nullptr });
	S_NODE* pNode{};
	if (pairResult.second)
	{
		pairResult.first->second = createNode(nId);
	}
	pNode = pairResult.first->second;

	return pNode;
}

C_DIJKSTRA::S_NODE* C_DIJKSTRA::popMinNode(std::list<S_NODE*>& list)
{
	auto iter = list.begin();
	auto iterMin = iter;
	iter++;
	S_NODE* pMinNode = *iterMin;
	while (iter != list.end())
	{
		if (pMinNode->nTotalLength > (*iter)->nTotalLength)
		{
			iterMin = iter;
		}
		iter++;
	}

	pMinNode = *iterMin;
	list.erase(iterMin);
	return pMinNode;
}

void C_DIJKSTRA::addNode(int nDst, int nSrc, int nLength)
{
	S_NODE* pDstNode = newNode(nDst);
	S_NODE* pSrcNode = newNode(nSrc);

	pDstNode->children.insert({ pSrcNode,nLength });
	pSrcNode->children.insert({ pDstNode,nLength });

}


void C_DIJKSTRA::print()
{
	for (auto iter : m_mapNode)
	{
		for ( auto node : iter.second->children)
		{
			printf("%d : ( %d , %d )",iter.first,node.first->nId,node.second);
		}
		printf("\n");
	}


}

void C_DIJKSTRA::printNode(int nId)
{
	auto node = m_mapNode.find(nId);
	int nLength = node->second->children.begin()->second;
	S_NODE* pMinNode = node->second;

	for (auto iter : node->second->children)
	{
		if (nLength > iter.second)
		{
			nLength = iter.second;
			pMinNode = iter.first;
		}
	}
	printf("%d : ( %d , %d )\n", nId, pMinNode->nId, nLength);

}

void C_DIJKSTRA::make(int nStart , int nEnd)
{
	S_NODE* pParent{};
S_NODE* pNode = m_mapNode.find(nStart)->second;

std::list<S_NODE*> listNode;
listNode.push_back(pNode);
pNode->isLogic = true;

while (!listNode.empty())
{
	//가장 작은 노드를 찾는다

	//child 순회 방문한적 이면 pass, isLogic이면 거리계산해서 총거리 비교 작으면 교체 

	S_NODE* pMinNode = popMinNode(listNode);

	pMinNode->isVisit = true;


	////방문 입력
	for (auto child : pMinNode->children)
	{
		S_NODE* pChildNode = child.first;
		int nChildLength = child.second + pMinNode->nTotalLength;
		/*if (!pChildNode->isVisit && !pChildNode->isLogic || pChildNode->nTotalLength > nChildLength)
		{
			if (!pChildNode->isLogic)
				listNode.push_back(pChildNode);

			pChildNode->pParent = pMinNode;
			pChildNode->nTotalLength = nChildLength;
			pChildNode->isLogic = true;
		}*/

		if (!pChildNode->isVisit)
		{
			if (!pChildNode->isLogic)
				listNode.push_back(pChildNode);

			if (pChildNode->nTotalLength == 0 || pChildNode->nTotalLength > nChildLength)
			{
				pChildNode->nTotalLength = nChildLength;
				pChildNode->pParent = pMinNode;
			}
			pChildNode->isLogic = true;

		}
	}
		
}

S_NODE* pEndNode = m_mapNode.find(nEnd)->second;
while (pEndNode)
{
	printf("%d ", pEndNode->nId);
	pEndNode = pEndNode->pParent;
}



}
