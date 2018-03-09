#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n, m;
	long long numero, entrega, tempo;
	vector<long long> casas, entregas;

	cin >> n >> m;
	for (int i =0; i< n; i++){
		cin >> numero;
		casas.push_back(numero);
	}
	for (int i =0; i < m; i++){
		cin >> entrega;
		entregas.push_back(entrega);

	}
	tempo = 0;
	vector<long long>::iterator posicaoAtual = lower_bound(casas.begin(), casas.end(), entregas[0]);
	tempo += posicaoAtual - casas.begin();
	for (int i = 1; i< m; i++){
		(posicaoAtual > lower_bound(casas.begin(), casas.end(), entregas[i]))? tempo = tempo + (posicaoAtual - lower_bound(casas.begin(), casas.end(), entregas[i])): tempo = tempo + (lower_bound(casas.begin(), casas.end(), entregas[i]) - posicaoAtual);
		posicaoAtual = lower_bound(casas.begin(), casas.end(), entregas[i]);
	}
	cout << tempo << endl;
}
