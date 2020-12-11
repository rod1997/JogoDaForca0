#include <iostream>

using namespace std;

int main(){
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

   cout <<  "valor depositado R$" << (valor_ini+(aporte*meses)) << endl;

   cout << "valor de juros adquirido: R$" << (acumulado-(valor_ini+(aporte*meses))) << endl;
   return 0;
}
