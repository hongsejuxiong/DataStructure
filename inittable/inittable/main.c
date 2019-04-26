//
//  main.c
//  inittable
//
//  Created by admin on 2019/4/23.
//  Copyright © 2019年 admin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Array {
    int * pBase;
    int length;
    int current;
};

/**
 typedef 表示取别名;
 STU代表 struct Student 类型;
 PSTU代表 struct Student * 类型;
 struct Student 仍然可以继续使用;
 */
typedef struct Student{
    int sid;
    char name[10];
    char gender;
}* PSTU, STU;


void initArray(struct Array * pArray, int length);
void showArray(struct Array * pArray);
bool is_empty(struct Array * pArray);
bool append_array(struct Array * pArray, int value);
bool insert_array(struct Array * pArray, int position, int value);
bool delete_array(struct Array * pArray, int position, int * val);
void inversion_array(struct Array * pArray);

int main (void) {
    
    struct Array array;
    int val;
    initArray(&array, 6);
    
    append_array(&array, 1);
    append_array(&array, 2);
    append_array(&array, 3);
    append_array(&array, 4);

//    insert_array(&array, 2, 88);
//
//    if ( delete_array(&array, 2, &val) ) {
//        printf("删除成功\n");
//        printf("删除的元素是: %d\n", val);
//
//    }
    
    inversion_array(&array);
    showArray(&array);

    
    return 0;
}

/** 创建数组*/
void initArray(struct Array * pArray, int length) {
    
    pArray->pBase = (int *)malloc(sizeof(int) * length);
    if (pArray->pBase == NULL) {
        printf("分配内存失败!!!");
        exit(-1);
    }else{
        pArray->length = length;
        pArray->current = 0;
    }
    
}

/** 判断是否为空*/
bool is_empty(struct Array * pArray) {
    
    if (pArray->current == 0) {
        return true;
    }else{
        return false;
    }
}

/** 打印数组*/
void showArray(struct Array * pArray) {
    if (is_empty(pArray)) {
        printf("数组为空\n");
    }else{
        for (int i=0; i<pArray->current; i++) {
            printf("%d\n", pArray->pBase[i]);
            
        }
    }
}

bool append_array(struct Array * pArray, int value) {
    
    if (pArray->current == pArray->length) {
        return false;
    }
    
    pArray->pBase[pArray->current] = value;
    pArray->current++;
    return true;
}


/** 插入*/
bool insert_array(struct Array * pArray, int position, int value) {
    
    if (position < 1 || position > pArray->current + 1) {
        return false;
    }
    
    for (int i = pArray->current - 1; i >= position - 1; i--) {
        pArray->pBase[i+1] = pArray->pBase[i];
        
    }
    
    pArray->pBase[position-1] = value;
    pArray->current++;
    
    return true;
}

/** 删除*/
bool delete_array(struct Array * pArray, int position, int * val) {
    
    if (position < 1 || position > pArray->current || is_empty(pArray)) {
        return false;
    }
    
    *val = pArray->pBase[position-1];
    for (int i=position; i < pArray->current; i++) {
        pArray->pBase[i-1] = pArray->pBase[i];
    }
    
    pArray->current--;
    
    return true;
}

/** 倒置*/
void inversion_array(struct Array * pArray) {
    int i = 0;
    int j = pArray->current-1;
    int t;
    while (i < j) {
        
        t = pArray->pBase[i];
        pArray->pBase[i] = pArray->pBase[j];
        pArray->pBase[j] = t;
        i++;
        j--;
    }
    return;
}


void sort_array(struct Array * pArray) {
    
    int i, j, t;
    
    for (i = 0; i < pArray->current; i++) {
        
        for (j = i+1; j < pArray->current; j++) {
            
            if (pArray->pBase[i] > pArray->pBase[j]) {
                t = pArray->pBase[i];
                pArray->pBase[i] = pArray->pBase[j];
                pArray->pBase[j] = t;
            }
        }
    }
    
}
