#include <cstdlib>
#include <iostream>
#include <string>
#include <K:\portada.hpp>

class Boleta
{
      private:
              string Ndb;
      public:
             Boleta (string NB=" ");
             void setNumBoleta(const string Ndb);
             string getNumBoleta(void)const;
             void LeerB(void);
             void ImprimirB(void)const;
 };

Boleta::Boleta(string NB)
{
    Ndb=NB;
}

void Boleta::getNumBoleta(void)const
{
  return Ndb;
}

string Boleta::setNumBoleta(const string Ndb)
{
  Boleta::Ndb=Ndb;
}

void Boleta::LeerB(void)
{
     cout<<"Introduzca numero de boleta: ";
     getline(cin,Ndb);
     cin.ignore();
}

void Boleta::ImprimirB(void)const
{
     cout<<"Numero de boleta: "<<Ndb<<endl;
}

class Calificacion: virtual public Boleta
{
      private:
              double Promedio;
              int Adeudo;
      public:
             Calificacion(string NB=" ", 
                          double P=0, int A=0);
             void LeerC(void);
             double ValidarP(void);
             int ValidarA(void);
             void ImprimirC(void);
             double RegresaP(void);
             int RegresaA(void);
};

Calificacion::Calificacion(string NB, double P, int A):Boleta(NB)
{
    Promedio=(P<0)?0:P;
    Adeudo=(A<0)?0:A;
}

void Calificacion::LeerC(void)
{
     Promedio=ValidarP();
     Adeudo=ValidarA();
}

void Calificacion::ImprimirC(void)
{
     ImprimirB();
     cout<<"Promedio: "<<Promedio<<endl
         <<"Adeudos: "<<Adeudo<<endl;
}

double Calificacion::RegresaP(void)
{
       return(Promedio);
}

int Calificacion::RegresaA(void)
{
    return(Adeudo);
}

double Calificacion::ValidarP(void)
{
       double P;
       do
       {
              cout<<"Introduzca Promedio: ";
              cin>>P;
              
			  if(P<0||P>10)
              {
                           cout<<"Introduzca Promedio valido"<<endl;
              }
     
	   }while(P<0||P>10);
       
       return(P);
}

int Calificacion::ValidarA(void)
{
    int A;
       do
       {
              cout<<"Introduzca Materias Adeudadas: ";
              cin>>A;
              
			  if(A<0||A>6)
              {
                           cout<<"Introduzca numero valido"<<endl;
              }
       
	   }while(A<0||A>6);
       
       return(A);
}

class Beca:virtual public Boleta
{
      private:
              string Tipo;
              double Monto;
      public:
             Beca(string NB=" ", string T=" ",
                  double M=0.0);
             void LeerBeca(void);
             void ImprimirBeca(void)const;
             double RegresaM(void);
             double ValidarM(void);
};

Beca::Beca(string NB, string T,
           double M):Boleta(NB)
{
           Tipo=T;
           Monto=(M<0)?0:M;
}

void Beca::LeerBeca(void)
{
     LeerB();
     
     cout<<"Introduzca Tipo de beca: ";
     
     getline(cin,Tipo);
     
     Monto=ValidarM();
}

double Beca::ValidarM(void)
{
       double M;
       
       do
       {
              cout<<"Introduzca Monto de Beca (100%): ";
              cin>>M;
        
		      if(M<0)
              {
                           cout<<"Introduzca Monto valido"<<endl;
              }
       
	   }while(M<0);
       
       return(M);
}

void Beca::ImprimirBeca(void)const
{
     cout<<"Tipo de Beca: "<<Tipo<<endl;
}

double Beca::RegresaM(void)
{
       return(Monto);
}
       
class Alumno:public Calificacion, public Beca
{
      public:
             Alumno(string NB=" ", double P=0, int A=0,
                    string T=" ", double M=0.0);
             void Leer(void);
             void Imprimir(void);
             double Calculo(void);
};

Alumno::Alumno(string NB, double P, int A,
               string T, double M):Boleta(NB),Calificacion(NB, P, A),
                                   Beca(NB, T, M)
{
    cout<<"nada"<<endl;
}

void Alumno::Leer(void)
{
     LeerBeca();
      LeerC();
}

double Alumno::Calculo(void)
{
       return( (RegresaP()/10.0)*(RegresaM()));
}

void Alumno::Imprimir(void)
{
     ImprimirC();
     ImprimirBeca();
     cout<<"El pago correspondiente es de :"<<Calculo()<<endl<<endl;
     
     if(RegresaA()>3)
     {
                     cout<<"Sin embargo por adeudo de materias ha perdido la beca"<<endl;
     }
}

int main(void)
{
	Portada();

	system("color 1f");
	
    Alumno *Al;
    Al=new Alumno;
    
    Al->Leer();
    system("cls");
    Al->Imprimir();
    
    delete Al;
    
    system ("pause");
    return 0;
}
