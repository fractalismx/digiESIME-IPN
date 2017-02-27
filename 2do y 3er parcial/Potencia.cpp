#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class Resistencias
{
	private:
		int Tam;
		double *AptR;
	public: 
		Resistencias(int T=1);
		void LeerR(void);
		double SR(void)const;
		void ImprimirR(void)const;
		~Resistencias(void);
};

Resistencias::Resistencias(int T)
{
	Tam=(T<1)?1:T;

	AptR=new double[Tam];
	
	for(int i=0;i<Tam;i++)
	AptR[i]=1.0;
}

void Resistencias::LeerR(void)
{

	cout<<"Introduzca Valores de las Resistencias:"<<endl;
	
    do
	{
	for(int i=0;i<Tam;i++)
	{
	 cin>>AptR[i];
    }
		 
	 if(SR()<=0)
	 {
	 	cout<<"Introduzca sumatoria valida"<<endl;
	 }
	 
	}while(SR()<=0);
    
}

double Resistencias::SR(void)const
{	
  double A;

   A=0.0;
  
   	for(int i=0;i<Tam;i++)
	A=A+AptR[i];
   
   
  return A;
}

void Resistencias::ImprimirR(void)const
{
	cout<<"Sus Valores de Resistencias:"<<endl;
	
	for(int i=0;i<Tam;i++)
	cout<<AptR[i]<<endl;
	
	cout<<endl;
	
	cout<<"Y su sumatoria "
	    <<SR()
		<<endl;
}

Resistencias::~Resistencias(void)
{
	
	delete []AptR;
	
}

class Voltaje
{
	private:
		double V;
	public:
		Voltaje(double V=0.0);
		void LeerV(void);
		double Volt(void)const;
		void ImprimirV(void)const;
		
};

Voltaje::Voltaje(double V)
{
	Voltaje::V = V;
}

void Voltaje::LeerV(void)
{
	cout<<"Introduzca voltaje"<<endl;
	cin>>V;
}

double Voltaje::Volt(void)const
{
	return V;
}

void Voltaje::ImprimirV(void)const
{
	cout<<endl<<"Su voltaje es "<<V<<endl;
}

class Corriente: public Resistencias, public Voltaje
{
  public:
  	    Corriente(int T=1,       //Resistencias 
		          double V=0.0);//Voltaje
        void LeerC(void);
		double CaC(void)const;
		void ImprimirC(void)const;
		~Corriente(void);
};

Corriente::Corriente(int T,double V): Resistencias(T), Voltaje(V)
{
  cout<<"nada"<<endl;	
}

void Corriente::LeerC(void)
{
	LeerR();
	LeerV();
}

double Corriente::CaC(void)const
{
	return(Volt()/SR());
}

void Corriente::ImprimirC(void)const
{
	ImprimirR();
	ImprimirV();
	
	cout<<"Su corriente es "<<CaC()<<endl;
}

Corriente::~Corriente(void)
{
	cout<<"aqui no hay nada"<<endl;
}

class Potencia: public Corriente
{
  public:
  	  Potencia(int T=1, double V=0.0);
      void LeerP(void);
      double CaP(void)const;
      void ImprimirP(void)const;
      ~Potencia(void);
};

Potencia::Potencia(int T,double V):Corriente(T,V)
{
	cout<<"nada"<<endl;
}

void Potencia::LeerP(void)
{
	LeerC();
}

double Potencia::CaP(void)const
{
	return(pow(CaC(),2)*Resistencias::SR());
}

void Potencia::ImprimirP(void)const
{
	ImprimirC();
	
	cout<<"su potencia es "<<CaP()<<endl;
}

Potencia::~Potencia(void)
{
	cout<<"Aqui no hay nada"<<endl;
}

int NR(void);

int main(void)
{
	int N;
	
	Potencia *AptP;
	
	N=NR();
	
	AptP = new Potencia(N);
	
	AptP->LeerP();
	
	system("pause");
	system("cls");
	
	AptP->ImprimirP();
	
	system("pause");
	
	return 0;
}

int NR(void)
{
	int B;
	
	do
	{	
	   cout<<"Introduza numero de resitencias"<<endl;
	   cin>>B;
	   
	   if(B<1)
	   {
	   	cout<<"introduzca valor valido"<<endl;
	   }
	   
    }while(B<1);
    
	system("cls");
	return B;
}
