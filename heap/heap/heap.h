#pragma once

#include <vector>

struct S_NODE
{
	int nData;

	int nId;
};

class C_HEAP
{
private:
	struct S_HEAP
	{
		S_NODE* pNode;
	};

private:
	std::vector<S_HEAP> m_heapBuffer;

	template<typename T>
	void swap(T& t1, T& t2);

private:
	void nodeUp(int nId , int nUp);
	void nodeSwap(int nId1 , int nId2);
	void nodeDown(int nId, int nL, int nR);
	void nodeUpVerTwo(int nId);
	S_HEAP* getParent(S_HEAP* heap);
public:
	C_HEAP() = default;
	void init();
	void add(S_NODE *pNode);
	void print();
	S_NODE* top();
	void pop();
	void changeData(int nChangeId, int nChangeData);
};

template<typename T>
inline void C_HEAP::swap(T& t1, T& t2)
{
	T t = t1; t1 = t2; t2 = t;
}
