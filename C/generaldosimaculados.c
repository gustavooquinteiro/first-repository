#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int compara (const void *p1, const void * p2){
	const char *palavra1 = *(const char **)p1;
	const char *palavra2 = *(const char **)p2;
	return (strcmp(palavra1, palavra2));
}

int main(){
	
	int s, i;
	scanf("%d %d",&s, &i);
	//char** nomes = (char**) malloc(s*sizeof(char*));
	char * nomes [s];
	int x;
	for (x=0;x<s;x++){
		nomes[x] = (char *)malloc(MAX*sizeof(char)); 
		scanf(" %[^\n]s", nomes[x]);
		
	}
	qsort(nomes, s, sizeof(char*), compara);
		
	printf("%s \n", nomes[i-1]);
return 0;
}
