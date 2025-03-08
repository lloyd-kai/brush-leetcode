#pragma once
#include <stdexcept>
#include <ostream>

//循环数组的实现
template<typename T>
class CycleArray
{
	//成员变量
	unique_ptr<T[]> arr;//C++11特性，智能指针，会自动释放指针的内存
	int start;//头指针，指向第一个元素
	int end;//尾指针，指向最后一个元素的"下一位"
	int count;//元素数量
	int size;

	//自动扩缩容辅助函数
	void resize(int newSize)
	{
		//创建新的数组
		unique_ptr<T[]> newArr = make_unique<T[]>(newSize);
		//将旧数组的元素复制到新数组中
		for (int i = 0; i < count; i++)
		{
			newArr[i] = arr[(start + i) % size];//循环数组的核心在于取模实现"循环",每一次元素的增减都需要这一步
		}
		
		arr = move(newArr);
		//重置start与end指针
		start = 0;
		end = count;
		size = newSize;

	}

public:
	//循环数组的构造函数
	CycleArray() : CycleArray(1)
	{

	}

	//初始化时首尾指针指向同一个元素
	explicit CycleArray(int size) :start(0), count(0), size(size)
	{
		arr = make_unique<T[]>(size);
	}

	//在数组头部添加元素,时间复杂度为O(1)
	void addFirst(const T& val)
	{
		//当数组满时，扩容为原来的两倍
		if (isFull())
		{
			resize(size * 2);
		}
		//因为start是闭区间(这里设置为左闭右开，比如[0,0)代表初始没有元素),所以先左移，再赋值
		start = (start - 1 + size) % size;
		arr[start] = val;
		count++;
	}

	//删除数组头部元素，时间复杂度为O(1)
	void removeFirst(void)
	{
		//如果数组为空
		if (isEmpty())
		{
			throw std::runtime_error("Array is empty");
		}
		//先赋值，后右移
		arr[start] = T();
		start = (start + 1) % size;
		count--;
		//如果数组元素数量减少到原来大小的四分之一,则减少数组到原来大小的一半
		if (count > 0 && count == size)
		{
			resize(size/2);
		}

	}


	//在数组尾部添加元素，时间复杂度为O(1)
	void addLast(const T& val)
	{
		if (isFull())
		{
			resize(size * 2);
		}
		//end是开区间，所以先赋值，然后右移动一位
		//防止end成为负数，需要加上模数然后再取模
		arr[end] = val;
		end = (end + 1) % size;
		count++;
	}

	//删除数组尾部元素
	void removeLast()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Array is empty");
		}
		//先移动再赋值，因为此时end是指向最后一个元素的"后一位"的
		end = (end - 1+size) % size;
		arr[end] = T();

		count--;
		//缩容
		if (count > 0 && count == size / 4)
		{
			resize(size / 2);
		}
	}

	//获取数组的头部元素
	T getFirst() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Array is empty");
		}
		return arr[start];
	}

	//获取数组尾部元素
	T getLast() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("Array is empty");
		}
		return arr[(end - 1 + size) % size];
	}

	//判断数组是否已满
	//数据结构中经常使用start与end之间的关系判断循环数组是否已满或者是为空
	bool isFull() const
	{
		return count == size;
	}

	//判断数组是否为空
	bool isEmpty() const
	{
		return count == 0;
	}

	//获取循环数组的元素个数
	int getSize() const
	{
		return count;
	}
};

