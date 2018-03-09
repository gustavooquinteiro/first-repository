#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b){
	return (a.first <  b.first) || (a.first == b.first && a.second < b.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t; 
	cin >> t;
	for (int i = 0; i < t; i++){
		priority_queue<pair<int, int>, vector< pair<int, int> >, bool(*)(pair<int,int>, pair<int, int>)>pq(cmp);
		int n, k;
        cin >> n >> k;
		int a; 
        int limite_inferior = 0;
        pair<int, int> par;
		for (int i = 0; i < n; i++){
			cin >> a;
			par.first = a;
			par.second = i;
			pq.push(par); 
			if ( i+1 == k ){
                bool c = true;
                int top;
                   while(c){
                 	if (pq.top().second >= limite_inferior){
                 		top = pq.top().first; 
                 		c = false;
                 	}else{

                 		pq.pop();
                 	}

                }
                cout << top << " "; 
                limite_inferior++;
                k++; 
            }
        }
        cout << endl;
	}
}
