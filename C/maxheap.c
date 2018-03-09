#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define ONE 1
#define ZERO 0

typedef struct heap{
	void *array;
	int heapsize;
} MaxHeap;

int parent(int i){
	return i >> ONE;
}

int left(int i){
	return i << ONE;
}

int right(int i){
	return i << ONE | ONE;
}


MaxHeap * defineMaxHeap(int capacity){
	MaxHeap* new = (MaxHeap *)malloc(sizeof(MaxHeap));
	new->heapsize = capacity;
	new->array = (void *)malloc((capacity+ONE) * sizeof(void));
	return new; 
}

void swap(void ** x, void ** y){
	void * temp = *x;
	*x = *y;
	*y = temp;
}

void maxHeapify(MaxHeap * heap, int n){
	int maior = n;
	
	if (left(n) <= heap->heapsize && heap->array[left(n)].frequency > heap->array[maior].frequency)
		maior = left(n);
	
	if (right(n)<= heap->heapsize && heap->array[right(n)].frequency > heap->array[maior].frequency)
		maior = right(n);
	
	if (maior != n){
		swap(&heap->array[n], &heap->array[maior]);
		maxHeapify(heap, maior);
	}
}

void maxHeapBuild(MaxHeap * heap, int n){
	register int i; 
	for(i = ceil(parent(n)); i > ONE; i--){
		maxHeapify(heap, i); 
	}
}

char maximum(MaxHeap * heap){
	return heap->array[ONE].letter; 
}

char removeMaximum(MaxHeap * heap){
	char max = heap->array[ONE].letter;
	swap(&heap->array[ONE], &heap->array[heap->heapsize]);
	free(&heap->array[heap->heapsize]); 
	heap->heapsize--;
	maxHeapify(heap, heap->heapsize); 
	return max;
}

void insert(MaxHeap * heap, filaPrioridade newLetter){
	heap->array[heap->heapsize + ONE]= newLetter;
	int i = heap->heapsize + ONE;
	while (i >= 2 && heap->array[(int)ceil(i/2)].frequency< heap->array[i].frequency){
		swap(&heap->array[(int)ceil(i/2)], &heap->array[i]);
		i = (int)ceil(i/2);
	}
}
