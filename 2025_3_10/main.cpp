#define _CRT_SECURE_NO_WARNINGS
#include "ChainHashMap.h"
#include "LinearProbingHashMap_Rehash.h"


//测试实现的代码和算法
int main()
{
	//测试拉链法实现的HashMap
	//Test_ChainHashMap();


	//测试线性探测法实现的HashMap,采用往后探测的方式
	Test_MyLinearProbingHashMap1();

	return 0;
}