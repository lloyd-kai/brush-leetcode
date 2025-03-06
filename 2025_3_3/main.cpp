#define _CRT_SECURE_NO_WARNINGS //这一行代码是防止VS中的scanf报警告错误
//以下为导入的头文件
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "DoublyLinkList.h"


//以下调用不同算法题对应的solution类或者是测试函数，具体实现见对应的头文件。
int main()
{
	//变量未初始化的演示
	//int a;
	//printf("%d", a);

	//测试静态数组
	//Test_StaticArray();

	//测试动态数组
	//Test_DynamicArray();

	//测试自己实现的动态数组
    // 初始容量设置为 3
    //MyArrayList<int> arr(3);

    //// 添加 5 个元素
    //for (int i = 1; i <= 5; i++) {
    //    arr.addLast(i);
    //}

    //arr.remove(3);
    //arr.add(1, 9);
    //arr.addFirst(100);
    //int val = arr.removeLast();

    //// 100 1 9 2 3
    //for (int i = 0; i < arr.getSize(); i++) {
    //    std::cout << arr.get(i) << std::endl;
    //}

    //--------------------------------------
    //测试单链表
    //Test_LinkList();


    //------------------------------------
    //测试双链表
    //Test_DoublyLinkList();


    //-----------------------------------
    //测试自己实现的双链表
    Test_MyLinkedList();



	return 0;
}


