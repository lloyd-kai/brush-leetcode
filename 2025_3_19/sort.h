#pragma once
#include <iostream>
#include <vector>

using namespace std;

//ѡ�������ʵ��
//ʱ�临�Ӷ�ΪO(n^2)
void sort1(vector<int>& nums)
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
void sort2(vector<int>& nums)
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

//��ѡ���������һ���Ż���������Сֵ��ͬʱ��������������forѭ��
//������������������֣�û������ð������
//���ݽṹ�е�ð������������for������˼����һ����
void bubbleSort1(vector<int>& nums)
{
	int n = nums.size();
	int sortedIndex = 0;
	while (sortedIndex < n)
	{
		//Ѱ��nums[sortedIndex...]�е���Сֵ
		//ͬʱ����Сֵͬ���ƶ���nums[sortedIndex]��λ��
		for (int i = n - 1; i > sortedIndex; i--)
		{
			if (nums[i] < nums[i - 1])
			{
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
			}
		}
		sortedIndex++;
	}
}


//�Ż����ð��������������������ǰ��ֹ���򣬼��ٱȽϵĴ���
void bubbleSort2(vector<int>& nums)
{
	int n = nums.size();
	int sortedIndex = 0;
	while (sortedIndex < n)
	{
		//Ѱ��nums[sortedIndex...]�е���Сֵ
		//ͬʱ����Сֵͬ���ƶ���nums[sortedIndex]��λ��
		//���һ��bool���������ڼ�¼һ�����Ƿ񽻻���һ��
		bool swapped = false;
		for (int i = n - 1; i > sortedIndex; i--)
		{
			if (nums[i] < nums[i - 1])
			{
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
				swapped = true;//����������Ϊ��
			}
		}
		//���һ����һ�ζ�û�н�������˵���Ѿ�����
		if (!swapped)
		{
			break;
		}

		sortedIndex++;
	}

}


//��ѡ��������Ż���������Ѿ������λ���в���Ԫ��
//Ҳ���ǲ�������
void insertSort(vector<int>& nums)
{
	int n = nums.size();
	int sortedIndex = 0;
	while (sortedIndex < n)
	{
		for (int i = sortedIndex; i > 0; i--)
		{
			if (nums[i] < nums[i - 1])
			{
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
			}
			else
			{
				break;
			}
		}
		sortedIndex++;
	}
}


//ϣ�����򣬶�h����������в�������
//����Сh�����h=1��ʱ������������������
//����ʹ���㷨�����е�h��Ҳ���Ǽ��Ϊ3��k-1�η������ڴ���������Ч�ʸ���
void shellSort(vector<int>& nums)
{
	int n = nums.size();
	//����ʹ�õ����ɺ�����3^(k-1)
	int h = 3;
	while (h < n / 3)
	{
		h = 3 * h;
	}

	//�Ķ�һ��AB�����������Ҫ�߼�����h��whileѭ������
	while (h >= 1)
	{
		//��sortedIndex��ʼ��Ϊh������1
		int sortedIndex = h;
		while (sortedIndex < n)
		{
			//�����Ĳ�����Ϊh������1
			for (int i = sortedIndex; i >= h; i -= h)
			{
				if (nums[i] < nums[i - h])
				{
					int temp = nums[i];
					nums[i] = nums[i - h];
					nums[i - h] = temp;
				}
				else
				{
					break;
				}
			}
			sortedIndex++;
		}
		h /= 3;
	}
}







//���������㷨
void test(void)
{
	vector<int>data;
	for (int i = 10; i > 0; i--)
	{
		data.push_back(i);
	}

	//����ð������
	//bubbleSort1(test);

	//�����Ż����ð������
	//bubbleSort2(test);

	//���Բ�������
	//insertSort(data);

	//����ϣ������
	shellSort(data);


	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " \n"[i == data.size() - 1];
	}

}