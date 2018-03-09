#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n, a; 
	cin >> n;
	vector<int> v;
	for (int i=0; i<n;i++){
		cin >> a;
		v.push_back(a);
	}
	int busca;
	sort (v.begin(), v.end());
	while (cin>> busca){
		if (binary_search(v.begin(), v.end(), busca)){
			cout << "sim" << endl;
		}else{
			cout << "nao" << endl;
		}
	}


}