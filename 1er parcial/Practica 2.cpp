using namespace std;

#include <stdlib.h>
#include <iostream>
#include <cmath>

struct Onda
{
       double Amp;
       double T;
       double Frec;
       double Vel;
       double x;
};

void Portada();
void Leer(Onda *AptMov);
double Calcular(const Onda *AptMov);
void Imprimir(const Onda *AptMov);
double Validar();

int main(void)
{
    Portada();
    
    Onda *Descripcion;
    Descripcion = new Onda; // memoria dinamica
    
    Leer(Descripcion);
    Imprimir(Descripcion);
    
    delete Descripcion; // borra memoria dinamica
    
    system("pause");
    
    return 0;
    
    
}

void Portada()
{
     system ("color cf");
              
         cout<<"\t\t\tInstituto Politecnico Nacional"
		 <<endl
		 <<endl
         <<"\t\tEscuela Superior De Ingenieria Mecanica y Electrica"
		 <<endl
         <<"\t\t\t\t   Plantel Zacatenco"
		 <<endl
		 <<endl
         <<"\t\tMateria:  Programacion Orientada a Objetos"
		 <<endl
		 <<endl
         <<"\t\tProfesora: Ing. Isis Espinoza Salazar"
		 <<endl
		 <<endl
		 <<endl
         <<"\t\t\t\t   Practica 2:"
		 <<endl
         <<"\t\t\t\t-Notacion Punto-"
		 <<endl
		 <<endl
		 <<endl
         <<"\t\tAlumnos:  Gonzalez Morales Cristian Joel"
		 <<endl
		 <<endl
         <<"\t\t          Tapia Marin Pablo"
		 <<endl
		 <<endl;
         
		 system("pause");
         system("cls");

}

void Leer(Onda *AptMov)
{
     system("color fc");
     
     cout<<"Este programa calcula la expresion matematica de una onda"
	     <<endl
		 <<endl
         <<"Introduzca Amplitud:"
		 <<endl;
         cin>>(*AptMov).Amp;
     cout<<endl<<endl
         <<"Introduzca Tiempo donde se desea calcular la posicion:"
		 <<endl;
         cin>>(*AptMov).T;
     cout<<endl<<endl
         <<"Introduzca Frecuencia:"
		 <<endl;
         (*AptMov).Frec=Validar();
     cout<<endl<<endl
         <<"Introduzca Posicion:"
		 <<endl;
         cin>>(*AptMov).x;
     cout<<endl<<endl
         <<"Introduzca Velocidad:"
		 <<endl;
         cin>>(*AptMov).Vel;
}

double Validar()
{
       double valor;
       
       do
       {
              cin>>valor;
              if(valor==0)
              {
                 cout<<"Introduzca valor de frecuencia valido"
					 <<endl
					 <<endl;
						  
              }
       }
       while(valor==0);
       
       return valor;
}

double Calcular(const Onda *AptMov)
{
       double y;
       
       if((*AptMov).x<0)
       {
                y=(2.0*M_PI*(*AptMov).x*(*AptMov).Frec);
                y=y/(*AptMov).Vel;
                y=(2.0*M_PI*(*AptMov).Frec*(*AptMov).T)-y;
                y=(*AptMov).Amp*sin(y*M_PI/180);                  
       }
       else
       {
         
		 y=(2.0*M_PI*(*AptMov).x*(*AptMov).Frec);
         y=y/(*AptMov).Vel;
         y=(2.0*M_PI*(*AptMov).Frec*(*AptMov).T)+y;
         y=(*AptMov).Amp*sin(y*M_PI/180);
       
	   }
       
       return y;
}           
                           

void Imprimir(const Onda *AptMov)
{
     system("cls");
     system ("color f0");
     
     cout<<"Con una Amplitud de:"
	     <<endl
         <<(*AptMov).Amp
		 <<" m,"
         <<endl
		 <<endl
         <<"un Tiempo de:"
		 <<endl
         <<(*AptMov).T
         <<" s,"
		 <<endl
		 <<endl
         <<"una Frecuencia de:"
		 <<endl
         <<(*AptMov).Frec
         <<" c/s,"
         <<endl
		 <<endl
         <<"una Posicion en:"
		 <<endl
         <<(*AptMov).x
         <<" m,"
		 <<endl
		 <<endl
         <<"y una Velocidad de:"
		 <<endl
         <<(*AptMov).Vel
         <<" m/s,"
		 <<endl
		 <<endl
         <<"la Descripcion de la onda en "
         <<(*AptMov).x
         <<"m es de "
		 <<endl
         <<Calcular(AptMov)<<" m"
		 <<endl
		 <<endl;
 }
