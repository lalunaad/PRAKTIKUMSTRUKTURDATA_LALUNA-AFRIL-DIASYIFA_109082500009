#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAXQ = 5;
typedef int infotype;

struct Queue {
    infotype info[MAXQ];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif