using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>
 struct Tienda
{
       string Nombre; 
       double Precio;
       double *AptV;
       int Dias;
};

void Leer(Tienda *AptIng);
int Numero(void);
double Suma(const Tienda *AptIng);
void Imprimir(const Tienda *AptIng);




int main(void)
{
    Tienda *AptIng;
    
    int N;
    int i;
    cout<<"Este programa proporciona sus ingresos"
	    <<endl
		<<endl
        <<"Introduzca Numero de productos"
		<<endl;
    N=Numero();
    AptIng = new Tienda[N];
    double S=0;
    
    
    
    for(i=0;i<N;i++)
    {
                    Leer(&AptIng[i]);
                    S=S+Suma(&AptIng[i]);  
    }      

cout<<"Valor Suma "<<S<<endl;


    for(i=0;i<N;i++)
    
    Imprimir(&AptIng[i]);
    
    
    
    
    delete []AptIng->AptV;
    delete []AptIng;
   
    
 system("pause");
    return 0;   
    
}


void Leer(Tienda *AptIng)
{
     
         cout<<"Introduzca nombre del producto"
		     <<endl;
         cin.ignore();
         getline(cin,AptIng->Nombre);
         
         cout<<endl
		     <<endl
			 <<"Introduzca el numero de dias en que se vendio el producto"
			 <<endl;
         
         cin>>AptIng->Dias;
         cout<<endl
		     <<endl
			 <<"Introduzca ventas por dia"
			 <<endl;
         
         AptIng->AptV = new double[AptIng->Dias];
         
         for(int i=0;i<(AptIng->Dias);i++)
         cin>>AptIng->AptV[i];
         
         cout<<endl
		     <<endl
			 <<"Introduzca precio al publico"
			 <<endl;
         cin>>AptIng->Precio;
         
         
         system("cls");
 }
 
int Numero(void)
{
    int N;
    cin>>N;
    system("cls");
   
    return(N);
}

double Suma(const Tienda *AptIng)
{
double Z=0;

               for(int i=0;i<AptIng->Dias;i++)
               {
                       Z=Z+(AptIng->AptV[i]);
               }
      return Z*AptIng->Precio;     
}


void Imprimir(const Tienda *AptIng)
{
        cout<<"Precio al publico: "
		    <<AptIng->Precio
			<<endl;
         
		 for(int i=0;i<AptIng->Dias;i++)
               
                      cout<<(AptIng->AptV[i])<<endl;
         
         cout<<Suma(AptIng);

}

