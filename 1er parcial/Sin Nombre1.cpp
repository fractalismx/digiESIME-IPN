#define USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "C:\Documents and Settings\ALUMNO\Escritorio\Portada.hpp"

using namespace std;

class Vel_I
{
	private:
		double V;
	public:
		Vel_I(double Vel =1.0);
		void LeerV(void);
		double Val(void);
		double Velocidad(void)const;
        void ImprimirV(void)const;	
};

Vel_I::Vel_I(double Vel)
{
	V=(Vel<=0)?1:Vel;
}

void Vel_I::LeerV(void)
{
	cout<<"Ingrese Velocidad"
	    <<endl;
	V=Val();
}

double Vel_I::Val(void)
{
	double Valor;
	
	do
	{
	  cin>>Valor;
	
	  if(Valor<=0)
	  {
	  	cout<<"Valor invalido. Introduzca nuevo valor"<<endl;
	  }
    }while(Valor<=0);
    
return Valor;

}

double Vel_I::Velocidad(void)const
{
	return V;
}

void Vel_I::ImprimirV(void)const
{
	cout<<"Su velocidad fue "
	    <<V
		<<endl;
}

class Angulo: public Vel_I
{
	private:
		double A;
	public:
        Angulo(double V=1.0, double Ang=1.0);
		void LeerA(void);
		double Ang(void)const;
		double Conversion(void)const;
		void ImprimirA(void)const;
};

Angulo::Angulo(double V,double Ang): Vel_I(V)
{
           A=(Ang<=0)?1:Ang;        
}

void Angulo::LeerA(void)
{
	LeerV();
	
	cout<<"Ingrese Angulo"
	    <<endl;
	A=Val();
	
}

double Angulo::Ang(void)const
{
	return A;
}

double Angulo::Conversion(void)const
{
	return(A*M_PI/180);
}

void Angulo::ImprimirA(void)const
{
	ImprimirV();
	
	cout<<"Su Angulo fue "
	    <<A
		<<endl;
}

class Tiro: public Angulo
{
	private:
		double g;
	public:
        Tiro(double V=1.0, double Ang=1.0,double gr=0.0);
		void Leer(void);
		double T(void)const;
		double H(void)const;
		double R(void)const;
		void Imprimir(void)const;
};

Tiro::Tiro(double V, double Ang, double gr):Angulo(V,Ang)
{
          g=gr;        
}

void Tiro::Leer(void)
{
	LeerA();
	
	cout<<"Ingrese Gravedad "
	    <<endl;
	cin>>g;
}

double Tiro::T(void)const
{
	return(((2.0*Velocidad()*sin(Conversion()))/g));
}

double Tiro::H(void)const
{
	return(pow(Velocidad()*sin(Conversion()),2)/(2.0*g));
}

double Tiro::R(void)const
{
	return((sin(2.0*Conversion())*pow(Velocidad(),2))/g);
}

void Tiro::Imprimir(void)const
{
	ImprimirA();
	
	cout<<"Su tiempo es "
	    <<T()
	    <<endl
	    <<"Su Altura maxima "
	    <<H()
	    <<endl
	    <<"Su alcanze maximo fue "
	    <<R()
	    <<endl;
	    
}

int main(void)
{
	Portada();
	
	system("color f0");
	
	Tiro *AptT;
	AptT = new Tiro;
	
	AptT->Leer();
	
	system("pause");
	system("cls");
	
	AptT->Imprimir();
	
	delete AptT;
	
	system("pause");
	return 0;
	
}
