#include <stdlib.h>
#include <stdio.h>

#define MAX 100
typedef struct pais{
	int id;
	int medalhasOuro;
	int medalhasPrata;
	int medalhasBronze;
	}Pais;


int compara(const void *p1, const void * p2){
	Pais i = *((Pais *)p1);
	Pais j = *((Pais *)p2);
	if (i.medalhasOuro == j.medalhasOuro && i.medalhasPrata==j.medalhasPrata && i.medalhasBronze == j.medalhasBronze && i.id == j.id){
		return 0;
	}else{
		if (i.medalhasOuro > j.medalhasOuro 
		|| (i.medalhasOuro == j.medalhasOuro && i.medalhasPrata > j.medalhasPrata) 
		|| (i.medalhasOuro == j.medalhasOuro && i.medalhasPrata == j.medalhasPrata && i.medalhasBronze > j.medalhasBronze)
		|| (i.medalhasOuro == j.medalhasOuro && i.medalhasPrata == j.medalhasPrata && i.medalhasBronze == j.medalhasBronze && i.id < j.id))
			return -1;
		else
			return 1; 
		}
}
	
	
int main(){
	int m, n, o, p, b;
	scanf("%d%d", &n, &m);
	Pais participante;
	Pais ganhadores[n+1]; 
	int medalhasOuro[n+1];
	int medalhasPrata[n+1];
	int medalhasBronze[n+1];
	for (int i=0; i<=n; i++){
		medalhasOuro[i]=0;
		medalhasPrata[i]=0;
		medalhasBronze[i]=0; 
	}
	
	
	for(int i=0; i<m; i++){
		scanf("%d%d%d", &o, &p, &b); 
		medalhasOuro[o]++;
		medalhasPrata[p]++;
		medalhasBronze[b]++;
	}
	for(int i =0; i<=n; i++){
		participante.id = i;
		participante.medalhasOuro = medalhasOuro[i];
		participante.medalhasPrata = medalhasPrata[i];
		participante.medalhasBronze = medalhasBronze[i]; 
		ganhadores[i] = participante; 
	}
	qsort(ganhadores, n+1, sizeof(Pais), compara); 
	for (int i =0; i<=n;  i++){
		if (ganhadores[i].id != 0)
			printf("%d ", ganhadores[i].id);
	}
	printf("\n"); 
	
	return 0;
}
