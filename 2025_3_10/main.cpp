#define _CRT_SECURE_NO_WARNINGS
#include "ChainHashMap.h"
#include "LinearProbingHashMap_Rehash.h"
#include "LinearProbingHashMap_Flag.h"
#include "LinkedHashMap.h"
#include "ArrayHashMap.h"


//����ʵ�ֵĴ�����㷨
int main()
{
	//����������ʵ�ֵ�HashMap
	//Test_ChainHashMap();


	//��������̽�ⷨʵ�ֵ�HashMap,��������̽��ķ�ʽ
	//Test_MyLinearProbingHashMap1();

	//����HashMap�����ñ��ɾ�����ŵķ�ʽ
	//Test_MyLinearProbingHashMap2();

	//���������ǿ�Ĺ�ϣ��
	Test_LinkedHashMap();

	return 0;
}