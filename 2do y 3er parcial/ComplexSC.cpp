#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class Complejo
{
	private:
		double R;
		double I;
	
	public:
        Complejo(double Re=0.0,double Im=0.0);
        double getReal(void)const;
        double getImaginario(void)const;
        void setReal(const double R);
        void setImaginario(const double I);
		int Menu(void);
		void Leer(void);
		void Estetica(void)const;
		bool Validar(void)const;
		Complejo operator+(const Complejo *AptC2)const;
		Complejo operator-(const Complejo *AptC2)const;
		Complejo operator*(const Complejo *AptC2)const;
		Complejo operator/(const Complejo *AptC2)const;
		void Imprimir2(void)const;
		void Imprimir(const Complejo *AptC1, const Complejo *AptC2, const char S)const;
		double RR(void)const;
		double RI(void)const;
};

Complejo::Complejo(double Re,double Im)
{
	R=Re;
	I=Im;
}

double Complejo::getReal(void)const
{
	return R;
}

double Complejo::getImaginario(void)const
{
	return I;
}

void Complejo::setImaginario(const double I)
{
	Tienda::I=I;
}

void Complejo::setReal(const double R)
{
	Tienda::R=R;
}

int Complejo::Menu(void)
{
	int Opcion;
	
  cout<<"Bienvenido sr. usuario "
      <<endl;
      
      do
      {
      	cout<<"Elija una opcion"
		    <<endl
			<<endl
      	    <<"1) Suma"
			<<endl
      	    <<"2) Resta"
			<<endl
      	    <<"3) Multiplicacion"
			<<endl
      	    <<"4) Division"
			<<endl
			<<endl
			<<"5) Salir"
			<<endl<<endl;
			
      	cin>>Opcion;
      	cout<<endl;
      	
      	if(Opcion<1||Opcion>5)
      	{
      		cout<<"Ingrese opcion valida"<<endl;
      	}
      
	  }while(Opcion<1||Opcion>5);

return Opcion;
}

void Complejo::Leer(void)
{
	 cout<<"Introduzca parte Real: ";
     cin>>R;
     
	 cout<<"Introduzca parte Imaginaria: ";
     cin>>I;
    
}

void Complejo::Estetica(void)const
{
	     if(I<-1)
         {
             cout<<R<<I<<'i'<<endl; 
         }
         else if(I==1)
         {
             cout<<R<<"+i"<<endl;
         }
         else if(I==-1)
         {
             cout<<R<<"-i"<<endl;
         }
         else
         {
             cout<<R<<'+'<<I<<'i'<<endl;
         }
         
}

bool Complejo::Validar(void)const
{
	bool Bandera=true;
	
	if(I==0 && R==0)
	{
		Bandera=false;
	}
 
  return Bandera;
}

Complejo Complejo::operator+(const Complejo *AptC2)const
{
	Complejo Z;
	
	Z.R=R+AptC2->R;
	Z.I=I+AptC2->I;
	
	return Z;
}

Complejo Complejo::operator-(const Complejo *AptC2)const
{
	Complejo Z;
	
	Z.R=R-AptC2->R;
	Z.I=I-AptC2->I;
	
	return Z;
}

Complejo Complejo::operator*(const Complejo *AptC2)const
{
	Complejo Z;
	
	Z.R=(R*AptC2->R)-(I*AptC2->I);
	Z.I=(R*AptC2->I)+(I*AptC2->R);
	
	return Z;
}
Complejo Complejo::operator/(const Complejo *AptC2)const
{
	Complejo Z;
	double Den;
	bool flag=Validar();
	
	if(flag==true)
	{
	 Den=pow(AptC2->R,2)+pow(AptC2->I,2);
	 
	 Z.R=(R*AptC2->R)+(I*AptC2->I);
	 Z.R=Z.R/Den;	 
	 
	 
	 Z.I=(I*AptC2->R)-(R*AptC2->I);
	 Z.I=Z.I/Den;
	}
	else
	{
		cout<<endl;
	}
	
return Z;
}

double Complejo::RI(void)const
{
	return I;
}

double Complejo::RR(void)const
{
	return R;
}

void Complejo::Imprimir(const Complejo *AptC1,const Complejo *AptC2,const char S)const
{
	AptC1->Estetica();
	cout<<" "<<S<<" ";
	AptC2->Estetica();
	
	cout<<"Resultado: "<<endl;
	Estetica();
}

void Complejo::Imprimir2(void)const
{
	system("color fc");
	
	cout<<endl
	    <<"No se puede hacer la division"
		<<endl
	    <<"ya que "
		<<R<<'+'<<I<<"i esta en el denominador"
		<<endl;
}

int main (void)
{
	Complejo *AptC1;
	Complejo *AptC2;
	Complejo *AptC3;

    char S,Resp;
    
    string Operacion;
	
	AptC1=new Complejo;
	AptC2=new Complejo;
	AptC3=new Complejo;
	
       	  
    
    do
    {
	
	int Opcion=AptC3->Menu();
	
	 	  if(Opcion>=1&&Opcion<=4)
          {
    	    cout<<"Ingrese Complejo 1"<<endl;
    	    AptC1->Leer();
    	    cout<<"Ingrese Complejo 2"<<endl;
    	    AptC2->Leer();
          }
		
	   switch(Opcion)
       {
                case 1:
                     {
					  *AptC3=*AptC1+(AptC2);
					  S='+';
					  Operacion="Suma";
                     }
                break;
                case 2:
 	                {
                     *AptC3=*AptC1-(AptC2);
                     S='-';
                     Operacion="Resta";
                    }
                break;
                case 3:
 	               {
                     *AptC3=(*AptC1)*(AptC2);
                     S='*';
                     Operacion="Multiplicacion";
                   }
                break;
                case 4:
 	               {
                     bool Flag=AptC2->Validar();
  					
  					if(Flag==true)
                      {
					  *AptC3=*AptC1/(AptC2);
					  S='/';
					  Operacion="Division";
                      }
                      else
                      {
                      	AptC2->Imprimir2();
                      }
                   }
                break;
                case 5:
 	            break;
 	            
       }
       
    if(Opcion==4&&(AptC2->RR()==0&&AptC2->RI()==0)||Opcion==5)
    {
    	cout<<"Duhhhh"<<endl;
    }
    else
    {
    	cout<<"Su operacion fue una"<<Operacion<<endl;
    	AptC3->Imprimir(AptC1,AptC2,S);
    }
       
    cout<<"Desea repetir???"<<endl;
    cin>>Resp;
    
    system("Pause");
    system("Cls");
    
	}while(Resp=toupper(Resp)=='S');
    
system("pause");
return 0;
}
