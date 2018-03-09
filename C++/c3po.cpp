#include <iostream>
#include <map>
using namespace std;
int main(){
  int t, p, l;
  cin >> t;
  for (int i = 0; i< t; i++){
    cin >> p >> l;
    string tatooines, traducao;

    map <string, string> dicionario;
    for (int y = 0; y < p; y++) {
      cin >> tatooines;
      cin.ignore();
      getline(cin, traducao);
      dicionario[tatooines] = traducao;
    }
    for (int j = 0; j < l; j++) {
      string texto, resposta;
      getline(cin, texto);
      string palavra;
      for (int k = 0; k < texto.size(); k++) {
        if (texto[k] != ' '){
          palavra += texto[k];
        }else{
          if (dicionario.find(palavra) != dicionario.end()){
            resposta += dicionario.find(palavra)->second + " ";
          }else{
            resposta += palavra + " ";
          }
          palavra = "";
        }
      }
      if (dicionario.find(palavra) != dicionario.end()){
        resposta += dicionario.find(palavra)->second;
      }else{
        resposta += palavra;
      }
      cout << resposta << endl;
      resposta = "";
    }
    cout << endl;
  }
}
