#pragma once
#include <iostream>
#include <cstring>
using namespace std;

//��̬�������ز���
void Test_StaticArray(void)
{

	//����һ����СΪ10�ľ�̬����
	int arr[10];

	//��memset�����������ֵ��ʼ��Ϊ0
	memset(arr, 0, sizeof(arr));

	//ʹ��������ֵ
	arr[0] = 1;
	arr[1] = 2;

	//ʹ������ȡֵ
	int a = arr[0];
}


