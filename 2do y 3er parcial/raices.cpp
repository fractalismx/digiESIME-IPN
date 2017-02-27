#define _USE_MATH_DEFINES

#include<cmath>
#include<cstdlib>
#include<iostream>

using namespace std;

class Raiz
{
	private:
		double A;
		double B;
		double C;
	
	public:
		Raiz(double a=1.0, double b=1.0, double c=0.0);
		void setA(const double a);
		void setB(const double b);
		void setC(const double c);
		double getA(void);
		double getB(void);
		double getC(void);
		void Leer(void);
		void Imprimir(void)const;
		double Raices1(void)const;
		double R(void)const;
		double Raices2(void)const;
		~Raiz(void);
		
};

Raiz::Raiz(double a, double b, double c)
{
	cout<<"Se esta creando memoria"<<endl<<endl;
	
	A=(a==0)?1.0:a;
	
	B=(b==0)?1.0:b;
	
	C=c;
}

void Raiz::setA(const double a)
{
	A=a;
}

void Raiz::setB(const double b)
{
	B=b;
}

void Raiz::setC(const double c)
{
	C=c;
}

double Raiz::getA(void)
{
	return A;
}

double Raiz::getB(void)
{
	return B;
}

double Raiz::getC(void)
{
	return C;
}

void Raiz::Leer(void)
{
	
	
	cout<<"Este progama calcula las raices de una ecuacion de segundo grado"
	    <<endl
	    <<"Ingrese elemento cuadratico "
		<<endl;
	cin>>A;
	
	cout<<"Ingrese elemento lineal "
	    <<endl;
	cin>>B;
	
	cout<<"Ingrese coeficiente constante"
	    <<endl;
	cin>>C;

}

double Raiz::Raices1(void)const
{
	double x;
	
	if(A==0)
	{
		x=(-1.0*C)/B; //lineal
	}
	else
	{
		x=(-1.0*B)/(2.0*A);  //cuadratica
	}

return x;	
}

double Raiz::R(void)const
{
	return(pow(B,2)-4.0*A*C);  //discriminate
}

double Raiz::Raices2(void)const
{
	double x;	
	
	if(R()>=0)
	{
		x=sqrt(R())/(2.0*A);  //reales
	}
	else
	{
		x=sqrt(abs(R()))/(2.0*A); //imaginarias
	}

return x;

}

void Raiz::Imprimir(void)const
{

	if(A==0&&B==0)
	{

	 cout<<"Esto es imposible de calcular"<<endl;	
	
	}
	else if(A==0)
	{
		
		cout<<"Como la ecuacion ingresada es lineal"
		    <<" solo tiene una raiz, esta es: "
			<<Raices1()
			<<endl;
	
	} 
	else
	{
		cout<<"Su ecuacion cuadratica es "<<endl;
		
		if(R()>0)
		{
			cout<<Raices1()+Raices2()
			    <<" y "
			    <<Raices1()-Raices2()
				<<endl;
		}
		else if(R()==0)
		{
			cout<<"esta ecuacion tiene raices repetidas las cuales son"
			    <<endl
			    <<Raices1()
				<<endl
				<<endl;;
		}
		else
		{
			cout<<Raices1()<<" +/- "
			    <<Raices2()<<'i'
				<<endl
				<<endl;
		}
	}
	
}

Raiz::~Raiz(void)
{
	
	cout<<endl<<"Se esta liberando memoria"<<endl;

}

int Num(void);

int main (void)
{
	
	int N,i;
	
	N=Num();
	
	Raiz *AptC;
	AptC = new Raiz[N];
	
	for(i=0;i<N;i++)
	{
	  
	  AptC[i].Leer();
	  AptC[i].Imprimir();
    
	}
	
	delete []AptC;
	
	return 0;
}

int Num(void)
{
	int N;
	
	cout<<"Ingrese el numero de ecuaciones que quiera calcular"<<endl;
    cin>>N;
	
	return (N);
}
