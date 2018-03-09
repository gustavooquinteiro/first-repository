#include <stdlib.h>
#include <stdio.h>
typedef struct pos{
	int x;
	int y;
	int proxX;
	int proxY;
	}posicaoRobo;
int main(){
	int n, m, s;
	while (scanf("%d%d%d", &n, &m, &s) && n!=0){
		int figurinha; 
		figurinha =0;
		posicaoRobo posicao; 
		char matriz[n][m];
		for (int i =0; i<n; i++){
			for(int j =0; j<m; j++){
				scanf("%c", &matriz[i][j]);
				if (matriz[i][j]!='*' && matriz[i][j]!='.' && matriz[i][j] !='#'){
					posicao.x = i; 
					posicao.y = j;
					switch (matriz[i][j]){
					case 'N':	
						posicao.proxX = i-1;
						posicao.proxY=j; 
						break; 
					case 'S':
						posicao.proxX = i+1;
						posicao.proxY = j;
						break;
					case 'L':
						posicao.proxX=i;
						posicao.proxY=j+1;
						break;
					case 'O':
						posicao.proxX=i;
						posicao.proxY=j-1;
						break;
					}					
				}
			}	
		}
		char orientacao; 
		for (int i =0; i<s; i++){
			scanf ("%c", &orientacao); 
			switch(orientacao){
				case 'D': 
					 if (posicao.proxY==posicao.y) {
                        if (posicao.proxX>posicao.x) {
                            posicao.proxX=posicao.x;
                            posicao.proxY=posicao.y-1;
                        }
                        else {
                            posicao.proxX=posicao.x;
                            posicao.proxY=posicao.y+1;
                        }
                    }
                    else {
                        if (posicao.proxY>posicao.y) {
                            posicao.proxY=posicao.y;
                            posicao.proxX=posicao.x+1;
                        }
                        else {
                            posicao.proxY=posicao.y;
                            posicao.proxX=posicao.x-1;
                        }
                    }
					break; 
				case 'E': 
					  if (posicao.proxX==posicao.x) {
                        if (posicao.proxY>posicao.y) {
                            posicao.proxY=posicao.y;
                            posicao.proxX=posicao.x-1;
                        }
                        else {
                            posicao.proxY=posicao.y;
                            posicao.proxX=posicao.x+1;
                        }
                    }
                    else {
                        if (posicao.proxX>posicao.x) {
                            posicao.proxX=posicao.x;
                            posicao.proxY=posicao.y+1;
                        }
                        else {
                            posicao.proxX=posicao.x;
                            posicao.proxY=posicao.y-1;
                        }
                    }
					break;
				case 'F':
					 if (matriz[posicao.proxX][posicao.proxY]!='#'&&(posicao.proxX<n&&posicao.proxX>-1)&&(posicao.proxY<m&&posicao.proxY>-1)) {
                        if (matriz[posicao.proxX][posicao.proxY]=='*') {
                            matriz[posicao.proxX][posicao.proxY]='.';
                            figurinha++;
                        }
                        if (posicao.proxY==posicao.y) {
                            if (posicao.proxX>posicao.x) {
                                posicao.x=posicao.proxX;
                                posicao.proxX++;

                            }
                            else {
                                posicao.x=posicao.proxX;
                                posicao.proxX--;
                            }
                        }
                        else {
                            if (posicao.proxY>posicao.y) {
                                posicao.y=posicao.proxY;
                                posicao.proxY++;

                            }
                            else {
                                posicao.y=posicao.proxY;
                                posicao.proxY--;
                            }
                        }
                    }
					break; 
				}
			}
			printf ("%d\n", figurinha); 
		}

return 0;
}
