using namespace std;

#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>


struct Periodo
{
  
  double F;
  double r;
  double t;
  
};

struct Resultados
{
  
  double T;
  double EL;
  double a;
  	
};

void Leer (Periodo *AptDatos);
void A (const Periodo *AptDatos, Resultados *AptRes);
void Llenar (const Periodo *AptDatos, Resultados *AptRes);
void Imprimir(const Periodo *AptDatos, Resultados *AptRes);
void EL (const Periodo *AptDatos, Resultados *AptRes);
void T (const Periodo *AptDatos, Resultados *AptRes);


int main(void)
{
	
	Portada();
	
	system("color f0");
	
	Periodo *AptD;
	Resultados *AptR;
	
	AptD = new Periodo;
	AptR = new Resultados;
	
	Leer(AptD);
	Llenar(AptD, AptR);
	Imprimir(AptD, AptR);
	
	system ("pause");
	
	delete AptD;
	delete AptR;
	
}


void Leer (Periodo *AptDatos)
{
    
    cout<<"Este programa calcula la Frecuancia (F), la Elongacion (EL) y el periodo (T)"
        <<endl
		<<endl;

	cout<<"Introduzca Frecuencia en Hertz (F)"
	    <<endl;
	cin>>AptDatos->F;
	cout<<endl;

    cout<<"Introduzca Radio en Metros (r)"
	    <<endl;
	cin>>AptDatos->r;
	cout<<endl;
	
	cout<<"Introduzca Tiempo en Segundos (t)"
	    <<endl;
	cin>>AptDatos->t;
	cout<<endl;
	
	system("cls");

}

void A(const Periodo *AptDatos, Resultados *AptRes)
{
	
	double x;
	
	x=2.0*M_PI*AptDatos->F*AptDatos->t;
	
	AptRes->a=(-4.0)*pow(M_PI,2.0)
	            *pow(AptDatos->F,2)
				*AptDatos->r*
	            cos(x);
	            
}

void EL (const Periodo *AptDatos, Resultados *AptRes)
{
	
	AptRes->EL = AptDatos->r*
	            cos(2*M_PI *AptDatos->F 
				*AptDatos->t);
				
}


void T (const Periodo *AptDatos, Resultados *AptRes)
{
	double C;
	
	C=sqrt((AptRes->EL) / 
	       ((-1.0)*AptRes->a));
	
	AptRes->T = (2.0)*M_PI*C;
				       
}

void Llenar (const Periodo *AptDatos, Resultados *AptRes)
{
	
	A(AptDatos, AptRes);
	EL(AptDatos, AptRes);
	T(AptDatos, AptRes);

}

void Imprimir(const Periodo *AptDatos, Resultados *AptRes)
{
     system("color cf");
    
	 cout<<"La aceleracion es "
         <<AptRes->a
         <<endl
         <<endl
         <<"La elongacion es "
         <<AptRes->EL
		 <<endl
		 <<endl
		 <<"Y el periodo "
		 <<AptRes->T
		 <<endl
		 <<endl;
     
}
