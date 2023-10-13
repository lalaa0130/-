#include "graph.h"


bool C_GRAPH::create(int nId)
{
    auto pairResult = m_mapNode.insert({nId,nullptr});
    
    if (!pairResult.second)
        return false;

    pairResult.first->second = new S_NODE{ nId,{} };
    return true;

}

bool C_GRAPH::linkNode(int nIdDst, int nIdSrc)
{
    auto iterDst = m_mapNode.find(nIdDst);
    auto iterSrc = m_mapNode.find(nIdSrc);


    if (iterDst == m_mapNode.end() || iterSrc == m_mapNode.end())
        return false;


    if (iterDst->second->setChild.find(iterSrc->second) != iterDst->second->setChild.end())
        return false;


    iterDst->second->setChild.insert(iterSrc->second);
    iterSrc->second->setChild.insert(iterDst->second);

    return true;
}

void C_GRAPH::printNode(S_NODE* pNode)
{
    if (pNode->isVisit)
    {
        return;
    }
    printf("%d ", pNode->nId);
    pNode->isVisit = true;

    for (S_NODE* pChild : pNode->setChild)
    {
        printNode(pChild);
    }
}

void C_GRAPH::DFS(int nId)
{
    S_NODE* pNode = m_mapNode.find(nId)->second;

    printNode(pNode);
}

void C_GRAPH::print()
{
    for (auto node: m_mapNode)
    {
        printf("%d ", node.first);
        printf("children: ");
        for (S_NODE* pNode : node.second->setChild)
        {
            printf("%d ", pNode->nId);
        }
        printf("\n");
    }

}
