#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b){
	return (a.first < b.first && a.second < b.second);
}

int main(){
  int t; 
	scanf(" %d", &t);
	for (int i = 0; i < t; i++){
		priority_queue< pair<int, int>, vector< pair<int, int> >, bool(*)(pair<int,int>, pair<int, int>)>pq(cmp);
		pair<int, int> par;
		int n, k;
    scanf(" %d %d", &n, &k);
		int a, y = 0;
		int	limite_inferior = y;
		for (y = 0; y < n; y++){
			scanf(" %d", &a);
			par.first = a;
			par.second = y;
	    pq.push(par); 	      
	    if (y+1 == k){
	    	printf("%d ", pq.top().first);
				k++;
				limite_inferior++;
				bool condicao = true;
				while (condicao){
					if(pq.top().second >= limite_inferior){
						
					}
				}
	    	pq.pop();
	    }
    } 
   printf("\n");   
	}
}