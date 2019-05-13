//
//  main.c
//  LinkedList
//
//  Created by admin on 2019/4/29.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node * pNext;
}NODE, *PNODE;

PNODE createList(void);
void traverseList(PNODE phead);
int getListLength(PNODE pHead);
void sortList(PNODE pHead);
bool insert_list(PNODE pHead, int position, int val);
bool delete_list(PNODE pHead, int position, int * val);

int main(void) {
    
    PNODE pHead = createList();
    sortList(pHead);
    traverseList(pHead);
    

    return 0;
}

/** 创建链表*/
PNODE createList(void) {
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    
    if (pHead == NULL) {
        printf("创建链表失败,程序终止!");
        exit(-1);
    }
    
    int length;
    printf("请输入创建链表的长度:\n");
    scanf("%d",&length);
    
    for (int i=0; i < length; i++) {
        
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (pNew == NULL) {
            printf("失败退出!");
            exit(-1);
        }
        
        int value;
        printf("第%d个链表的值为:\n",i+1);
        scanf("%d",&value);
        pNew->data = value;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;

    }
    
    return pHead;
}

/** 遍历链表*/
void traverseList(PNODE pHead) {
    
    PNODE pTail = pHead->pNext;
    while (pTail != NULL) {
        printf("%d\n",pTail->data);
        pTail = pTail->pNext;
    }
    
    return;
}

/** 获取链表的长度*/
int getListLength(PNODE pHead){
    
    PNODE pTail = pHead->pNext;
    int length = 0;
    
    while (pTail != NULL) {
        length++;
        pTail = pTail->pNext;
    }
    
    return length;
    
}

/** 排序*/
void sortList(PNODE pHead) {
    int length = getListLength(pHead);
    printf("链表的长度为:%d\n",length);
    PNODE p,q;

    int i, j,t;
    
    for (i=0,p=pHead->pNext; i < length-1; i++,p=p->pNext) {

        for (j=i+1,q=p->pNext; j < length; j++,q=q->pNext) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    
    return;
}

/** 插入*/

bool insert_list(PNODE pHead, int position, int val) {
    
    int i = 0;
    PNODE p = pHead;
    
    while (p->pNext != NULL && i < position - 1) {
        p = p->pNext;
        i++;
    }
    
    if (i > position - 1 || p == NULL) {
        return false;
    }
    
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    
    if (pNew == NULL) {
        printf("内存g分配失败,程序退出!");
        exit(-1);
    }
    
    pNew->data = val;
    
    PNODE pTail = p->pNext;
    p->pNext = pNew;
    pNew->pNext = pTail;
    
    return true;
    
}

/** 删除节点,并返回删除点的值*/
bool delete_list(PNODE pHead, int position, int * val) {
    
    int i = 0;
    PNODE p = pHead;
    
    while (p->pNext != NULL && i < position - 1) {
        p = p->pNext;
        i++;
    }
    
    if (p == NULL || i > position - 1) {
        return false;
    }
    
    PNODE pTail = p->pNext;
    *val = pTail->data;
    p->pNext = p->pNext->pNext;
    free(pTail);
    pTail = NULL;
    
    return true;
}
