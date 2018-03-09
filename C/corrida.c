#include <stdlib.h>
#include <stdio.h>

int main(){
int N, M, aux=0; 
scanf("%d%d", &N, &M);
int carros =0;
int tt[N], colocacao[N];
for (int i =0; i<N; i++){
	tt[i]=0;
	colocacao[i]=i;
}
for(int i=0;i<N;i++){
	for(int j=0;j<M;j++){
		scanf("%d", &carros);
		tt[i]+=carros;
	}
}
for(int i=0;i<N-1;i++){
	for(int j=i+1;j<N;j++){
		if (tt[i]>tt[j]){
			aux=colocacao[i];
			colocacao[i]=colocacao[j];
			colocacao[j]=aux;

			aux = tt[i];
			tt[i] = tt[j];	 
			tt[j]=aux;
		}
	}
}
for (int i=0; i<3;i++){
	printf("%d \n", colocacao[i]+1);
}
return 0;
}
