#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

string palavra_aleatoria();
void mostratraco(pal);

int main(){

   cout << "--------------------------------------------" << endl;
   cout << "|                                          |" << endl;
   cout << "|               JOGO DA FORCA              |" << endl;
   cout << "|                                          |" << endl;
   cout << "--------------------------------------------" << endl;

   char letra;
   string palavra = palavra_aleatoria();

   mostratraco(palavra);
   cin >> letra;

   for(int c=0;c<(palavra.length());c++){
      if(letra==palavra[c]){ cout <<  palavra[c];}else{ cout << "__ ";}
   }
   return 0;
}
void mostratraco(*pal){
   for(int c=0;pal.length();c++){
      cout<< "__ ";
   }
}
string palavra_aleatoria(){
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
