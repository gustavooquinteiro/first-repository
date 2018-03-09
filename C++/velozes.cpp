#include <iostream>
#include <stack>
using namespace std;
int main(){
	
	int n; 

	while(cin >> n && n!=0){
		stack <int> aux;
		int a, menor = 1;
		for (int i=0; i<n; i++){
			cin >> a; 
			if (a == menor){
				menor++;	 
			} else{
				aux.push(a); 
			}
			while(!aux.empty()){
				if(aux.top() == menor){
					aux.pop();
					menor++;
				} else{
					break;
				}
			}
		}
	
		if (aux.empty()){
			cout << "yes" << endl; 
		} else{
			cout << "no" << endl;
		}

	}
}
