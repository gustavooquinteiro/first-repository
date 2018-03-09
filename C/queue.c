#include <stdio.h>
#include <stdlib.h>
#include "../lib/avl.h"
#include "../lib/queue.h"

// Declaração da struct
typedef struct queue{
	Node * node; 	
	struct queue * next;
	struct queue * begin;
	struct queue * end;
	int size;
} Queue; 

/* Função que aloca na memoria uma queue
 * Caso não consiga alocar, lança erro de alocação na saída padrão e termina o programa */
Queue * defineQueue(){
	Queue * queue = (Queue *)malloc(sizeof(Queue));
	if (!queue){
		perror(MALLOC_ERROR);
		exit(EXIT_FAILURE); 
	} else{
		queue->begin = NULL;
		queue->end = NULL;
		queue->next = NULL;
		queue->size = ZERO;
		return queue;
	}
}

// Função que remove o elemento da frente da queue, caso ela não esteja vazia. Caso a queue estiver vazia, desaloca-a da memória 
void pop(Queue * queue){
	Queue *aux;
	if (isEmpty(queue)){
		clearQueue(queue);
	} else{
		aux = queue->begin;
		queue->begin = aux->next; 		 
	}
	queue->size -= ONE;
	free(aux);
}
	
//Função que verifica se a queue está vazia
int isEmpty(Queue *queue){
	return (queue->begin == NULL); 
}

// Função que retorna a frente da queue
Node * front (Queue * queue){
	return !isEmpty(queue)? queue->begin->node: NULL; 
}

// Função que retorna o final da queue
Node * back (Queue * queue){
	return !isEmpty(queue)? queue->end->node: NULL;  
}

// Função que retorna o tamanho da queue
int size(Queue * queue){
	return queue->size;
}

// Função que desaloca da memória a queue
void clearQueue(Queue * queue){
	free(queue); 
}
