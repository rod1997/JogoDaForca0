#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

string palavra_aleatoria();
void mostratraco(string palavra);
int main(){

   cout << "--------------------------------------------" << endl;
   cout << "|                                          |" << endl;
   cout << "|               JOGO DA FORCA              |" << endl;
   cout << "|                                          |" << endl;
   cout << "--------------------------------------------" << endl;

   string palavra = palavra_aleatoria();

   char letra;
   int vetor[palavra.length()];
   for(int d=0;d<(palavra.length());d++){ vetor[d]=0; }

   cout << palavra << endl;
   mostratraco(palavra);

   for(int r=0;r<(palavra.length());r++){
       cin >> letra;
       for(int c=0;c<(palavra.length());c++){
           if(letra==palavra[c]){
               vetor[c]=1;
           }
       }
       for(int t=0;t<(palavra.length());t++){
           if(vetor[t]==1){
               cout << " " << palavra[t] << " ";
           }else{
               cout << " __ ";
           }
       }
   }

   return 0;
}
void mostratraco(string palavra){
   for(int c=0;c<(palavra.length());c++){
      cout << " __ ";
   }
}
string palavra_aleatoria()
{
   vector<string> palavras;
   string linha;

   ifstream arquivo;

   arquivo.open("palavras.txt");
   if(arquivo.is_open()){
      while(getline(arquivo,linha)){
         palavras.push_back(linha);
      }
      arquivo.close();
   }else{
      cout << "arquivo nao encontrado";
   }
   unsigned seed=time(0);
   srand(seed);
   int num_ale=rand()%17;

   return palavras[num_ale];
}
