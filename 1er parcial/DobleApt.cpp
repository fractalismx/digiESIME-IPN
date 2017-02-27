#include <iostream>
#include <cmath>
#include <cstdlib>
#include <I:\Portada.hpp>

struct Onda
{
       double *Amp;
       double *T;
       double *Frec;
       double *Vel;
       double *x;
};

void Leer(Onda *AptMov);
double Calcular(const Onda *AptMov);
void Imprimir(const Onda *AptMov);
double Validar(void);

int main(void)
{
    Portada();

    Onda *Descripcion;
    
	Descripcion = new Onda;

    Leer(Descripcion);
    Imprimir(Descripcion);

    delete Descripcion->x;
    delete Descripcion->Vel;
    delete Descripcion->Frec;
    delete Descripcion->T;
    delete Descripcion->Amp;
    
	delete Descripcion;

    system("PAUSE");
    system("cls");

    return 0;

}


void Leer(Onda *AptMov)
{
     system("color f4");

     cout<<"Este programa calcula la expresion matematica de una onda"<<endl<<endl
         <<"Introduzca Amplitud:"<<endl;
     AptMov->Amp=new double;
         cin>>*(AptMov->Amp);
     cout<<endl<<endl

         <<"Introduzca Tiempo donde se desea calcular la posicion:"<<endl;
     AptMov->T=new double;
         cin>>*(AptMov->T);
     cout<<endl<<endl

         <<"Introduzca Frecuencia:"<<endl;
     AptMov->Frec=new double;
         cin>>*(AptMov->Frec);
     cout<<endl<<endl

         <<"Introduzca Posicion:"<<endl;
     AptMov->x=new double;
         cin>>*(AptMov->x);
     cout<<endl<<endl
         <<"Introduzca Velocidad:"<<endl;
     AptMov->Vel=new double;
         cin>>*(AptMov->Vel);
}

double Validar(void)
{
       double valor;

       do
       {
              cin>>valor;
              if(valor==0)
              {
                          cout<<"Introduzca valor de frecuencia valido"<<endl<<endl;
              }
       }
       while(valor==0);

       return valor;
}

double Calcular(const Onda *AptMov)
{
       double y;

       if(*(AptMov->x)<0)
       {
                        y=(2.0*M_PI*abs(*(AptMov->x))*(*(AptMov->Frec)));
                        y=y/(*(AptMov->Vel));
                        y=(2.0*M_PI*(*(AptMov->Frec))*(*(AptMov->T)))-y;
                        y=*(AptMov->Amp)*sin(y*M_PI/180);
       }
       else
       {
            y=(2.0*M_PI*abs(*(AptMov->x))*(*(AptMov->Frec)));
                        y=y/(*(AptMov->Vel));
                        y=(2.0*M_PI*(*(AptMov->Frec))*(*(AptMov->T)))+y;
                        y=*(AptMov->Amp)*sin(y*M_PI/180);
       }

       return y;
}


void Imprimir(const Onda *AptMov)
{
     system("cls");
     system("color F0");

     cout<<"Amplitud:"
	     <<endl
         <<*(AptMov->Amp)
         <<endl
		 <<endl
         <<"Tiempo:"
		 <<endl
         <<*(AptMov->T)
         <<endl
		 <<endl
         <<"Frecuencia:"
		 <<endl
         <<*(AptMov->Frec)
         <<endl
		 <<endl
         <<"Posicion:"
		 <<endl
         <<*(AptMov->x)
         <<endl
		 <<endl
         <<"Velocidad:"
		 <<endl
         <<*(AptMov->Vel)
         <<endl
		 <<endl
         <<"Descripcion de la onda"
		 <<endl
         <<Calcular(AptMov)<<" m"
		 <<endl
		 <<endl;
 }
