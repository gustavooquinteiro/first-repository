#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
	void * element;
	struct stack * top;
	struct stack * bottom;
	int size;
}Stack;

Stack * defineStack(){
	Stack * stack = (Stack *)malloc(sizeof(Stack));
	if (stack){
		stack->top = NULL;
		stack->bottom = NULL;
		stack->size = 0;
	}
	return stack;
}

Stack * push(Stack * stack, void * element){
	Stack * new = (Stack *)malloc(sizeof(Stack));
	
	new->bottom = stack->top;
	stack->top = new;

	stack->size += 1;
	
	return stack;
}

void pop(Stack * stack){
		Stack * aux;
		if(isEmpty(stack)){
			clearStack(stack);
		}else{
			aux = stack->top;
			stack->top = aux->bottom;
		}
		stack->size -= 1;
		free(aux);
}

Stack * isEmpty(Stack * stack){
	return stack->top;
}

Stack * top(Stack * stack){
	return stack->top;	
}

int size(Stack * stack){
	return stack->size;
}

void clearStack(Stack * stack){
	free(stack);
}
