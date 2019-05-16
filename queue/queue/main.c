//
//  main.c
//  queue
//

#include <stdio.h>
#include <stdbool.h>
//# include <malloc.h>

typedef struct queue {
    int * pBase;
    int front;
    int rear;
}QUEUE, * PQUEUE;

void init_queue(PQUEUE);
void en_queue(PQUEUE, int);
void out_queue(PQUEUE, int*);
bool empty_queue(PQUEUE);
bool full_queue(PQUEUE);
void traverse_queue(PQUEUE);



int main (void) {
    
    QUEUE q;
    int val;
    
    init_queue(&q);
    en_queue(&q, 1);
    en_queue(&q, 2);
    en_queue(&q, 3);
    en_queue(&q, 4);
    en_queue(&q, 5);
    en_queue(&q, 6);
    en_queue(&q, 7);
    en_queue(&q, 8);
    
    out_queue(&q, &val);
    
    traverse_queue(&q);

    
    return 0;
}

void init_queue(PQUEUE pQ) {
    pQ->pBase = (int*)(malloc(sizeof(int) * 6));
    pQ->front = 0;
    pQ->rear = 0;
}

bool empty_queue(PQUEUE pQ) {
    
    return pQ->front == pQ->rear;
}

void en_queue(PQUEUE pQ, int val) {
    
    pQ->pBase[pQ->rear] = val;
    pQ->rear = (pQ->rear + 1) % 6;
}

void out_queue(PQUEUE pQ, int * pVal) {
    *pVal = pQ->pBase[pQ->front];
    pQ->front = (pQ->front + 1) % 6;
}

void traverse_queue(PQUEUE pQ) {
    int p = pQ->front;
    
    while (p != pQ->rear) {
        printf("%d", pQ->pBase[p]);
        p = (p + 1 ) % 6;
    }
}


bool full_queue(PQUEUE pQ) {
    
    return (pQ->rear + 1) % 6 == pQ->front;
}
