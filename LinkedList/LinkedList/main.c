//
//  main.c
//  LinkedList
//
//  Created by admin on 2019/4/29.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node * pNext;
}NODE, *PNODE;

PNODE createList(void);
void traverseList(PNODE phead);

int main(void) {
    
    PNODE pHead = createList();
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
