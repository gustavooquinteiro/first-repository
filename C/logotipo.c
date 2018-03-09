#include <stdlib.h>
#include <stdio.h>

int main(){
	int k, m, n;
	int x, y; 
	int cont = 0; 
	while (scanf("%d%d", &x, &y) && x!=0 && y!=0){
		int logo[x][y];
		//leio o logotipo
		for (int i=0; i<x; i++){
			for (int j=0; j<y; j++){
				scanf("%d", &logo[i][j]); 
			}
		}
		
		
		scanf("%d%d%d", &k,&m,&n);
		int reg[m][n];
		
	
		//leio as k matrizes m por n
		int contadorLogoOficial = 0;
		for (int l=0; l<k;l++){
			for(int i=0; i<m; i++){
				for(int j=0; j<n;j++){
					scanf("%d", &reg[i][j]);
				}
			}
			int xaux, yaux, xaux2, yaux2;
			xaux = yaux =0;
			for(int i=0; i<m; i++){
				for(int j =0; j<n;j++){
					if(reg[i][j] == logo[xaux][yaux]){
						yaux2 = j+1;
						xaux2 = i;
						yaux++;
						int contadorLogo = 1;
						while (reg[xaux2][yaux2] == logo[xaux][yaux]){
							
							if(xaux2 >= m || yaux2 >= n)
								break;
								
							contadorLogo++;
							yaux++;
							yaux2++;
							
							if(yaux == y){
								xaux = x+1;
								yaux = 0;
								yaux2 = j+1;
								xaux2 = i;
							}
							
							if(contadorLogo == x*y){
								contadorLogoOficial += 1; 
								break;
							}
						}
						xaux = 0;
						yaux = 0;
						i = xaux2;
						j = yaux2;
					
					}
				}
			}
		}
		printf("Logotipo %d\n", ++cont); 
		printf("%d\n\n", contadorLogoOficial); 
	}
	return 0;
}
