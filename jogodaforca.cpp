#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

string palavra_aleatoria();
void mostratraco(string a);
void teste_palavra(string palavra,char letra);


int main(){

   cout << "--------------------------------------------" << endl;
   cout << "|                                          |" << endl;
   cout << "|               JOGO DA FORCA              |" << endl;
   cout << "|                                          |" << endl;
   cout << "--------------------------------------------" << endl;

   vector<char> letra;
   string palavra = palavra_aleatoria();

   int tentativa;

   for(tentativa=1;tentativa<palavra.length();tentativa++)
   {
       cout << palavra ;
       mostratraco(palavra);
       cin >> letra[tentativa-1];

       teste_palavra(palavra,letra,tentativa);
   }





   return 0;
}
void teste_palavra(string palavra,vector<char>& letra,int tentativa)
{

   for(int c=0;c<(palavra.length());c++)
   {  for(int d=0;d<tentativa;d++)
      {
         if(letra[d]==palavra[c]){
            cout << palavra[c];
         }else{
            cout << " __ ";
         }
      }
   }
}
void mostratraco(string a)
{
   for(int c=0;c<(a.length());c++)
   {
      cout<< "__ ";
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
