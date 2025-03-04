#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>
using namespace std;

//��̬�������ز���

void Test_DynamicArray(void)
{
	//������̬����
	//������ʽָ������Ĵ�С��������ʵ��������ݻ���������
	vector<int> arr;

	for (int i = 0; i < 10; i++)
	{
		//�ڶ�̬�����ĩβ���Ԫ�أ�ʱ�临�Ӷ�O(1)
		arr.push_back(i);//��Ȼ����һ�ֲ�����emplace_back()���ﲻչ��
	}

	//���м����Ԫ��
	//������Ϊ2��λ�ò���Ԫ��666
	arr.insert(arr.begin() + 2, 666);

	//��ͷ�����Ԫ��
	arr.insert(arr.begin(), -1);

	//ɾ��ĩβԪ��
	arr.pop_back();
	
	//ɾ������Ϊ2��Ԫ��
	arr.erase(arr.begin() + 2);

	//������������Ԫ�أ��������ݽṹ�еİ�λ����(���±����)
	int a = arr[0];

	//���������޸�Ԫ��
	arr[0] = 100;

	//����Ԫ��ֵ�������������ǵ���ú���������ʱ�临�Ӷ�ΪO(n)
	//find�������ص��ǵ��������õ�����-�������õ��±�
	int index = find(arr.begin(), arr.end(), 666) - arr.begin();

	//��ӡ�����е�Ԫ��
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " \n"[i == arr.size() - 1];
	}

}



//��̬�������ʵ�֡����ӵײ�ʵ��
//��Ҫ�õ�ģ����࣬�����������C++�Ļ���֮��������
template<typename E>
class MyArrayList
{
private:
	//�����洢����ĵײ�����
	E* data;//�����E�൱��ElemType,����ʹ�������������������
	//��¼�����е�Ԫ�ظ���
	int size;

	//���Ԫ������
	int cap;

	//Ĭ�ϳ�ʼ������
	static const int INIT_CAP = 1;

public:
	//Ĭ�Ϲ��캯��
	MyArrayList()
	{
		this->data = new E[INIT_CAP];//����һ���ռ�
		this->size = 0;//��ʼ��Ԫ������Ϊ0
		this->cap = INIT_CAP;
	}

	//��ʽָ������Ŀռ�
	MyArrayList(int initCapacity)
	{
		this->data = new E[initCapacity];
		this->size = 0;
		this->cap = initCapacity;
	}

	//�������Ԫ��
	void addLast(E e)
	{
		//�����ж������Ƿ��㹻
		if (size == cap)
		{
			resize(2 * cap);//����պ����˾ͽ�������Ϊԭ��������
		}
		//��β������Ԫ��
		data[size] = e;
		size++;//Ԫ�ظ���+1
	}

	//��ָ��λ��(ע��������)����Ԫ��
	void add(int index, E e)
	{
		//��������Ƿ�Խ��
		checkPositionIndex(index);

		//�����������Ƿ����
		if (size == cap)
		{
			resize(2 * cap);
		}

		//Ǩ������
		for (int i = size - 1; i >= index; i--)
		{
			data[i + 1] = data[i];
		}

		//����Ԫ��
		data[index] = e;

		//Ԫ������+1
		size++;
	}

	//�������ײ����Ԫ��
	void addFirst(E e)
	{
		add(0, e);
	}

	//ɾ�����һ��Ԫ�ز�����ֵ
	E removeLast()
	{
		//�쳣����
		if (size == 0)
		{
			throw std::out_of_range("NoSuchElementException");
		}

		//��������
		if (size == cap / 4)
		{
			resize(cap / 2);
		}

		E deletedVal = data[size - 1];

		//ɾ�����һ��Ԫ��
		//��C++Ҫ�����ÿջ�����free����������ڴ�й¶�ķ���
		data[size - 1] = NULL;
		size--;

		return deletedVal;
	}

	//ɾ��ָ��������Ԫ��
	E remove(int index)
	{
		//�������Խ��
		checkElementIndex(index);

		//��������
		if (size == cap / 4)
		{
			resize(cap / 2);
		}

		E deletedVal = data[index];

		//Ǩ������
		for (int i = index+1; i < size; i++)
		{
			data[i-1] = data[i];
		}

		//ɾ�����һ��Ԫ��
		data[size - 1] = NULL;

		size--;

		return deletedVal;
	}

	//����ָ������λ�õ�Ԫ��
	E get(int index)
	{
		//�������Խ��
		checkElementIndex(index);

		return data[index];
	}

	//�޸�ָ������Ԫ�ص�ֵ
	E set(int index, E element)
	{
		//�������Խ��
		checkElementIndex(index);

		//�޸�����
		E oldVal = data[index];
		data[index] = element;

		return oldVal;
	}

	//���߷���,��ȡ�����Ԫ������
	int getSize()
	{
		return size;
	}

	//�ж������Ƿ�Ϊ��
	bool empty()
	{
		return size == 0;
	}

	//�������������ΪNewCap
	void resize(int newCap)
	{
		E* temp = new E[newCap];//��ָ��ָ���µ��ڴ�ռ�

		//Ǩ��ԭ����Ԫ��
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}

		//�ͷ�ԭ�������ڴ�
		delete[] data;//ע�ⲻ��ֻдdelete

		data = temp;
		cap = newCap;
	}

	//�ж϶�Ӧ�����Ƿ����
	bool isElementIndex(int index)
	{
		return index >= 0 && index < size;
	}

	//�ж϶�Ӧλ���Ƿ����
	bool isPositionIndex(int index)
	{
		return index >= 0 && index <= size;
	}

	//���index����λ���Ƿ���Դ���Ԫ��
	void checkElementIndex(int index)
	{
		if (!isElementIndex(index))
		{
			throw std::out_of_range("Index out of bounds");
		}
	}

	//���index����λ���Ƿ�������Ԫ��
	//����������ĩβ��ӣ�����index����==size
	void checkPositionIndex(int index)
	{
		if (!isPositionIndex(index))
		{
			throw std::out_of_range("Index out od bounds");
		}
	}

	//չʾ���е�����Ԫ��
	void display()
	{
		cout << "size =" << size << " cap = " << cap << endl;
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

	//��������
	~MyArrayList()
	{
		delete[] data;
	}
};