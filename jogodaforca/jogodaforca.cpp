#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstring>
using namespace std;

/*==============================PROTOTIPOS DAS FUNÇOES============================*/

string palavra_aleatoria(int num_ale);/* retorna alguma paravra aleatoria do banco de palavras */

void mostratraco(string palavra); /* para mostrar traços iniciais*/

int numeroaleatorio();

void mostradica(int num_ale);

/*==============================FUNÇÂO PRINCIPAL===================================*/

int main()
{
   cout << "--------------------------------------------" << endl;
   cout << "|                                          |" << endl;
   cout << "|               JOGO DA FORCA              |" << endl;
   cout << "|                                          |" << endl;
   cout << "--------------------------------------------" << endl;

   int num_ale=numeroaleatorio();
   string palavra = palavra_aleatoria(num_ale);

   int conta_vetor;
   char letra;

   mostradica(num_ale);

   /* cada posicao do vetor será usada como parametro para verificaçao se determinada letra ja foi descoberta (1 sim, 0 não)*/
   int vetor[palavra.length()];

   /*loop para zerar todas posiçoes do vetor*/
   for(int d=0;d<(palavra.length());d++){ vetor[d]=0;}

   mostratraco(palavra);

   /*loop principal*/
   for(int r=0;r<(palavra.length()+2);r++)
   {
       cout << endl << endl << "digite sua letra:" ;
       cin >> letra;
       cout << endl;

       /*loop para varedura e atribuiçao em respectiva posiçao no vetor, se letra foi achada(1)*/
       for(int c=0;c<(palavra.length());c++)
       {
           if(letra==palavra[c])
           {
               vetor[c]=1;
           }
       }

       /*loop para varedura e saida na tela das respectivas letra achadas e nao achadas(vazio)*/
       for(int t=0;t<(palavra.length());t++)
       {
           if(vetor[t]==1)
           {
               cout << " " << palavra[t] << " ";
           }else
           {
               cout << " __ ";
           }
       }

      /*faz a verificaçao do andamento do looping e varedura no vetor para ver se todas as letras ja foram achadas*/
      if(r>2)
      {
         conta_vetor=0;
         for(int h=0;h<(palavra.length());h++)
         {
             (vetor[h]>0)?conta_vetor++:conta_vetor--;
         }
         if(conta_vetor==(palavra.length()))
         {
            r=r+10;/*variavel "r" faz controle do loop*/
         }
      }
   }

   if(conta_vetor==(palavra.length()))
   {
         cout << endl << endl << "PARABENS!! vc ganhou" << endl << endl;
   }else
   {
        cout << endl<< endl << "vc perdeu" << endl << "palavra:" << palavra << endl;
   }

   return 0;
}
/*=====================================FUNÇOES===========================================*/

void mostradica(int num_ale)
{
   if(num_ale<10){
         cout << endl << "dica: UMA FRUTA..." << endl;
   }else if(num_ale>10 && num_ale<20){
         cout << endl << "dica: UM ANIMAL..." << endl;
   }else{
         cout << endl << "dica: UM PAIS.." << endl;
   }
}


int numeroaleatorio()
{
   unsigned seed=time(0);
   srand(seed);
   int num_ale=rand()%17;

   return num_ale;
}
void mostratraco(string palavra){
   for(int c=0;c<(palavra.length());c++){
      cout << " __ ";
   }
}


string palavra_aleatoria(int num_ale)
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

   return palavras[num_ale];
}
