using namespace std;

#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>

struct Num
{
       double R;
       double R2;
       double I;
       double I2;
};

struct Res
{
       double Rr;
       double Ri;

};


void Leer(Num *AptComp);
void Validar(const Num *AptComp);
void Suma(const Num *AptComp, Res *AptRes);
void Resta(const Num *AptComp, Res *AptRes);
void Multiplicacion(const Num *AptComp, Res *AptRes);
void Division(const Num *AptComp, Res *AptRes);
double Seleccion(Num *AptComp, Res *AptRes);
void Validar2(const Res *AptRes);
void Imprime(const Num *AptComp, const Res *AptRes);

int main(void)
{

system("color F0");

char r;

    Num *Imaginario;
    Res *Complejo;

    Imaginario = new Num;
    Complejo = new Res;

    do
    {
    Leer(Imaginario);

	Seleccion(Imaginario, Complejo);


    cout<<"Desea introducir nuevos valores?"<<endl
        <<"Si: S"<<endl
        <<"No: N"<<endl<<endl;
        cin>>r;
        r=toupper(r);

        system("cls");
    }
    while(r=='S');

    delete Imaginario;
    delete Complejo;

    system ("pause");
    system ("cls");


}

void Leer(Num *AptComp)
{
    system("color fc");
     cout<<"Introduzca parte Real del numero 1"<<endl;
         cin>>AptComp->R;
     cout<<endl<<endl<<"Introduzca parte Imaginaria"<<endl;
         cin>>AptComp->I;

     system("cls");

     cout<<"Introduzca parte Real del numero 2"<<endl;
         cin>>AptComp->R2;
     cout<<endl<<endl<<"Introduzca parte Imaginaria"<<endl;
         cin>>AptComp->I2;

         system("cls");

         Validar(AptComp);
}

void Validar(const Num *AptComp)
{
                 if(AptComp->I<-1)
         {
             cout<<"Numero Complejo 1: "<<AptComp->R
                                      <<AptComp->I<<"i"<<endl;
         }

         else if(AptComp->I==1)
         {
                cout<<"Numero Complejo 1: "<<AptComp->R
                                          <<"+i"<<endl<<endl;
         }

         else if(AptComp->I==-1)
         {
                cout<<"Numero Complejo 1: "<<AptComp->R
                                           <<"-i"<<endl<<endl;
         }
         else
         {
             cout<<"Numero Complejo 1: "<<AptComp->R<<"+"
                                      <<AptComp->I<<"i"<<endl<<endl;
         }


		 if(AptComp->I2==1)
         {
             cout<<"Numero Complejo 1: "<<AptComp->R2
                                      <<"+i"<<endl;
         }
		 else if(AptComp->I2<-1)
         {
             cout<<"Numero Complejo 2: "<<AptComp->R2
                                      <<AptComp->I2<<"i"<<endl<<endl;
         }

         else if(AptComp->I2==-1)
         {
                cout<<"Numero Complejo 1: "<<AptComp->R2
                                           <<"-i"<<endl<<endl;
         }

         else
         {
             cout<<"Numero Complejo 2: "<<AptComp->R2<<"+"
                                      <<AptComp->I2<<"i"<<endl<<endl;
         }
}


double Seleccion(Num *AptComp, Res *AptRes)
{

char o;
char r;

       do
       {
       cout<<"Seleccione operacion a realizar"
	       <<endl
	       <<endl
           <<"A.- Suma"
	       <<endl
           <<"B.- Resta"
		   <<endl
           <<"C.- Multiplicacion"
		   <<endl
           <<"D.- Division"
		   <<endl
           <<"Z.- Salir"
		   <<endl
		   <<endl;

           cin>>o;
           o=toupper(o);

		   system("cls");

       switch(o)
       {

				case 'A':
                     Suma(AptComp,AptRes);
                     Imprime(AptComp,AptRes);
                     break;
				case 'B':
                     Resta(AptComp,AptRes);
                     Imprime(AptComp,AptRes);
                     break;
				case 'C':
                     Multiplicacion(AptComp,AptRes);
                     Imprime(AptComp,AptRes);
                     break;
				case 'D':
                     Division(AptComp,AptRes);
                     Imprime(AptComp,AptRes);
                     break;
                case 'Z':
                     exit(0);

				default:
                        cout<<"Caso no valido"<<endl;

       }

      cout<<endl<<"Desea calcular otra operacion con estos valores?"<<endl
          <<"Si: S"<<endl
          <<"No: N"<<endl<<endl;
          cin>>r;
          r=toupper(r);

          system("cls");
          system("color 0f");
       }
       while(r=='S');

       system("color 0f");

}

void Suma(const Num *AptComp, Res *AptRes)
{
     AptRes->Rr=AptComp->R+
                AptComp->R2;

	 AptRes->Ri=AptComp->I+

	            AptComp->I2;
}

void Resta(const Num *AptComp, Res *AptRes)
{

	 AptRes->Rr=AptComp->R-
                AptComp->R2;

	 AptRes->Ri=AptComp->I-
                AptComp->I2;

}

void Multiplicacion(const Num *AptComp, Res *AptRes)
{

       AptRes->Rr=AptComp->R*
         AptComp->R2-
         AptComp->I2*
         AptComp->I;

       AptRes->Ri=AptComp->R*
         AptComp->I2+
         AptComp->I*
         AptComp->R2;

}

void Division(const Num *AptComp, Res *AptRes)
{

double f;
double r;
double i;

       f=pow(AptComp->R2,2) +
	     pow(AptComp->I2,2);

       r=(AptComp->R*AptComp->R2)+
	     (AptComp->I2*AptComp->I);


       i=(AptComp->I*AptComp->R2)-
	     (AptComp->R*AptComp->I2);

       AptRes->Rr=r/f;
       AptRes->Ri=i/f;

}

void Validar2(const Res *AptRes)
{

	     if(AptRes->Ri==1)
         {
             cout<<"Resultado: "<<AptRes->Rr
                                      <<"+i"<<endl;
         }
	     else if(AptRes->Ri<-1)
         {
             cout<<"Resultado: "<<AptRes->Rr
                                <<AptRes->Ri<<"i"<<endl<<endl;
         }

         else if(AptRes->Ri==-1)
         {
                cout<<"Resultado: "<<AptRes->Rr
                                   <<"i"<<endl<<endl;
         }

         else
         {
             cout<<"Resultado: "<<AptRes->Rr<<"+"
                                <<AptRes->Ri<<"i"<<endl<<endl;
         }

}

void Imprime(const Num *AptComp, const Res *AptRes)
{

  system("color f0");

  Validar(AptComp);

  system("color 4f");

  Validar2(AptRes);

 }
