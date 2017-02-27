using namespace std;

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <H:\Practica 3\Portada.H>

struct Circuito
{
       double Voltaje;
       double Resist;
       double Indu;
       double Capa;
       double Frec;
};

void Leer(Circuito *AptInt);
void Imprimir(const Circuito *AptInt);
double Validar();
double Calcular(const Circuito *AptInt);

int main(void)
{
    
    Portada();
    
    Circuito *Formula;
    Formula = new Circuito;
    
    Leer(Formula);
    Imprimir(Formula);
    
    delete Formula;
    
    system("PAUSE");
    system("cls");
    
    return 0;
}


void Leer(Circuito *AptInt)
{
     system("color fc");
     
     cout<<"Este programa calcula la Intensidad de Corriente en un circuito CA"
	     <<endl
		 <<endl
         <<"Introduzca Voltaje:"
		 <<endl;
         cin>>AptInt->Voltaje;
         cout<<endl
		     <<endl
		     <<"Introduzca Resistencia:"
			 <<endl;
         cin>>AptInt->Resist;
         cout<<endl
		     <<endl
			 <<"Introduzca Inductancia:"
			 <<endl;
         cin>>AptInt->Indu;
         cout<<endl
		     <<endl
			 <<"Introduzca Capacitancia:"
			 <<endl;
         AptInt->Capa=Validar();
         cout<<endl
		     <<endl
			 <<"Introduzca Frecuencia:"
			 <<endl;
         AptInt->Frec=Validar();
}

double Validar()
{
       double valor;
	
	do
	{
		cin>>valor;
		if(valor==0)
		{
		cout<<"Introduzca valor valido"<<endl<<endl;
        }
        
	}
	while(valor==0);
    
    return(valor);
}
    
void Imprimir(const Circuito *AptInt)
{
     system("cls");
     
     cout<<"Voltaje:"
	     <<endl
         <<AptInt->Voltaje
		 <<endl
         <<endl
         <<"Resistencia:"
		 <<endl
         <<AptInt->Resist
		 <<endl
         <<endl
         <<"Inductancia:"
		 <<endl
         <<AptInt->Indu
		 <<endl
         <<endl
         <<"Capacitancia:"
		 <<endl
         <<AptInt->Capa
		 <<endl
         <<endl
         <<"Frecuencia:"
		 <<endl
         <<AptInt->Frec
		 <<endl
		 <<endl
         <<endl
         
         <<"Intensidad de Corriente: "
		 <<endl
         <<Calcular(AptInt)<<"  A"
		 <<endl
		 <<endl;
		 
}

double Calcular(const Circuito *AptInt)
{
       double Corriente;
       Corriente=(1.0/(2*M_PI*(AptInt->Frec)*(AptInt->Capa)));       
       Corriente=(2.0*M_PI*(AptInt->Frec)*(AptInt->Indu))-Corriente;
       Corriente=pow(AptInt->Resist,2)+pow(Corriente,2);
       Corriente=sqrt(Corriente);
       Corriente=AptInt->Voltaje/Corriente;
       
       return(Corriente);
}     
