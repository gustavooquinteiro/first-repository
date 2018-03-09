#include <iostream>
#include <stack>
#include <string>
using namespace std; 
int main(){
	stack <char> p;  
	int n; 
	cin >> n; 
	string linha;
		cin.ignore();
	for (int i =0; i<n; i++){
        getline(cin, linha); 
		for(int j =0;  j < linha.size(); j++){
            //cout << "ENTREI NO LOOP" << endl;
			if (!p.empty() && linha[j] == p.top()){
			//	cout << "Tirei dessa merda " << linha[j] << endl;
				p.pop(); 
                continue;			
            } 
			if (linha[j] == '*' || linha[j] == '/' || linha[j] == '_' ){
				//cout << "Inseri nessa merda " << linha[j]<< endl;
				p.push(linha[j]); 
			}
		}
	}
	if (p.empty()){
		cout << "C" << endl;
	}else{
		cout << "E" << endl; 
	}
	return 0; 
}
