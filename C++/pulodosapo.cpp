#include <iostream>
#include <vector>
using namespace std;
int main(){
	
	int n, m, pos, d;
	cin >> n >> m;
	vector <int> pedras(n);

	for (int i =0; i<m; i++){
		cin >> pos >> d;
		int aux =pos-1;
		pedras[aux] = 1; 
		while (aux+d < n){
		 	aux+=d; 
			pedras[aux] = 1;
		}
		aux=pos-1;
		while(aux-d >= 0){
		 	aux-=d;
		 	pedras[aux] = 1;	
		} 
	}
	for (int i =0; i<n; i++){
		cout << pedras[i]<< endl; 
	}

}