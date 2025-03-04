#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>
using namespace std;

//动态数组的相关操作

void Test_DynamicArray(void)
{
	//创建动态数组
	//不用显式指定数组的大小，其会根据实际情况扩容或者是缩容
	vector<int> arr;

	for (int i = 0; i < 10; i++)
	{
		//在动态数组的末尾添加元素，时间复杂度O(1)
		arr.push_back(i);//当然还有一种操作是emplace_back()这里不展开
	}

	//在中间插入元素
	//在索引为2的位置插入元素666
	arr.insert(arr.begin() + 2, 666);

	//在头部添加元素
	arr.insert(arr.begin(), -1);

	//删除末尾元素
	arr.pop_back();
	
	//删除索引为2的元素
	arr.erase(arr.begin() + 2);

	//根据索引查找元素，就是数据结构中的按位查找(按下标查找)
	int a = arr[0];

	//根据索引修改元素
	arr[0] = 100;

	//根据元素值查找索引，考虑到最好和最坏的情况，时间复杂度为O(n)
	//find函数返回的是迭代器，用迭代器-迭代器得到下标
	int index = find(arr.begin(), arr.end(), 666) - arr.begin();

	//打印数组中的元素
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " \n"[i == arr.size() - 1];
	}

}



//动态数组代码实现——从底层实现
//需要用到模板和类，建议读者在有C++的基础之后再来看
template<typename E>
class MyArrayList
{
private:
	//真正存储数组的底层数组
	E* data;//这里的E相当于ElemType,可以使用任意的数据类型声明
	//记录数组中的元素个数
	int size;

	//最大元素容量
	int cap;

	//默认初始化容量
	static const int INIT_CAP = 1;

public:
	//默认构造函数
	MyArrayList()
	{
		this->data = new E[INIT_CAP];//分配一个空间
		this->size = 0;//初始的元素数量为0
		this->cap = INIT_CAP;
	}

	//显式指定数组的空间
	MyArrayList(int initCapacity)
	{
		this->data = new E[initCapacity];
		this->size = 0;
		this->cap = initCapacity;
	}

	//数组添加元素
	void addLast(E e)
	{
		//首先判断容量是否足够
		if (size == cap)
		{
			resize(2 * cap);//如果刚好满了就将其扩容为原来的两倍
		}
		//在尾部插入元素
		data[size] = e;
		size++;//元素个数+1
	}

	//在指定位置(注意是索引)插入元素
	void add(int index, E e)
	{
		//检查索引是否越界
		checkPositionIndex(index);

		//看数组容量是否充足
		if (size == cap)
		{
			resize(2 * cap);
		}

		//迁移数据
		for (int i = size - 1; i >= index; i--)
		{
			data[i + 1] = data[i];
		}

		//插入元素
		data[index] = e;

		//元素数量+1
		size++;
	}

	//在数组首部添加元素
	void addFirst(E e)
	{
		add(0, e);
	}

	//删除最后一个元素并返回值
	E removeLast()
	{
		//异常处理
		if (size == 0)
		{
			throw std::out_of_range("NoSuchElementException");
		}

		//可以缩容
		if (size == cap / 4)
		{
			resize(cap / 2);
		}

		E deletedVal = data[size - 1];

		//删除最后一个元素
		//在C++要将其置空或者是free，否则会有内存泄露的风险
		data[size - 1] = NULL;
		size--;

		return deletedVal;
	}

	//删除指定索引的元素
	E remove(int index)
	{
		//检查索引越界
		checkElementIndex(index);

		//可以缩容
		if (size == cap / 4)
		{
			resize(cap / 2);
		}

		E deletedVal = data[index];

		//迁移数据
		for (int i = index+1; i < size; i++)
		{
			data[i-1] = data[i];
		}

		//删除最后一个元素
		data[size - 1] = NULL;

		size--;

		return deletedVal;
	}

	//查找指定索引位置的元素
	E get(int index)
	{
		//检查索引越界
		checkElementIndex(index);

		return data[index];
	}

	//修改指定索引元素的值
	E set(int index, E element)
	{
		//检查索引越界
		checkElementIndex(index);

		//修改数据
		E oldVal = data[index];
		data[index] = element;

		return oldVal;
	}

	//工具方法,获取数组的元素数量
	int getSize()
	{
		return size;
	}

	//判断数组是否为空
	bool empty()
	{
		return size == 0;
	}

	//将数组的容量改为NewCap
	void resize(int newCap)
	{
		E* temp = new E[newCap];//将指针指向新的内存空间

		//迁移原来的元素
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}

		//释放原来数组内存
		delete[] data;//注意不能只写delete

		data = temp;
		cap = newCap;
	}

	//判断对应索引是否存在
	bool isElementIndex(int index)
	{
		return index >= 0 && index < size;
	}

	//判断对应位置是否存在
	bool isPositionIndex(int index)
	{
		return index >= 0 && index <= size;
	}

	//检查index索引位置是否可以存在元素
	void checkElementIndex(int index)
	{
		if (!isElementIndex(index))
		{
			throw std::out_of_range("Index out of bounds");
		}
	}

	//检查index索引位置是否可以添加元素
	//允许在数组末尾添加，所以index可以==size
	void checkPositionIndex(int index)
	{
		if (!isPositionIndex(index))
		{
			throw std::out_of_range("Index out od bounds");
		}
	}

	//展示所有的数组元素
	void display()
	{
		cout << "size =" << size << " cap = " << cap << endl;
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

	//析构函数
	~MyArrayList()
	{
		delete[] data;
	}
};