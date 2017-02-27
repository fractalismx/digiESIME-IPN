using namespace std;

#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>

struct Num
{
       
	   double R,
              I; 

};

void Leer(Num *Apt1,Num *Apt2);
void Suma(const Num *Apt1,const Num *Apt2,Num *AptR);
void Resta(const Num *Apt1,const Num *Apt2,Num *AptR);
void Multiplicacion(const Num *Apt1,const Num *Apt2,Num *AptR);
void Division(const Num *Apt1,const Num *Apt2,Num *AptR);
void Validar(Num *Apt1,Num *Apt2);
bool Validar2(const Num *Apt2);
void Imprime(const Num *AptR);
void Imprime2(const Num *AptR);
double Seleccion(const Num *Apt1,const Num *Apt2,Num *AptR);

int main(void)
{
    char a;
    Num *Apt1;
    Num *Apt2;
    Num *AptR;
    
    Apt1 = new Num;
    Apt2 = new Num;
    AptR = new Num;
    
    
    do
    {
    Leer(Apt1,Apt2);
    Seleccion(Apt1,Apt2,AptR);
    
    cout<<"Desea ingresar nuevos valores?"<<endl
        <<"Si: S ";
    
	cin>>a;
    a=toupper(a);
    
    delete Apt1;
    delete Apt2;
    delete AptR;
    
	system("cls");
    }
    while(a=='S');
    
   
    
    system("pause");
    return 0;

}

void Leer(Num *Apt1,Num *Apt2)
{
	 
	 system("cls");
	 system("color f0");
	 
	 cout<<"Introduzca parte Real del numero 1: ";
     cin>>Apt1->R;
     
	 cout<<"Introduzca parte Imaginaria: ";
     cin>>Apt1->I;
     
	 cout<<endl<<endl<<"Introduzca parte Real del numero 2: ";
     cin>>Apt2->R;
     
	 cout<<"Introduzca parte Imaginaria: ";
     cin>>Apt2->I;
    
	 system("cls");

}

void Validar(const Num *Apt1,const Num *Apt2)
{
         double z;
         
         if(Apt1->I<-1)
         {
             cout<<"Numero Complejo 1: "<<Apt1->R
                                        <<Apt1->I<<'i'<<endl; 
         }
         else if(Apt1->I==1)
         {
             cout<<"Numero Complejo 1: "<<Apt1->R<<'+'<<'i'<<endl<<endl;
         }
         else if(Apt1->I==-1)
         {
             cout<<"Numero Complejo 1: "<<Apt1->R<<'-'<<'i'<<endl<<endl;
         }
         else
         {
             cout<<"Numero Complejo 1: "<<Apt1->R<<'+'
                                        <<Apt1->I<<'i'<<endl<<endl;
         }
         
         
         if(Apt2->I<-1)
         {
             cout<<"Numero Complejo 2: "<<Apt2->R
                                        <<Apt2->I<<'i'<<endl<<endl; 
         }
         else if(Apt2->I==1)
         {
              cout<<"Numero Complejo 2: "<<Apt2->R<<'+'<<'i'<<endl<<endl;
         }
         else if(Apt2->I==-1)
         {
              cout<<"Numero Complejo 2: "<<Apt2->R<<'-'<<'i'<<endl<<endl;
         }
         else
         {
             cout<<"Numero Complejo 2: "<<Apt2->R<<'+'
                                      <<Apt2->I<<'i'<<endl<<endl;
         }
         
}

double Seleccion(const Num *Apt1,const Num *Apt2,Num *AptR)
{
       int o;
       char r;
       
  do
  {
       	
       system("color cf");
       
	   Validar(Apt1,Apt2);
       
	   cout<<"Seleccione operacion a realizar"
	       <<endl
	       <<endl
           <<"1.- Suma"<<endl
           <<"2.- Resta"<<endl
           <<"3.- Multiplicacion"<<endl
           <<"4.- Division"<<endl
           <<"5.- Salir"<<endl
		   <<endl;    
       cin>>o;
            o=toupper(o);
           
       switch(o)
       {
                case 1:
                     {
					  Suma(Apt1,Apt2,AptR);
                      Imprime(AptR);
                     }
                break;
                case 2:
 	                {
                     Resta(Apt1,Apt2,AptR);
                     Imprime(AptR);
                    }
                break;
                case 3:
 	               {
                     Multiplicacion(Apt1,Apt2,AptR);
                     Imprime(AptR);
                    }
                break;
                case 4:
 	               {
                     bool Flag=Validar2(Apt2);
  					
  					if(Flag==true)
                      {
					  Division(Apt1,Apt2,AptR);
                      Imprime(AptR);
                      }
                      else
                      {
                     	Imprime2(Apt2);
                      }
                   }
                break;
                case 5:
 	                {
                     exit(0);
                    }
                default:
                     cout<<"Caso no valido"<<endl;
       }
       
       cout<<endl<<"Desea realizar otra operacion? "<<endl
           <<"Si: S ";
       cin>>r;
           r=toupper(r);
  
  }while(r=='S');

}


void Suma(const Num *Apt1,const Num *Apt2,Num *AptR)
{
     AptR->R=Apt1->R+
                Apt2->R;
     AptR->I=Apt1->I+
                Apt2->I;
}

void Resta(const Num *Apt1,const Num *Apt2,Num *AptR)
{
     AptR->R=Apt1->R-
             Apt2->R;
     AptR->I=Apt1->I-
             Apt2->I;
}

void Multiplicacion(const Num *Apt1,const Num *Apt2,Num *AptR)
{
     AptR->R=Apt1->R*Apt2->R-
             Apt1->I*Apt2->I;
     AptR->I=Apt1->R*Apt2->I+
             Apt1->I*Apt2->R;
}

void Division(const Num *Apt1,const Num *Apt2,Num *AptR)
{
	 bool Bandera;
     double d;
    
     Bandera=Validar2(Apt2);
     
	 if(Bandera==true)
     {
	 d=pow(Apt2->R,2)+
       pow(Apt2->I,2);
     
     AptR->R=(Apt1->R*Apt2->R+
             Apt1->I*Apt2->I)/d;
     
     AptR->I=(Apt1->R*Apt2->I*(-1.0)+
             Apt1->I*Apt2->R)/d;
     }


}


bool Validar2(const Num *Apt2)
{
	bool Bandera=true;
	
	if(Apt2->I==0 && Apt2->R==0)
	{
		Bandera=false;
	}
 
  return Bandera;
}

void Imprime(const Num *AptR)
{
   system("color fc");
         
		 if(AptR->I<-1)
         {
             cout<<"Resultado: "<<AptR->R
                                <<AptR->I<<'i'<<endl; 
         }
         else if(AptR->I==1)
         {
             cout<<"Resultado: "<<AptR->R<<'+'<<'i'<<endl<<endl;
         }
         
         else if(AptR->I==-1)
         {
             cout<<"Resultado: "<<AptR->R<<'-'<<'i'<<endl<<endl;
         }
         else
         {
             cout<<"Resultado: "<<AptR->R<<'+'
                                <<AptR->I<<'i'<<endl<<endl;
         }
}

void Imprime2(const Num *Apt2)
{
	system("color fc");
	
	cout<<endl
	    <<"No se puede hacer la division"
		<<endl
	    <<"ya que "
		<<Apt2->R
		<<'+'<<Apt2->I<<"i esta en el denominador"
		<<endl;
}
