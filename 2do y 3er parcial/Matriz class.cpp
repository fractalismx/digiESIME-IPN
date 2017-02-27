#include <iostream>
#include <cstdlib>

using namespace std;

class Matriz
{
	private: 
		int Ren;
		int Col;
		double **AptMat;
	public: 
		Matriz(int R=2, int C=2);
		Matriz(const Matriz &RefM);
		void Leer(void);
		void Imprimir(void)const;
		bool Validar(Matriz *AptM2)const;
		void Producto(Matriz *AptM1, Matriz *AptM2);
		~Matriz(void);
};

Matriz::Matriz(int R, int C)
{
	Ren=(R<2)?2:R;
	Col=(C<2)?2:C;
	
	AptMat=new double*[Ren];
	
	for(int i=0;i<Ren;i++)
	{
	  AptMat[i]=new double[Col];
    }
	
	for(int j=0;j<Ren;j++)
	{
	  for(int k=0;k<Col;k++)
	  {
	   AptMat[j][k]=0.0;
      }
    }
}

Matriz::Matriz(const Matriz &RefM)
{
	Ren=RefM.Ren;
	Col=RefM.Col;
	
	AptMat=new double*[Ren];
	
	for(int i=0;i<Ren;i++)
	{
	  AptMat[i]=new double[Col];
    }
	
	for(int j=0;j<Ren;j++)
	{
	  for(int k=0;k<Col;k++)
      {
	   AptMat[j][k]=RefM.AptMat[j][k];
      }
    }
}

void Matriz::Leer(void)
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

void Matriz::Imprimir(void)const
{
	for(int j=0;j<Ren;j++)
	{
   	 cout<<endl;
	  for(int k=0;k<Col;k++)
	  {
	   cout<<AptMat[j][k]<<' ';
	  }
    }
}

bool Matriz::Validar(Matriz *AptM2)const
{
	return (AptM2->Ren==Col);
}

void Matriz::Producto(Matriz *AptM1, Matriz *AptM2)
{
	for(int i=0;i<Ren;i++)
	  for(int j=0;j<Col;j++)
	  {
	    for(int k=0;k<AptM2->Ren;k++)
	        AptMat[i][j]=(AptM1->AptMat[i][k]*AptM2->AptMat[k][j])+
		               AptMat[i][j];
      }
      
 
}

Matriz::~Matriz(void)
{
	for(int i=0;i<Ren;i++)
	{
	  delete []AptMat[i];
    }
    
	delete []AptMat;
}

void Tam(int &RefR, int &RefC);

int main(void)
{
	
	Matriz *AptM1;
	Matriz *AptM2;
	Matriz *AptM3;
	
	int NR1, NR2, NC1, NC2;
	bool flag;
	
	system("color f0");
	
	cout<<"Matriz 1"<<endl;
	
	Tam(NR1,NC1);
	
	cout<<"Matriz 2"<<endl;
	Tam(NR2,NC2);
	
	AptM1=new Matriz(NR1,NC1);
	AptM2=new Matriz(NR2,NC2);
	AptM3=new Matriz(NR1,NC2);
	
	flag=AptM1->Validar(AptM2);
	
	if(flag==false)
	{
		cout<<"Duhhhhhhhhhhhhhhhh"<<endl;
	}
	else
	{
		system("color fc");		
		
		cout<<"Introduzca valores de la Matriz 1:"<<endl<<endl;
		AptM1->Leer();
		
		system("cls");
		
		cout<<"Introduzca valores de la Matriz 2:"<<endl<<endl;
		AptM2->Leer();
		
		system("cls");
		
		AptM3->Producto(AptM1,AptM2);
		
		cout<<"Matriz 1"<<endl;
		AptM1->Imprimir();
		
		cout<<endl<<"Matriz 2"<<endl;
		AptM2->Imprimir();
		
		cout<<endl<<"Matriz Resultante"<<endl;
		AptM3->Imprimir();
		cout<<endl;
	}
		
	delete AptM1;
	delete AptM2;
	delete AptM3;
		
	return 0;
}

void Tam(int &RefR, int &RefC)
{
	cout<<"Introduzca Numero de renglones ";
	cin>>RefR;

	cout<<endl<<"Introduzca Numero de columnas ";
	cin>>RefC;
	
	system("cls");
}
