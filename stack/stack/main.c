//
//  main.c
//  stack
//
//  Created by admin on 2019/5/13.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
 
    int data;
    struct node * pNext;
}NODE, * PNODE;

typedef struct stack {
    PNODE pTop;
    PNODE pBottom;
}STACK, * PSTACK;

void initStack(PSTACK);
void pushStack(PSTACK, int);
void popStack(PSTACK, int *);
void traverse(PSTACK);
bool isEmpty(PSTACK);
void clearStack(PSTACK);

int main(void) {

    STACK pS;
    int val;
    initStack(&pS);
    
    popStack(&pS, &val);
}

void initStack(PSTACK pS) {
    
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    
    if (pS->pTop == NULL) {
        printf("失败退出");
        exit(-1);
    }else{
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
    
    
}

void pushStack(PSTACK pS, int val) {
    
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (pNew == NULL) {
        printf("失败退出");
        exit(-1);
    }else{
        pNew->data = val;
        pNew->pNext = pS->pTop;
        pS->pTop = pNew;
    }
}

void traverse(PSTACK pS) {
    
    if (!isEmpty(pS)) {
        PNODE p = pS->pTop;
        while (p != pS->pBottom) {
            printf("%d/n", p->data);
            p = p->pNext;
        }
    }
}

bool isEmpty(PSTACK pS) {
    return pS->pTop == pS->pBottom;
}

void popStack(PSTACK pS, int * val) {
    
    PNODE p = pS->pTop;
    
    *val = p->data;
    pS->pTop = p->pNext;
    
    free(p);
    p = NULL;
    
}



void clearStack(PSTACK pS) {
    
    if (isEmpty(pS)) {
        return;
    }
    
    PNODE p = pS->pTop;
    PNODE q = NULL;
    
    while (p != pS->pBottom) {
        q = p->pNext;
        free(p);
        p = q;
    }
    
    pS->pTop = pS->pBottom;
    
}

