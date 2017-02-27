#include <iostream>
#include <cmath>
#include <cstdlib>
#include <I:\Portada.h>

using namespace std;

struct Matriz
{
       int x;
       int y;
       double **AptMat;
};

void Leer(Matriz *AptM);
void Memoria(Matriz *AptM);
void Valores(Matriz *AptM);
bool Validar(Matriz *AptM1,Matriz *AptM2);
void Producto(const Matriz *AptM, const Matriz *AptM2, Matriz *AptMR);
void Imprimir(const Matriz *AptM);

int main(void)
{
    int i;
	bool Flag;
    
    Matriz *AptM1;
    Matriz *AptM2;
    Matriz *AptMR;
    
    AptM1=new Matriz;
    AptM2=new Matriz;
    AptMR=new Matriz;

	Portada();

	system("color fc");
    
    cout<<"Matriz A:"<<endl<<endl;
    Leer(AptM1);
    
    system("cls");
    
    cout<<"Matriz B:"<<endl<<endl;
    Leer(AptM2);
    
    AptMR->x=AptM1->x;
    AptMR->y=AptM2->y;
    
    system("cls");
    
    system("color f0");
    
    Memoria(AptM1);
    Memoria(AptM2);
    Memoria(AptMR);
    
    Flag = Validar(AptM1,AptM2);
    
	if(Flag==true)
	{
    cout<<"Introduzca Valores de Matriz A:"<<endl<<endl;
    Valores(AptM1);
    cout<<endl<<"Introduzca Valores de Matriz B:"<<endl<<endl;
    Valores(AptM2);
    
    system("cls");
    
	Producto(AptM1,AptM2,AptMR);
    
    cout<<"Matriz A:"<<endl<<endl;
    Imprimir(AptM1);
    cout<<endl<<endl<<"Matriz B:"<<endl<<endl;
    Imprimir(AptM2);
    cout<<endl<<endl<<"Matriz Resultante:"<<endl<<endl;
    Imprimir(AptMR);
    cout<<endl<<endl;
	}
	else
	{
	 cout<<"El numero de filas de la matriz B no permite realizar producto matricial"<<endl
		 <<" ya que es distinto a las columnas de la matriz A"<<endl
         <<"Este numero se modificara a "<<AptM1->y<<endl;
     
     AptM2->x=AptM1->y; 

	 cout<<"Introduzca Valores de Matriz A:"<<endl<<endl;
    Valores(AptM1);
    cout<<endl<<"Introduzca Valores de Matriz B:"<<endl<<endl;
    Valores(AptM2);
    
    system("cls");
	Producto(AptM1,AptM2,AptMR);
    
    cout<<"Matriz A:"<<endl<<endl;
    Imprimir(AptM1);
    cout<<endl<<endl<<"Matriz B:"<<endl<<endl;
    Imprimir(AptM2);
    cout<<endl<<endl<<"Matriz Resultante:"<<endl<<endl;
    Imprimir(AptMR);
    cout<<endl<<endl;
	}
    
    for(i=0;i<AptM1->x;i++)
    {
       delete []AptM1->AptMat[i];
    }
    
	for(i=0;i<AptM2->x;i++)
    {    
       delete []AptM2->AptMat[i];
    }
	
	for(i=0;i<AptMR->x;i++)
    {
      delete []AptMR->AptMat[i];
    }
    
	delete []AptM1->AptMat;
    delete []AptM2->AptMat;
    delete []AptMR->AptMat;
    
    delete AptM1;
    delete AptM2;
    delete AptMR;
    
    system("pause");
    return 0;
}

void Leer(Matriz *AptM)
{
     cout<<"Numero de filas: ";
     cin>>AptM->x;
     cout<<endl<<"Numero de columnas: ";
     cin>>AptM->y;
     cout<<endl;
}

void Memoria(Matriz *AptM)
{
     AptM->AptMat=new double*[AptM->x];
     for(int i=0;i<AptM->x;i++)
     {
      AptM->AptMat[i]=new double[AptM->y];
     }
}

void Valores(Matriz *AptM)
{     
     for(int i=0;i<AptM->x;i++)
     {
       cout<<"\nIntroduzca valores de fila "<<i+1<<":\n\n";        
     for(int j=0;j<AptM->y;j++)
     {
     cin>>AptM->AptMat[i][j];
     }
     }
}


bool Validar(Matriz *AptM1,Matriz *AptM2)
{
	bool Bandera;
	
	if(AptM2->x==AptM1->y)
	{
		Bandera = true;
	}
	else
	{
		Bandera = false;
	}

	return Bandera;

}

void Producto(const Matriz *AptM,const Matriz *AptM2,Matriz *AptMR)
{
       for(int i=0;i<AptMR->x;i++)
	   {
		 for(int j=0;j<AptMR->y;j++)
       {
             AptMR->AptMat[i][j]=0;
           for(int k=0;k<AptM2->x;k++)
	   {
		   AptMR->AptMat[i][j]=AptM->AptMat[i][k]*
                                 AptM2->AptMat[k][j]+
                                 AptMR->AptMat[i][j];
	   }
	   }
       }
}

void Imprimir(const Matriz *AptM)
{  

int i,j;
          
   for(i=0;i<AptM->x;i++)
   {
   cout<<endl;
   for(j=0;j<AptM->y;j++)
   {
   cout<<AptM->AptMat[i][j]<<" ";
   }
   }
}
