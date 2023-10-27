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

void C_DIJKSTRA::make(int nId)
{
	S_NODE* pParent{};
	S_NODE* pNode = m_mapNode.find(nId)->second;

	std::list<S_NODE*> listNode;
	listNode.push_back(pNode);
	pNode->isLogic = true;

	while (!listNode.empty())
	{
		//���� ���� ��带 ã�´�

		//child ��ȸ �湮���� �̸� pass, isLogic�̸� �Ÿ�����ؼ� �ѰŸ� �� ������ ��ü 

		S_NODE* pMinNode = popMinNode(listNode);

		pMinNode->isVisit = true;

		//�ش� ��带 ǥ��
		//pMinNode->nTotalLength += MinPair->second;
		//pMinNode->isLogic = true;

		//// �θ��� �Է�
		//pMinNode->pParent = pNode;

		////�湮 �Է�
		for (auto child : pNode->children)
		{
			if (child.first->isVisit)
			{}
			else if (child.first->isLogic)
			{
				if (child.first->nTotalLength > (pMinNode->nTotalLength+ child.second))
					child.first->pParent = pMinNode;
			}
			else
			{
				child.first->isLogic = true;
				listNode.push_back(child.first);
			}
		}
			
	}


}
