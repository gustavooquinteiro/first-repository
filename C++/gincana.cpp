#include <stdio.h>
#include <vector>

using namespace std;
int main(){
	int n, k, l;
	
	//Leitura das variaveis e alocação dinamica do vector ganhadores
	scanf("%d %d", &n, &k);
	vector <int> ganhadores(k);
    int menor;
	for (int i=0; i<n; i++){
		scanf ("%d", &l); 
		ganhadores[l-1]++; 
	}
menor = ganhadores[0]; 
    
    for (int i = 0; i<k; i++){
        if(menor>ganhadores[i])
            menor = ganhadores[i]; 
    }
	
	printf("%d \n", menor);		
}