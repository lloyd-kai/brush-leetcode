#define _CRT_SECURE_NO_WARNINGS //��һ�д����Ƿ�ֹVS�е�scanf���������
//����Ϊ�����ͷ�ļ�
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "DoublyLinkList.h"


//���µ��ò�ͬ�㷨���Ӧ��solution������ǲ��Ժ���������ʵ�ּ���Ӧ��ͷ�ļ���
int main()
{
	//����δ��ʼ������ʾ
	//int a;
	//printf("%d", a);

	//���Ծ�̬����
	//Test_StaticArray();

	//���Զ�̬����
	//Test_DynamicArray();

	//�����Լ�ʵ�ֵĶ�̬����
    // ��ʼ��������Ϊ 3
    //MyArrayList<int> arr(3);

    //// ��� 5 ��Ԫ��
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
    //���Ե�����
    //Test_LinkList();


    //------------------------------------
    //����˫����
    //Test_DoublyLinkList();


    //-----------------------------------
    //�����Լ�ʵ�ֵ�˫����
    Test_MyLinkedList();



	return 0;
}


