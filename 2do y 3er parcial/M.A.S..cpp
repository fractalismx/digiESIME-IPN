#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include "I:\Portada.hpp"

class Periodo
{
  
  private:
          double F;
          double *AptR;
          double T;
  
  public:
         Periodo(double f=0.0, double t=0.0);
         Periodo(const Periodo &RefP);
         void setFrecuencia(const double F);
         void setTiempo(const double T);
         void setRadio(const double R);
         double getFrecuencia(void)const;
         double getTiempo(void)const;
         double getRadio(void)const;
         void Leer(void);
         double Validar(void)const;
         double A (void)const;
         double EL (void)const;
         double Ti(void)const;
         void Imprimir(void)const;
         ~Periodo(void);

};

Periodo::Periodo(double f,double t)
{
    cout<<"Aqui actua el constructor normal"<<endl<<endl;
	AptR = new double;
	
	*AptR = 0.0;
	F=(f<0)?0.0:f;
	T=(t<0)?0.0:t;
}

Periodo::Periodo(const Periodo &RefP)
{
	cout<<"Aqui actua el constructor de copia"<<endl<<endl;
	AptR = new double;
	
	*AptR=*RefP.AptR;
	
	F=RefP.F;
	T=RefP.T;
}

void Periodo::setFrecuencia(const double F)
{
	Periodo::F=F;
}

void Periodo::setTiempo(const double T)
{
	Periodo::T=T;
}

void Periodo::setRadio(const double R)
{
	*AptR=R;
}

double Periodo::getFrecuencia(void)const
{
	return F;
}

double Periodo::getTiempo(void)const
{
	return T;
}

double Periodo::getRadio(void)const
{
	return *AptR;
}

void Periodo::Leer (void)
{
    
    cout<<"Este programa calcula la Frecuancia (F), la Elongacion (EL) y el periodo (T)"
        <<endl
		<<endl;

	cout<<"Introduzca Frecuencia en Hertz (F)"
	    <<endl;
	F=Validar();
	cout<<endl;

    cout<<"Introduzca Radio en Metros (r)"
	    <<endl;
	*AptR=Validar();
	cout<<endl;
	
	cout<<"Introduzca Tiempo en Segundos (t)"
	    <<endl;
	T=Validar();
	cout<<endl;
	
	system("cls");

}

double Periodo::Validar(void)const
{

double V;
   
 do
 {
  cin>>V;

    if(V<0)
     {
       
       cout<<"valor invalido"
       <<endl
       <<"introduzca nuevo valor"
       <<endl;

     }
 }
 while(V<0);
         
return V;
}

double Periodo::A(void)const
{
	
	double x;
	
	x=2.0*M_PI*F*T;
	
	return((-4.0)*pow(M_PI,2.0)
	            *pow(F,2)
				*(*AptR)*
	            cos(x));
	            
}

double Periodo::EL(void)const
{
	
	return((*AptR)*cos(2*M_PI *F*T));
				
}


double Periodo::Ti(void)const
{
	double C;
	
	C=sqrt(EL() / ((-1.0)*A()));
	
	return((2.0)*M_PI*C);
				       
}

void Periodo::Imprimir(void)const
{
     system("color cf");
    
	 cout<<"La frecuencia es "
	     <<endl
	     <<F
		 <<" Hz"
		 <<endl
         <<endl
	     <<"El Radio es "
		 <<endl
	     <<*AptR
		 <<" m"
		 <<endl
		 <<endl
	     <<"El tiempo "
		 <<endl
		 <<endl
	     <<T
		 <<" s"
		 <<endl
		 <<endl
	     <<"La aceleracion es "
         <<A()
         <<" m/(s^2)"
         <<endl
         <<endl
         <<"La elongacion es "
         <<EL()
         <<" m"
		 <<endl
		 <<endl;
		 
         if(A()==0||(A()==0&EL()==0))
		 {
                   cout<<"El periodo el imposible de calcular"
                   <<endl
                   <<endl;
         }
		 else
		 {
	     
         cout<<"Y el periodo "
		 <<Ti()
		 <<" 1/s"
		 <<endl
		 <<endl;
         
         }
}

Periodo::~Periodo(void)
{
	cout<<endl<<"Se esta liberando memoria"<<endl<<endl;
	delete AptR;
}

int main(void)
{
	
	Portada();
	
	system("color f0");
	
	Periodo *AptP;
	
	AptP = new Periodo;
	
	AptP->Leer();
	AptP->Imprimir();
	
	system ("pause");
	system("CLS");
	
	
	Periodo *AptP1 = new Periodo(*AptP);
	
	AptP1->Imprimir();
	
	system("pause");

	delete AptP;
	delete AptP1;
    
    system("pause");	
	
	return 0;
		
}

