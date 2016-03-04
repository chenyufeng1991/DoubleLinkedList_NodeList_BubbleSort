//
//  main.c
//  DoubleLinkedList_NodeList_BubbleSort
//
//  Created by chenyufeng on 16/3/4.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  对带头结点尾结点的双向非循环链表进行冒泡排序
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化带头结点和尾结点的非循环双向链表
void InitialList(Node **pHead,Node **pTail){

    *pHead = (Node *)malloc(sizeof(Node));
    *pTail = (Node *)malloc(sizeof(Node));

    if (*pHead == NULL || *pTail == NULL) {
        printf("%s函数执行，内存分配失败，初始化双链表失败\n",__FUNCTION__);
    }else{
        //这个里面是关键，也是判空的重要条件
        (*pHead)->prior = NULL;
        (*pTail)->next = NULL;

        //链表为空的时候把头结点和尾结点连起来
        (*pHead)->next = *pTail;
        (*pTail)->prior = *pHead;

        printf("%s函数执行，带头结点和尾节点的双向非循环链表初始化成功\n",__FUNCTION__);
    }
}

//创建带头结点和尾结点的双向非循环链表
void CreateList(Node *pHead,Node *pTail){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pHead;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pInsert->prior = pMove;
        pInsert->next = pTail;
        pTail->prior = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->prior = NULL;
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行完成，带头节点和尾结点的双向非循环链表创建成功\n",__FUNCTION__);

}

//正序打印链表
void PrintList(Node *pHead,Node *pTail){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }
    
    printf("\n%s函数执行，正序打印带头结点尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}

//计算链表长度
int SizeList(Node *pHead,Node *pTail){

    int i = 0;
    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        i++;
        pMove = pMove->next;
    }
    printf("%s函数执行，链表的长度为%d\n",__FUNCTION__,i);

    return i;
}

//冒泡排序
void BubbleSort(Node *pHead,Node *pTail){

    int count = SizeList(pHead, pTail);
    Node *pMove;
    pMove = pHead->next;

    while (count > 1) {
        while (pMove->next != pTail) {
            if (pMove->element > pMove->next->element) {
                //交换
                int temp;
                temp = pMove->element;
                pMove->element = pMove->next->element;
                pMove->next->element = temp;
            }
            pMove = pMove->next;
        }
        pMove = pHead->next;
        count --;
    }

    printf("%s函数执行，链表的冒泡排序完成\n",__FUNCTION__);
}

int main(int argc, const char * argv[]) {

    Node *pHead;//头结点
    Node *pTail;//尾结点

    InitialList(&pHead, &pTail);

    CreateList(pHead, pTail);
    PrintList(pHead, pTail);

    BubbleSort(pHead, pTail);
    PrintList(pHead, pTail);

    return 0;
}








