#pragma once
#include <stdexcept>
#include <ostream>

//ѭ�������ʵ��
template<typename T>
class CycleArray
{
	//��Ա����
	unique_ptr<T[]> arr;//C++11���ԣ�����ָ�룬���Զ��ͷ�ָ����ڴ�
	int start;//ͷָ�룬ָ���һ��Ԫ��
	int end;//βָ�룬ָ�����һ��Ԫ�ص�"��һλ"
	int count;//Ԫ������
	int size;

	//�Զ������ݸ�������
	void resize(int newSize)
	{
		//�����µ�����
		unique_ptr<T[]> newArr = make_unique<T[]>(newSize);
		//���������Ԫ�ظ��Ƶ���������
		for (int i = 0; i < count; i++)
		{
			newArr[i] = arr[(start + i) % size];//ѭ������ĺ�������ȡģʵ��"ѭ��",ÿһ��Ԫ�ص���������Ҫ��һ��
		}
		
		arr = move(newArr);
		//����start��endָ��
		start = 0;
		end = count;
		size = newSize;

	}

public:
	//ѭ������Ĺ��캯��
	CycleArray() : CycleArray(1)
	{

	}

	//��ʼ��ʱ��βָ��ָ��ͬһ��Ԫ��
	explicit CycleArray(int size) :start(0), count(0), size(size)
	{
		arr = make_unique<T[]>(size);
	}

	//������ͷ�����Ԫ��,ʱ�临�Ӷ�ΪO(1)
	void addFirst(const T& val)
	{
		//��������ʱ������Ϊԭ��������
		if (isFull())
		{
			resize(size * 2);
		}
		//��Ϊstart�Ǳ�����(��������Ϊ����ҿ�������[0,0)�����ʼû��Ԫ��),���������ƣ��ٸ�ֵ
		start = (start - 1 + size) % size;
		arr[start] = val;
		count++;
	}

	//ɾ������ͷ��Ԫ�أ�ʱ�临�Ӷ�ΪO(1)
	void removeFirst(void)
	{
		//�������Ϊ��
		if (isEmpty())
		{
			throw std::runtime_error("Array is empty");
		}
		//�ȸ�ֵ��������
		arr[start] = T();
		start = (start + 1) % size;
		count--;
		//�������Ԫ���������ٵ�ԭ����С���ķ�֮һ,��������鵽ԭ����С��һ��
		if (count > 0 && count == size)
		{
			resize(size/2);
		}

	}


	//������β�����Ԫ�أ�ʱ�临�Ӷ�ΪO(1)
	void addLast(const T& val)
	{
		if (isFull())
		{
			resize(size * 2);
		}
		//end�ǿ����䣬�����ȸ�ֵ��Ȼ�����ƶ�һλ
		//��ֹend��Ϊ��������Ҫ����ģ��Ȼ����ȡģ
		arr[end] = val;
		end = (end + 1) % size;
		count++;
	}

	//ɾ������β��Ԫ��
	void removeLast()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Array is empty");
		}
		//���ƶ��ٸ�ֵ����Ϊ��ʱend��ָ�����һ��Ԫ�ص�"��һλ"��
		end = (end - 1+size) % size;
		arr[end] = T();

		count--;
		//����
		if (count > 0 && count == size / 4)
		{
			resize(size / 2);
		}
	}

	//��ȡ�����ͷ��Ԫ��
	T getFirst() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Array is empty");
		}
		return arr[start];
	}

	//��ȡ����β��Ԫ��
	T getLast() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Array is empty");
		}
		return arr[(end - 1 + size) % size];
	}

	//�ж������Ƿ�����
	//���ݽṹ�о���ʹ��start��end֮��Ĺ�ϵ�ж�ѭ�������Ƿ�����������Ϊ��
	bool isFull() const
	{
		return count == size;
	}

	//�ж������Ƿ�Ϊ��
	bool isEmpty() const
	{
		return count == 0;
	}

	//��ȡѭ�������Ԫ�ظ���
	int getSize() const
	{
		return count;
	}
};

