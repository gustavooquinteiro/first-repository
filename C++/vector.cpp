#include <iostream>
#include <vector>
using namespace std;
int main(){
int d,a,cont=0;
cin >> d;
vector <int> msg; 
vector <int> msgv; 
for (int i =0; i < d; i++){
	cin >> a;
	msg.push_back(a); 
}
for (int i =0; i<d; i++){
	if(msg[i]==1)
		cont++;
	if(i-1>=0 && msg[i-1]==1)
		cont++;
	if(i+1 <= d && msg[i+1]==1)
		cont++;
	
	msgv.push_back(cont);
	cont =0;
}
for (int i =0; i<d; i++){
	cout << msgv[i] << " ";
}
}
