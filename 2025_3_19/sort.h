#pragma once
#include <iostream>
#include <vector>

using namespace std;

//ѡ�������ʵ��
//ʱ�临�Ӷ�ΪO(n^2)
void sort(vector<int>& nums)
{
	int n = nums.size();
	//����sortedIndex��һ���ָ���
	//���� < sortedIndex��Ԫ�ض����Ѿ�������
	//���� >= sortedIndex��Ԫ�ض���δ�����
	int sortedIndex = 0;//��ʼ��Ϊ����Ԫ�ض�û������
	while (sortedIndex < n)
	{
		//���ҵ�[sortedIndex,n)�е���Сֵ
		int minIndex = sortedIndex;
		for (int i = sortedIndex + 1; i < n; i++)
		{
			if (nums[i] < nums[minIndex])
			{
				minIndex = i;
			}
		}
		//������Сֵ��sortedIndex����Ԫ��
		int temp = nums[sortedIndex];
		nums[sortedIndex] = nums[minIndex];
		nums[minIndex] = temp;

		sortedIndex++;
	}
}


//ѡ��������Ż�-�����Ż�Ϊ�ȶ�����
void sort(vector<int>& nums)
{
	int n = nums.size();
	int sortedIndex = 0;
	while (sortedIndex < n)
	{
		//���ҵ�[sortedIndex,n)�е���Сֵ
		int minIndex = sortedIndex;
		for (int i = sortedIndex + 1; i < n; i++)
		{
			if (nums[i] < nums[minIndex])
			{
				minIndex = i;
			}
		}

		//������Сֵ��sortedIndex����Ԫ��
		//�Ż�
		//��nums[sortedIndex,minIndex]��Ԫ����������ƶ�һλ
		int minVal = nums[minIndex];
		//����Ǩ�����ݵĲ���
		for (int i = minIndex; i > sortedIndex; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[sortedIndex] = minVal;

		sortedIndex++;
	}
}