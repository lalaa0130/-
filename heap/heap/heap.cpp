#include "heap.h"

void C_HEAP::init()
{
    m_heapBuffer.push_back({});
}

void C_HEAP::add(S_NODE* pNode)
{
    int nId = (int)m_heapBuffer.size();

    pNode->nId = nId;
    m_heapBuffer.push_back({ pNode });

    nodeUp(nId, nId / 2);
}

void C_HEAP::nodeUp(int nId, int nUp)
{
    if (nUp == 0 || (m_heapBuffer[nUp].pNode->nData < m_heapBuffer[nId].pNode->nData))
        return;

    nodeSwap(nUp, nId);
    nodeUp(nUp , nUp / 2);
}

void C_HEAP::nodeSwap(int nId1, int nId2)
{
    swap(m_heapBuffer[nId1].pNode, m_heapBuffer[nId2].pNode);
    m_heapBuffer[nId1].pNode->nId = nId1;
    m_heapBuffer[nId2].pNode->nId = nId2;
}


void C_HEAP::print()
{
    for (int i = 1; i < m_heapBuffer.size(); i++)
    {
        printf("%d ", m_heapBuffer[i].pNode->nData);
    }
    printf("\n");
}

S_NODE* C_HEAP::top()
{
    return m_heapBuffer[1].pNode;
}

void C_HEAP::pop()
{
    if (m_heapBuffer.size() <= 1)
        return;

    int nLastIndex = (int)m_heapBuffer.size() - 1;
    nodeSwap(1, nLastIndex);
    m_heapBuffer[1].pNode->nId = 0;
    m_heapBuffer.pop_back();

    nodeDown(1, 2, 3);
}

void C_HEAP::changeData(int nChangeId, int nChangeData)
{
    nodeUpVerTwo(nChangeId);
    pop();
    add(new S_NODE{nChangeData});

}

void C_HEAP::nodeDown(int nId, int nL, int nR)
{
    int nLastIndex = (int)m_heapBuffer.size() - 1;
    if (nL > nLastIndex)
        return;

    int nSelect = nL;
    if (nR <= nLastIndex && m_heapBuffer[nL].pNode->nData > m_heapBuffer[nR].pNode->nData)
        nSelect = nR;

    if (m_heapBuffer[nId].pNode->nData < m_heapBuffer[nSelect].pNode->nData)
        return;

    nodeSwap(nId, nSelect);
    nodeDown(nSelect, nSelect * 2, nSelect * 2 + 1);
}

void C_HEAP::nodeUpVerTwo(int nId)
{
    int nUp = nId / 2;
    while (nUp >= 1)
    {
        nodeSwap(nId, nUp);
        nId = nUp;
        nUp /= 2;
    }
}

C_HEAP::S_HEAP* C_HEAP::getParent(S_HEAP* heap)
{
    int nUpId = heap->pNode->nId / 2;
    return &m_heapBuffer[nUpId];
}
