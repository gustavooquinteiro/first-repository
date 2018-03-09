#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n;
	while (cin >> n && n!=0){
		vector<int> a;
		int q;
		for (int i =0; i< n; i++){
			cin >> q;
			a.push_back(q);
		}
		sort(a.begin(), a.end());
		int cont = 0;
		for (vector<int>::iterator i = a.begin(); i < a.end(); ++i){
			for (vector<int>::iterator j = i + 1; j < a.end(); ++j){
				cont += (a.end() - upper_bound(a.begin(), a.end(), *i + *j));
			}
		}
		cout << cont << endl;
	}
}
