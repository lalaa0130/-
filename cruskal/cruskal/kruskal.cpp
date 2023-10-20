#include "kruskal.h"

void C_KRUSKAL::swap(int& nDst, int& nSrc)
{
	int nTmp = nDst;
	nDst = nSrc;
	nSrc = nTmp;

}

void C_KRUSKAL::add(int nDst, int nSrc, int nLength)
{
	auto DstResult = insertNode(nDst);
	auto SrcResult = insertNode(nSrc);


	DstResult->mapChildren.insert({SrcResult, nLength });

	SrcResult->mapChildren.insert({ DstResult, nLength });
}

C_KRUSKAL::S_NODE* C_KRUSKAL::insertNode(int nId)
{
	auto pairResultDst = m_mapGraph.insert({ nId,nullptr });

	if (pairResultDst.second)
	{
		pairResultDst.first->second = new S_NODE{ nId };
	}
	return pairResultDst.first->second;
}

void C_KRUSKAL::makeKruskalNode()
{
	for (auto node : m_mapGraph)
	{
		for (auto childrenNode : node.second->mapChildren)
		{
			int nId1 = node.first;
			int nId2 = childrenNode.first->nId;

			if (nId1 > nId2)
				swap(nId1, nId2);


			auto pairResult = m_mapkruskal.insert({ nId1,{nId2} });
			if (!pairResult.second)
			{
				pairResult.first->second.insert({nId2});

			}


		}

	}

	S_NODE* pParent{};
	S_NODE* pChild{};
	std::priority_queue<S_KRUSKAL, std::vector<S_KRUSKAL>, S_KRUSKAL> queue{};

	for (auto iter : m_mapkruskal)
	{
		pParent = m_mapGraph.find(iter.first)->second;
		for (int nId : iter.second )
		{
			pChild = m_mapGraph.find(nId)->second;
			int nLength = pParent->mapChildren.find(pChild)->second;
			queue.push({ pParent,pChild ,nLength});
		}
	}


	while(!queue.empty())
	{
		S_KRUSKAL sKruskal = queue.top();
		queue.pop();

		if (sKruskal.p1->pParent && sKruskal.p2->pParent)
		{
			printf("연결안함\n");
		}
		else
		{
			S_NODE* pParent = sKruskal.p1->pParent;
			if (sKruskal.p2->pParent)
				pParent = sKruskal.p2->pParent;

			if (!pParent)
				pParent = sKruskal.p1;

			sKruskal.p1->pParent = sKruskal.p2->pParent = pParent;

		}



	}

}

void C_KRUSKAL::print()
{
	for (auto node : m_mapGraph)
	{
		printf("ID %d: ", node.first);
		KRUS(node.second);
	}
}

void C_KRUSKAL::KRUS(S_NODE * pNode)
{
	printf("자식: ");
		for (auto node : pNode->mapChildren)
		{
			printf("%d ", node.second);
		}
		printf("\n");
}

bool C_KRUSKAL::S_KRUSKAL::operator()(S_KRUSKAL sDst, S_KRUSKAL sSrc)
{
	return sDst.nLength> sSrc.nLength;
}
