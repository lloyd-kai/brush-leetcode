#pragma once
#include <iostream>
#include <vector>
using namespace std;


//���������ʵ��
void countSort(vector<int>& nums)
{
	//���ҵ���СԪ�غ����Ԫ��
	//����������ƫ������count�����С
	int min = -1000000,max = 1000000;//����ʵ������ʵ�ѡ����ʵ�ֵ,��ò�Ҫ���ó�ĳһ�������͵���ֵ�����п��ܻ����
	for (int i = 0; i < nums.size(); i++)
	{
		min = std::min(min, nums[i]);
		max = std::max(max, nums[i]);
	}

	//������Сֵ�����ֵ����Ԫ��ӳ�䵽0��ʼ������ֵ
	//��hash�е��񣬵������ӳ���߼��ǽ���ӳ��Ϊ�����������ǷǸ���
	int offset = -min;
	vector<int> count(max - min + 1);

	//��һ�α�����ͳ��ÿһ��Ԫ�س��ֵĴ���
	for (int num : nums)
	{
		count[num + offset]++;
	}

	//�ۼ�count������ÿһ��Ԫ�أ��õ�����nums[i]�����������Ľ���λ��
	//����count[1,5] ����Ϊ1ʱԪ��Ϊ5��������������[1,5)����ĳһ��ֵ��ͬ��Ԫ��
	for (int i = 1; i < count.size(); i++)
	{
		count[i] += count[i - 1];
	}

	//����ÿ��Ԫ������������λ�ã��������
	//Ҫ�Ӻ���ǰ��������֤������ȶ���
	vector<int> sorted(nums.size());
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		//����sorted��������
		sorted[count[nums[i] + offset] - 1] = nums[i];
		count[nums[i] + offset]--; 
	}

	//������ṹ���ƻ�ԭ����
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] = sorted[i];
	}
}


//���Լ�������
void testCountSort(void)
{
	vector<int>test = { 2,3,1,0,2,2,-4,-1,3,0 };
	countSort(test);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " \n"[i == test.size() - 1];
	}
}