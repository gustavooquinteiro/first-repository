#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    
    while(cin >> n && n != 0){    
        priority_queue <double, vector<double>, greater<double> > venda;
        priority_queue <double, vector<double>, less<double> > compra;	
  
        double resu = 0;
        for (int i = 0; i < n; i++){
            char letra;
            double valor;
            cin >> letra >> valor;
            if (letra == 'C'){
                compra.push(valor);
            } else{
                venda.push(valor);
            }

            if (!compra.empty() && !venda.empty()){
				if (compra.top() >= venda.top()){
					resu += compra.top() - venda.top();
					compra.pop();
					venda.pop();
				}
				else {
					compra.top();
				}

            }
        }
        cout << setprecision(2) << fixed << resu << endl;
    }
}