#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n, k, numero;
	cin >> n >> k;
	vector<int> v;
	for (int i =0; i<n; i++){
		cin >> numero;
		v.push_back(numero);
	}
	sort(v.begin(), v.end());
	int cont =0;
	for (int i =0; i<v.size(); i++){
		if (binary_search(v.begin(), v.end(), v[i]-k))
			cont++;
	}
	cout << cont<< endl;
}