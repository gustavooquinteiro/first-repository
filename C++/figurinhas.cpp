#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int p, c, figurinha;
    while (cin>>p>>c && p!=0){
        set<int> figurinhasPaula;
        set<int> figurinhasClara;
        set<int> universo;
        int intercessao =0; 
        for (int i =0; i<p;i++){
            cin >> figurinha;
            figurinhasPaula.insert(figurinha);
            universo.insert(figurinha);
        }
        for (int i =0; i<c;i++){
            cin >> figurinha;
            figurinhasClara.insert(figurinha);
            universo.insert(figurinha); 
            if(figurinhasPaula.count(figurinha) != 0)
                intercessao++;
        }

        /*for (set<int>::iterator it=figurinhasPaula.begin();it!=figurinhasPaula.end(); it++){
          if (figurinhasClara.find(*it) != figurinhasClara.end())
                intercessao++;
        }*/
        int np = universo.size() - figurinhasPaula.size();
        int nc = universo.size() - figurinhasClara.size();

        cout << min(np, nc) << endl;
    }
}
