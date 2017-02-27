using namespace std;

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "J:\Portad.h"
#define R 0.08205

struct Temp
{
       double Tc;
       double T;
};

void Leer(Temp *AptT);
void Imprimir(const Temp *AptT);
double C1(const Temp *AptT);

struct PT
{
       Temp *AptT;
       double Pc;
       double P;
};

void Leer(PT *AptPT);
void Imprimir(const PT *AptPT);
double C2(const PT *AptPT);

struct Volumen
{
       PT *AptPT;
       double N;
};

void Leer(Volumen *AptV);
void Imprimir(const Volumen *AptV);
double Vol(const Volumen *AptV);

int main(void)
{
    
	Portada();
    
    Volumen *AptV;
    AptV = new Volumen;
    
    system("color f0");
    
    Leer(AptV);
    Imprimir(AptV);
    
    delete AptV->AptPT->AptT;
    delete AptV->AptPT;
    delete AptV;
    
    system ("pause");
    return (0);

}

void Leer(Temp *AptT)
{
     cout<<"Introduzca Temperatura Critica: ";
     cin>>AptT->Tc;
     cout<<endl<<"Intruduzca Temperatura: ";
     cin>>AptT->T;
}

void Imprimir(const Temp *AptT)
{
     cout<<"Temperatura Critica: "<<AptT->Tc<<endl
         <<"Temperatura: "<<AptT->T<<endl;
}

double C1(const Temp *AptT)
{
       return (1-(6.0*pow((AptT->Tc/AptT->T),2)));
}

void Leer(PT *AptPT)
{
     AptPT->AptT = new Temp;
     
     Leer(AptPT->AptT);
     cout<<"Introduzca Presion Critica: ";
     cin>>AptPT->Pc;
     cout<<endl<<"Introduzca Presion: ";
     cin>>AptPT->P;
}

void Imprimir(const PT *AptPT)
{
     Imprimir(AptPT->AptT);
     cout<<"Presion Critica: "<<AptPT->Pc<<endl
         <<"Presion: "<<AptPT->P<<endl;
}
     
double C2(const PT *AptPT)
{
       double c;
       
       c=(9.0*(AptPT->P)*(AptPT->AptT->Tc));
       c=c/((128.0*AptPT->Pc)*(AptPT->AptT->T));
       c=(c*C1(AptPT->AptT))+1.0;
       return c;
}

void Leer(Volumen *AptV)
{
     AptV->AptPT = new PT;
     
     Leer(AptV->AptPT);
     cout<<"Introduzca Numero de moles: ";
     cin>>AptV->N;
     cout<<endl;
     
     system ("cls");
}

void Imprimir(const Volumen *AptV)
{
	system("color cf");
     double z=Vol(AptV);
     
     Imprimir(AptV->AptPT);
     
     cout<<"Numero de moles: "
         <<AptV->N<<endl<<endl
         <<"Volumen del gas: "<<z<<endl<<endl;
}
         
double Vol(const Volumen *AptV)
{
       return(((AptV->N)*R*(AptV->AptPT->AptT->T) *
              C2(AptV->AptPT))/
              (AptV->AptPT->P));
}
