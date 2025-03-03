#pragma once
#include <iostream>
#include <cstring>
using namespace std;

//静态数组的相关操作
void Test_StaticArray(void)
{

	//定义一个大小为10的静态数组
	int arr[10];

	//用memset函数把数组的值初始化为0
	memset(arr, 0, sizeof(arr));

	//使用索引赋值
	arr[0] = 1;
	arr[1] = 2;

	//使用索引取值
	int a = arr[0];
}


