#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>

class Energia
{
      private:
              double A;
              double x;
              double M;
              double T;
      public:
             Energia (double A=0.0,double DI=0.0,double Masa=0.0,double Tiempo=1);
             void Leer(void);
             double getA(void)const;
             double getX(void)const;
             double getM(void)const;
             double getT(void)const;
             void setA(const double A);
             void setX(const double x);
             void setM(const double M);
             void setT(const double T);
             double K(void)const;
             double PE(void)const;
             double TE(void)const;
             double KE(void)const;
             void Imprimir(void)const;
             ~Energia(void);
};

Energia::Energia(double A,double DI,double Masa,double Tiempo)
{
                       cout<<"Se esta creando memoria"<<endl;
                        Energia::A=(A<0)?0.0:A;
                        x=DI;
                        M=(Masa<0)?0.0:Masa;
                        T=(Tiempo<=0)?1.0:Tiempo;
}

void Energia::Leer(void)
{
     double Time;
     double Ma;
     double Amp;
     
     cout<<"Introduzca Amplitud: ";
     cin>>Amp;
     A=(Amp<0)?0.0:Amp;
     
     cout<<endl<<"Introduzca Desplazamiento inicial: ";
     cin>>x;
     
     cout<<endl<<"Introduzca Masa: ";
     cin>>Ma;
     M=(Ma<0)?0.0:Ma;
     
     cout<<endl<<"Introduzca Tiempo: ";
     cin>>Time;
     T=(Time<=0)?1.0:Time;
}

double Energia::K(void)const
{
       return((4.0*pow(M_PI,2)*
              M)/pow(T,2));
}

double Energia::PE(void)const
{
     return((K()*
            pow(x,2))/2.0);
}

double Energia::TE(void)const
{
       return((K()*pow(A,2))/2.0);
}

double Energia::KE(void)const
{
       return (TE()-PE());
}

void Energia::Imprimir(void)const
{
     cout<<"Amplitud: "<<A<<endl
         <<"Desplazamiento inicial: "<<x<<endl
         <<"Masa: "<<M<<endl
         <<"Tiempo: "<<T<<endl
         <<"Constante del resorte: "<<K()<<endl
         <<"Energia Ponencial: "<<PE()<<endl
         <<"Energia Total: "<<TE()<<endl
         <<"Energia cinetica: "<<KE()<<endl;
}

Energia::~Energia(void)
{
                       cout<<"Se esta liberando memoria"<<endl;
}

int main(void)
{

	Portada();

    system("color f0");
	
	cout<<"Por lectura"<<endl<<endl;
	
	Energia *AptL;
    
    AptL=new Energia;  //Por lectura
    
    AptL->Leer();
    AptL->Imprimir();
    
    delete AptL;
    
    system("pause");
    system("cls");
    
	system("color f1");
    
	cout<<"Por omision"<<endl<<endl;
    
    Energia *AptO;     //Por omision
    AptO= new Energia;
    
    AptO->Imprimir();
    
    delete AptO;
    
    system("pause");
    system("cls");
    
	system("color f2");
    
    cout<<"Por asignacion"<<endl<<endl;
    
    Energia *AptA;              //Por asignacion
    AptA= new Energia(3,4,5,7);
    
    AptA->Imprimir();
  
    delete AptA;
    
    system("pause");
    system("cls");
    
    system("color f3");
    
    cout<<"Por asignacion fuera de rango"<<endl<<endl;
    
    Energia *AptAFR;                //Por asignacion fuera de rango
    AptAFR = new Energia(3,4,6,-9);
    
    AptAFR->Imprimir();
    
    delete AptAFR;
	
	cout<<endl<<endl<<endl;
	
	system("pause");
	return (0);
    
}
