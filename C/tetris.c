	#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAIS_INFINITO 20000
#define MENOS_INFINITO -1

typedef struct competidores{
  char nome[16];
  int pontos;
}Competidores;

Competidores compet [1010]; 
int n;

int compara(const void * p1, const void * p2){
  int r = ((Competidores *)p2)->pontos - ((Competidores *)p1)->pontos;
  if (r != 0)
    return r;
  return strcmp(((Competidores *)p1)->nome, ((Competidores *)p2)->nome);
}

int main(){
  int pontos, p, min, max, i, k, classif, pontos_ant, teste=1;
  while (scanf("%d", &n) == 1 && n > 0){
      /* le jogadores e pontuacoes */
      for (i = 0; i < n; i++){
		  scanf("%s", compet[i].nome);
		  min = MAIS_INFINITO;
		  max = MENOS_INFINITO;
		  pontos = 0;
		  for (k = 0; k < 12; k++){
			 scanf("%d", &p);
			 if (p < min)
				min = p;
			 if (p > max)
				max = p;
			 pontos += p;
		  }
		compet[i].pontos = pontos - max - min;
	}
   /* ordena */
   qsort(compet, n, sizeof(Competidores), compara);
   /* calcula classificacao e imprime */
   pontos_ant = MAIS_INFINITO;
   printf("Teste %d\n", teste++);
   for (i = 0; i < n; i++){
		if (compet[i].pontos != pontos_ant)
			classif = i + 1;
		printf("%d %d %s\n", classif, compet[i].pontos, compet[i].nome);
		pontos_ant = compet[i].pontos;
	}
    printf("\n");
   }
  return 0;
}
