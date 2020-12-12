#include <iostream>
#include <string>
using namespace std;

int main(){
    repetir:
    int  valor_ini, aporte, meses;
    float taxa, acumulado;

    cout << "valor inicial:";
    cin >> valor_ini;

    cout << "aporte:";
    cin >> aporte;

    cout <<  "meses:";
    cin >> meses;

    cout <<  "taxa ao ano:";
    cin >> taxa;

    for(int c=0; c<meses; c++){
        if(c<1){
           acumulado=valor_ini*((taxa/100)/12)+valor_ini;
        }else{
           acumulado=acumulado*((taxa/100)/12)+acumulado+aporte;
        }
    printf(" mes %d RS%.2f\n",c,acumulado);
    }

   cout << endl <<  "valor depositado R$" << (valor_ini+(aporte*meses)) << endl;

   cout << "valor de juros adquirido: R$" << (acumulado-(valor_ini+(aporte*meses))) << endl;

   string opcao;
   cout << endl << "deseja refazer os calculos?[s/n]";cin >> opcao;

   if(opcao=="s" || opcao=="S"){
      goto repetir;
   }else{
       cout << "saindo do programa" << endl;
   }
   return 0;
}

