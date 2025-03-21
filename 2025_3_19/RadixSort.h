#pragma once
#include <iostream>
#include <vector>
using namespace std;

//��������
//���ǶԶ�λ�������򣬴����λ�Ƚϣ�ֱ�����λ
//���������Ϊ�Ӹ�λ����λ��Most Significant Digit first����� MSD��
//�ӵ�λ����λ��Least Significant Digit first����� LSD�����֡�
//���õľ���MSD����ҪӦ�þ����ֵ���
//������дLSD��������дMSD


//����������ʹ�ü�������������㷨����һ��ļ�������ͬ
//����Ҫȷ��nums�е�Ԫ�ض��ǷǸ���
//k�ǵ�ǰ��Ҫ�����λ��
void countSort(vector<int>& nums, int k)
{
	//����������ÿһλʮ��������ȡֵ��Χ��0-9
	vector<int> count(10, 0);

	//��ÿһ��Ԫ�صĵ�kλ���м���
	for (int num : nums)
	{
		int digit = (num / static_cast<int>(pow(10, k))) % 10;
		count[digit]++;
	}

	for (int i = 1; i < count.size(); i++)
	{
		count[i] += count[i - 1];
	}

	//���յ�kλ��ֵ ��Ԫ�ؽ�������
	vector<int> sorted(nums.size());
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		int digit = (nums[i] / static_cast<int>(pow(10, k))) % 10;
		sorted[count[digit] - 1] = nums[i];
		count[digit]--;
	}

	//�����������ƻ�Դ����
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] = sorted[i];
	}
}

void radixSortLSD(vector<int>& nums)
{
	int min = INT_MAX;
	for (int num : nums)
	{
		min = std::min(min, num);
	}

	//������СԪ�أ�������Ԫ��ת��Ϊ��0��ʼ�ķǸ���
	int offset = -min;
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] += offset;
	}

	int max = INT_MAX;
	for (int num : nums)
	{
		max = std::max(max, num);
	}

	//�������Ԫ�ص�λ��
	int maxLen = 0;
	while (max > 0)
	{
		max /= 10;
		maxLen++;
	}

	//�ӵ�λ����λ�����ζ�ÿһλ���м�������
	for (int k = 0; k < maxLen; k++)
	{
		countSort(nums, k);
	}

	//������Ԫ��ת����ԭ����ֵ
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] -= offset;
	}
}



//���Ի�������
void testRadixSort(void)
{
	vector<int>test = { 200,312,145,0,22,27,-40,-123,374,235,235 };

	//���Ի�������
	radixSortLSD(test);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " \n"[i == test.size() - 1];
	}
}