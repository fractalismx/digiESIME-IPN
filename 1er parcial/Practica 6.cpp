#include <iostream>
#include <string>
#include <cstdlib>
#include "I:\Portada.hpp"

using namespace std;

struct Tienda
{
       string Nombre;
       double Precio;
       double *AptCosto;
       double *AptV;
       int Dias;
};

void Leer(Tienda *AptIng);
int Numero(void);
double Ventas(const Tienda *AptIng);
double Bruto(const Tienda *AptIng);
double Neto(const Tienda *AptIng);
void Imprimir(const Tienda *AptIng);
void Imprimir2(const double S, double T);

int main(void)
{
    Portada ();
    Tienda *AptIng;
    
    int N;
    int i;
    double S=0;
    double T=0;
    
    cout<<"Este programa proporciona sus ingresos"
	    <<endl
	    <<endl
        <<"Introduzca Numero de productos ";
    
	N=Numero();
    
	AptIng = new Tienda[N];
    
    for(i=0;i<N;i++)
    {
     Leer(&AptIng[i]);
     S=S+Bruto(&AptIng[i]);
     T=T+Neto(&AptIng[i]); 
	  
    }
    
    for(i=0;i<N;i++)
    {
      Imprimir(&AptIng[i]);
    }
    
      Imprimir2(S,T);    
    
    for(i=0;i<N;i++)
    {
     delete AptIng[i].AptCosto;
     delete []AptIng[i].AptV;
    }
    
	delete []AptIng;
    
    system("pause");
    return 0;
}

int Numero(void)
{
     int N;
     cin>>N;
     return (N);
}
     
void Leer(Tienda *AptIng)
{
         
	AptIng->AptCosto = new double;
     
         cout<<"Nombre del producto: ";
         cin.ignore();
         
		 getline(cin,AptIng->Nombre);
         
         cout<<endl
		     <<"Costo unitario: ";
         cin>>*(AptIng->AptCosto);
         
		 cout<<endl
		     <<endl
			 <<"Dias de venta: ";
         cin>>AptIng->Dias;
         
		 cout<<endl
		    <<endl
			<<"Ventas del dia: "
			<<endl;
         
         AptIng->AptV = new double[AptIng->Dias];
         
         for(int i=0;i<(AptIng->Dias);i++)
         {
         cin>>AptIng->AptV[i];
         }
        
         
         cout<<endl<<endl<<"Precio al publico"<<endl;
         cin>>AptIng->Precio;
         
		 system("cls");
}

double Ventas(const Tienda *AptIng)
{
       double Z=0;

       for(int i=0;i<AptIng->Dias;i++)
       {
       Z=Z+(AptIng->AptV[i]);
       }
       
	   return Z;     
}

double Bruto(const Tienda *AptIng)
{              
       return (Ventas(AptIng)*(AptIng->Precio));     
}

double Neto(const Tienda *AptIng)
{
       return (Bruto(AptIng)-
              Ventas(AptIng)*(*(AptIng->AptCosto)));
}

void Imprimir(const Tienda *AptIng)
{
     cout<<"====="
	     <<AptIng->Nombre
		 <<"====="
	     <<endl
		 <<endl
         <<"Costo Unitario:    $"
		 <<*(AptIng->AptCosto)
		 <<endl
         <<"Precio al publico: $"
		 <<AptIng->Precio
		 <<endl
         <<"Total Ventas:      "
		 <<Ventas(AptIng)
		 <<endl
		 <<endl;
}

void Imprimir2(const double S, double T)
{
     cout<<"Ingreso Bruto:     $"<<S<<endl;
                    if(T<0)
                    {
                           T=T*-1.0;
                          cout<<"Tiene perdida de:  $"<<T<<endl<<endl;
                    }
					else if(T==0)
					{
						cout<<" Negocio sin ganancias "<<endl; 
					}
                    else
                    {
                         cout<<"Ingreso Neto:      $"<<T<<endl<<endl;
                    }

}
