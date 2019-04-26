//
//  main.c
//  跨函数使用内存
//
//  Created by admin on 2018/12/21.
//  Copyright © 2018年 admin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int sid;
    int age;
};

struct Student * CreatStudent(void) {
    struct Student * pst = (struct Student *)malloc(sizeof(struct Student));
    pst->sid = 100;
    pst->age = 99;
    return pst;
}

void ShowStudent(struct Student * pst) {
    printf("打印: %d, %d", (*pst).sid, (*pst).age);
}

int main(void) {

    struct Student * st;
    st = CreatStudent();
    ShowStudent(st);

    return 0;
}


