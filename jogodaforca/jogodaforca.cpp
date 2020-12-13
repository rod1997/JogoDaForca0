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
   int conta;
   char letra;
   int vetor[palavra.length()];
   for(int d=0;d<(palavra.length());d++){ vetor[d]=0; }

   /*cout << palavra << endl;*/
   mostratraco(palavra);

   for(int r=0;r<(palavra.length()+2);r++){
       cout << endl << endl << "digite sua letra:" ;
       cin >> letra;
       cout << endl;
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
      if(r>2){
         conta=0;
         for(int h=0;h<(palavra.length());h++){
             (vetor[h]>0)?conta++:conta--;
         }
         if(conta==(palavra.length())){
            r=r+10;
         }
      }
   }

   if(conta==(palavra.length())){
         cout << endl << endl << "PARABENS!! vc ganhou" << endl << endl;
   }else{
        cout << endl<< endl << "vc perdeu" << endl << "palavra:" << palavra << endl;
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
