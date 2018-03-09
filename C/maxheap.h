#ifndef MAXHEAP_H
#define MAXHEAP_H

typedef struct priorityQueue filaPrioridade;
typedef struct heap MaxHeap;

void maxHeapify(MaxHeap * heap, int n);
void maxHeapBuild(MaxHeap * heap, int n);
void swap(filaPrioridade * x, filaPrioridade * y);
MaxHeap * defineMaxHeap(int capacity);
char maximum(MaxHeap * heap);
char removeMaximum(MaxHeap * heap);
void insert(MaxHeap * heap, filaPrioridade newLetter);



#endif

