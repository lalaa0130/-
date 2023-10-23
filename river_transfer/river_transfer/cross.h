#pragma once


class C_CROSS
{
public:
	enum
	{
		E_NULL		= 0x00,
		E_CABBAGE	= 0x01,
		E_GOAT		= 0x02,
		E_WOLF		= 0x04,
		E_FAMER		= 0x08,
		E_REVERSE	= 0x0F,
		E_MAX		= 0x10
	};

	struct S_LAND
	{
		int nLand;
		bool arMove[E_MAX];
	};

private:
	bool m_arBlock[E_MAX];
	const char* m_arObjectTable[4];

	S_LAND m_nLandA;
	S_LAND m_nLandB;

	bool m_arMoveA[E_MAX];
	bool m_arMoveB[E_MAX];

private:
	bool move(S_LAND &sDst,S_LAND &sSrc);
	bool moveObject(int nDst, int nSrc, int nObject);
public:
	C_CROSS() = default;
	void init();
	void run();
	void printObj(int nObj , const char* str);
};