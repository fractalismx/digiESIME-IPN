#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>

class Matriz
{
	private: 
		int Ren;
		int Col;
		T **AptMat;
	public: 
		Matriz(int R=2, int C=2);
		Matriz(const Matriz &RefM);
		~Matriz(void);
		void Leer(void);
		void Imprimir(void)const;
		T Suma(void)const;
		
};

template <typename T>
Matriz<T>::Matriz(int R, int C)
{
	Ren=(R<2)?2:R;
	Col=(C<2)?2:C;
	
	AptMat=new double*[Ren];
	
	for(int i=0;i<Ren;i++)
	{
	  AptMat[i]=new T[Col];
    }
	
	for(int j=0;j<Ren;j++)
	{
	  for(int k=0;k<Col;k++)
	  {
	   AptMat[j][k]=0.0;
      }
    }
}

template <typename T>
Matriz<T>::Matriz(const Matriz &RefM)
{
	Ren=RefM.Ren;
	Col=RefM.Col;
	
	AptMat=new T*[Ren];
	
	for(int i=0;i<Ren;i++)
	{
	  AptMat[i]=new T[Col];
    }
	
	for(int j=0;j<Ren;j++)
	{
	  for(int k=0;k<Col;k++)
      {
	   AptMat[j][k]=RefM.AptMat[j][k];
      }
    }
}

template <typename T>
Matriz<T>::~Matriz(void)
{
	for(int i=0;i<Ren;i++)
	{
	  delete []AptMat[i];
    }
    
	delete []AptMat;
}

template <typename T>
void Matriz<T>::Leer(void)
{
	for(int j=0;j<Ren;j++)
	{
	 cout<<"Introduzca valores de renglon "<<j+1<<endl<<endl;
	  for(int k=0;k<Col;k++)
	  {
	   cin>>AptMat[j][k];
      }
     cout<<endl;
	}
}

template <typename T>
T Matriz<T>::Suma(void)const
{
int i,j;
	
T e=0;
	
 for(i=0;i<Ren;i++)
 {
  
  for(j=0;j<Col;j++)
  {
     e=e+AptMat[i][j];
  }
 
 }
 
return e;

}

template <typename T>
void Matriz<T>::Imprimir(void)const
{
	cout<<"Sus renglones fueron "
	    <<Ren<<endl
	    <<"Sus columnas fueron "
	    <<Col<<endl
	    <<"Los elementos de su matriz fueron "<<endl<<endl;
	
	for(int j=0;j<Ren;j++)
	{
	  for(int k=0;k<Col;k++)
	  {
	   cout<<AptMat[j][k]<<"\t";
      }
     cout<<endl;
	}
	
	cout<<endl<<"Y la suma de sus elementos fue "
	    <<Suma()<<endl;
}

void Tam(int &RefR, int &RefC);
int Val(void);

int main (void)
{
	
  Matriz <double> *AptM;
  
  int a,b;
  
  Tam(a,b);
  
  cout<<"Tipo double"<<endl;
  
  AptM=new Matriz<double>(a,b);	
  
  AptM->Leer();
  
  system("pause");
  system("cls");
  
  AptM->Imprimir();
  
  delete AptM;
  
  system("pause");
  
  return 0;
}

void Tam(int &RefR, int &RefC)
{
	cout<<"Introduzca Numero de renglones ";
	RefR=Val();

	cout<<endl<<"Introduzca Numero de columnas ";
	RefC=Val();
	
	system("cls");
}

int Val(void)
{
    int v;
    do
    {   
		cin>>v;
        
		if(v<2)
        cout<<endl<<"Introduzca valor valido"<<endl;
    
	}
	while(v<2);
    
	return v;
}
