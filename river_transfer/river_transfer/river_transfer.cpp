// river_transfer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "cross.h"
    
int main()
{
    //point로 배열을 잡고 값을 확인 하고 싶으면 refernce로 casting 해서 본다
    C_CROSS cCross{};
    cCross.init();
    cCross.run();

}

