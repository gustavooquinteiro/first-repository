#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	int n, k, a, busca;
	scanf("%d %d", &n, &k);
	vector <int> vetor;
	for (int i = 0; i<n; i++){
		scanf("%d", &a);
		vetor.push_back(a);
	}
	
	sort(vetor.begin(), vetor.end());
	for (int i =0; i<k; i++){
		scanf("%d", &busca);
		if (*(lower_bound(vetor.begin(), vetor.end(), busca)) == busca){
				printf("%ld\n",(lower_bound(vetor.begin(), vetor.end(), busca) - vetor.begin()));
		}else{
			printf ("-1\n");
		}
	}
	
}