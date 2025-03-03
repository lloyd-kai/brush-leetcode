#pragma once
#include <iostream>
#include <cstring>
using namespace std;

//静态数组的相关操作
void Test_StaticArray(void)
{
	//静态数组简单的操作
	//定义一个大小为10的静态数组
	//int arr[10];

	//用memset函数把数组的值初始化为0
	//memset(arr, 0, sizeof(arr));

	//使用索引赋值
	//arr[0] = 1;
	//arr[1] = 2;

	//使用索引取值
	//int a = arr[0];


	//----------------------------
	//数组末尾添加元素
	//大小为10的数组已经添加了四个元素
	//int arr[10];
	//for (int i = 0; i < 4; i++)
	//{
	//	arr[i] = i;
	//}

	//在数组末尾追加一个元素4
	//arr[4] = 4;

	//再次追加
	//arr[5] = 5;


	//----------------------------
	//数组插入元素
	//数组初始化
	int arr[10];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = i;
	}

	//在索引2位置插入元素666
	//首先需要将索引2以及之后的元素都往后移动一位
	//要从后往前开始遍历防止已有元素覆盖
	for (int i = 4; i > 2; i--)
	{
		arr[i] = arr[i - 1];
	}

	//插入新元素
	arr[2] = 666;

	//打印数组元素
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " \n"[i == 4];
	}
	

}


