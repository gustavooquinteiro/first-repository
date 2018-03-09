#include <iostream>
#include <queue>
using namespace std;

struct pos{
    int x;
    int y;
    int quantidade; 
};

int main(){
    int i, j;
    cin >> i >> j;
    queue <pos> possibilidades;
    pos posicao;
    int matriz[i][j]; 
    for (int x=0; x < i; x++){
        for (int y=0; y < j; y++){
            cin >> matriz[x][y];
            if (matriz[x][y] == 3){
                posicao.x = x;
                posicao.y = y;
                posicao.quantidade = 0; 
                possibilidades.push(posicao); 
            }
        }
    }
    while (!possibilidades.empty()){
       pos novaPos = possibilidades.front();    
       if (novaPos.x -1 >=0 && matriz[novaPos.x-1][novaPos.y] != 2){
            if (matriz[novaPos.x-1][novaPos.y] == 0 ){
                cout << ++novaPos.quantidade << endl;
                break;
            } else if (matriz[novaPos.x - 1][novaPos.y] == 1){
                matriz[novaPos.x][novaPos.y] = 2;
                pos novaPosicao; 
                novaPosicao.x= novaPos.x-1;
                novaPosicao.y = novaPos.y;
                novaPosicao.quantidade = ++novaPos.quantidade; 
                possibilidades.push(novaPosicao);
            }
       }
       novaPos = possibilidades.front();
       if (novaPos.x+1 < i && matriz[novaPos.x+1][novaPos.y] != 2 )  {
           if( matriz[novaPos.x+1][novaPos.y] == 0) {
                cout << ++novaPos.quantidade << endl;
                break;
           } else if (matriz[novaPos.x+1][novaPos.y] == 1){
               matriz[novaPos.x][novaPos.y] = 2; 
               pos novaPosicao; 
                novaPosicao.x = novaPos.x+1;
                novaPosicao.y = novaPos.y;
                novaPosicao.quantidade = ++novaPos.quantidade;
                possibilidades.push(novaPosicao);   
           } 
       }
       novaPos = possibilidades.front();
       if (novaPos.y+1 < j && matriz[novaPos.x][novaPos.y+1] != 2){
           if (matriz[novaPos.x][novaPos.y+1] == 0){
               cout << ++novaPos.quantidade << endl;
                break;
           }else  if(matriz[novaPos.x][novaPos.y + 1] == 1){
                matriz[novaPos.x][novaPos.y] = 2;
                pos novaPosicao; 
                novaPosicao.x = novaPos.x;
                novaPosicao.y = novaPos.y+1;
                novaPosicao.quantidade = ++novaPos.quantidade; 
                possibilidades.push(novaPosicao);
            }
       }
       novaPos = possibilidades.front();
       if (novaPos.y -1 >=0 && matriz[novaPos.x][novaPos.y-1] != 2){
            if ( matriz[novaPos.x][novaPos.y-1] == 0){
                cout << ++novaPos.quantidade << endl;
                break;
            }else if(matriz[novaPos.x][novaPos.y - 1] == 1){
                matriz[novaPos.x][novaPos.y] = 2;
                pos novaPosicao; 
                novaPosicao.x= novaPos.x;
                novaPosicao.y = novaPos.y-1;
                novaPosicao.quantidade = ++novaPos.quantidade; 
                possibilidades.push(novaPosicao);
            }
        }
        possibilidades.pop();
    }     
}
