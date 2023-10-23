#include "cross.h"
#include <stdio.h>



void C_CROSS::init()
{
	m_arBlock[E_WOLF | E_GOAT] = m_arBlock[E_CABBAGE | E_GOAT] = 
	m_arBlock[E_WOLF | E_GOAT | E_CABBAGE] = true;

	m_nLandA.nLand  = E_WOLF | E_GOAT | E_CABBAGE | E_FAMER;
	m_nLandB.nLand  = E_NULL;


}
bool C_CROSS::move(S_LAND &sDst, S_LAND &sSrc)
{
	if (m_arBlock[sDst.nLand] || m_arBlock[sSrc.nLand])
		return false;

	int nObject = E_FAMER | E_CABBAGE;


	for (int nObject = E_FAMER; nObject > E_NULL; nObject >>= 1)
	{

		int nTmpA = sDst.nLand ^ (nObject | E_FAMER);
		int nTmpB = sSrc.nLand ^ (nObject | E_FAMER);

		if (m_arBlock[nTmpA] || m_arBlock[nTmpB] || sDst.arMove[nTmpA] || sSrc.arMove[nTmpB])
		{
			return false;
		}
		printObj(nObject | E_FAMER , "ø≈±‰¥Ÿ");
		sDst.nLand = nTmpA;
		sDst.arMove[nTmpA] = true;
		sSrc.nLand = nTmpB;
		sSrc.arMove[nTmpB] = true;

		move(sSrc, sDst);


		//printf("--------------------\n");

	}

}

bool C_CROSS::moveObject(int nDst, int nSrc, int nObject)
{
	return false;
}
void C_CROSS::run()
{
	move(m_nLandA, m_nLandB);
}

void C_CROSS::printObj(int nObj , const char* str)
{
	printf("%s : ", str);
	if (nObj & E_FAMER)		printf("≥Û∫Œ ");
	if (nObj & E_GOAT)		printf("ø∞º“ ");
	if (nObj & E_WOLF)		printf("¥¡¥Î ");
	if (nObj & E_CABBAGE)	printf("πË√ﬂ ");
	
	printf("\n");
}
