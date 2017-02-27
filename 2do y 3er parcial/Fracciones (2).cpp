#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

class Racional
{
	  friend istream &operator>>(istream &E, Racional *AptR);
	  friend ostream &operator<<(ostream &S,const Racional *AptR);
	  
      private:
              int Num;
              int Den;
      public:
             Racional(int N=0,int D=0);
             void Leer(void);
             int Seleccion(void);
      
             int ValidarDen(void);

             void setNumerador(const int Num);
             void setDenominador(const int Den);
             int getNumerador(void)const;
             int getDenominador(void)const;
             
             Racional operator+(const Racional *R2)const;
             Racional operator-(const Racional *R2)const;
             Racional operator*(const Racional *R2)const;
             Racional operator/(const Racional *R2)const;
             
             bool operator>(const Racional *R2)const;
             bool operator<(const Racional *R2)const;
             bool operator>=(const Racional *R2)const;
             bool operator<=(const Racional *R2)const;
             bool operator==(const Racional *R2)const;
             bool operator!=(const Racional *R2)const;
             
             void Imprimir(const Racional *R1,
                           const Racional *R2,
                           const char S);
             void Imprimir2(const Racional *R2);
              
             int RetN()const;
             ~Racional(void);
};

Racional::Racional(int N,int D)
{
                          Num=N;
                          Den=(D==0)?1:D;
}



void Racional::Leer(void)
{          
                    Racional *AptR;
                    AptR=this;
                    cin>>AptR;
}

void Racional::setDenominador(const int Den)
{
  Racional::Den=Den;
}

void Racional::setNumerador(const int Num)
{
  Racional::Num=Num;
}

int Racional::getDenominador(void)const
{
  return Den;
}

int Racional::getNumerador(void)const
{
  return Num;
}

int Racional::ValidarDen(void)
{
       int D;
       do
       {
       cin>>D;
       
       if(D==0)
               cout<<endl<<endl<<"Valor invalido. Introduzca nuevamente"<<endl;
               
       }while(D==0);
       
       return D;
}

Racional Racional::operator+(const Racional *R2)const
{
   Racional R;  
          
         R.Num=Num*R2->Den+
               Den*R2->Num;   
         R.Den=Den*R2->Den;
         
         return R;
}

Racional Racional::operator-(const Racional *R2)const
{
   Racional R;         
         R.Num=Num*R2->Den-
               Den*R2->Num;   
         R.Den=Den*R2->Den;
         
         return R;         
}      

Racional Racional::operator*(const Racional *R2)const
{
   Racional R;
         R.Num=Num*R2->Num;
         R.Den=Den*R2->Den;
         
         return R;
}

Racional Racional::operator/(const Racional *R2)const
{
         Racional R;
         R.Num=Num*R2->Den;
         
         if(R2->Num==0)
         {
                       cout<<"El numerador es cero"<<endl;
         }
         else
         {
             R.Den=Den*R2->Num;
         }
         
         return R;
}   

bool Racional::operator>(const Racional *R2)const
{
     return((Num*R2->Den)>(Den*R2->Num));
}
 
bool Racional::operator<(const Racional *R2)const
{
     return((Num*R2->Den)<(Den*R2->Num));
}

bool Racional::operator>=(const Racional *R2)const
{
     return((Num*R2->Den)>=(Den*R2->Num));
}

bool Racional::operator<=(const Racional *R2)const
{
     return((Num*R2->Den)<=(Den*R2->Num));
}

bool Racional::operator==(const Racional *R2)const
{
     return((Num*R2->Den)==(Den*R2->Num));
}

bool Racional::operator!=(const Racional *R2)const
{
     return((Num*R2->Den)!=(Den*R2->Num));
}
                 
void Racional::Imprimir(const Racional *R1,
                        const Racional *R2,
                        const char S)
{
	Racional *AptR;
	AptR=this;
	
                           cout<<R1<<' '<<S
						       <<' '<<R2<<'='
						       <<AptR;
                               
                               
}

void Racional::Imprimir2(const Racional *R2)
{
     Racional *R1;
     R1=this;
     
     if(*R1>R2)
     {
               cout<<endl<<R1<<" > "<<R2;
     }
     if(*R1<R2)
     {
               cout<<endl<<R1<<" < "<<R2;
     }
     if(*R1>=R2)
     {
               cout<<endl<<R1<<" >= "<<R2;
     }
     if(*R1<=R2)
     {
              cout<<endl<<R1<<" <= "<<R2;
     }
     if(*R1==R2)
     {
               cout<<endl<<R1<<" = "<<R2;
     }
     if(*R1!=R2)
     {
               cout<<endl<<R1<<" != "<<R2<<endl;
     }
}


int Racional::RetN()const
{
    return Num;
}    

Racional::~Racional(void)
{
                         //cout<<endl<<endl<<"Se esta liberando memoria"<<endl<<endl;
}


int menu(void);
bool ValidarOp(const int Op);

int main(void)
{
	system("color f0");
	
    Racional *R1,*R2,*R3;
    int Op;
    char Ans, S;
    string Operacion;
    
    R1=new Racional;
    R2=new Racional;
    R3=new Racional;
    
    do
    {
    Op=menu();
    
              if(Op!=5)
              {
              	cout<<"Ingrese Racional 1"<<endl;
                R1->Leer();//Aqui Recibe en la direccion
                cout<<"Ingrese Racional 2"<<endl;
                R2->Leer();
              }
    switch(Op)
    {
              case 1:
                   *R3=*R1+R2;
                   S='+';
                   Operacion="Suma";
                   break;
              case 2:
                   *R3=*R1-R2;
                   S='-';
                   Operacion="Resta";
                   break;
              case 3:
                   *R3=*R1*(R2);
                   S='*';
                   Operacion="Multiplicacion";
                   break;
              case 4:
                   *R3=*R1/R2;
                   S='/';
                   Operacion="Division";
                   break;     
              case 5:
                   break;     
    }               
    
    if(R2->RetN()==0&&Op==4||Op==5)
    {
       cout<<"Duh"<<endl;
    }
    else
    {
        cout<<"Su operacion fue una "<<Operacion<<endl;
        R3->Imprimir(R1,R2,S);
        R1->Imprimir2(R2);
    }
    
    cout<<endl<<endl<<"Desea calcular nuevamente?: ";
    cin>>Ans;
    Ans=toupper(Ans);
   
    }while(Ans=='S');
       
    system("pause");
    
    delete R1;
    delete R2;
    delete R3;
    
    return 0;
}

int menu(void)
{
    int Op;
    bool flag=false;
    
    while(flag==false)
    {
    system("cls");
    cout<<"Seleccione opcion:"<<endl<<endl
        <<"1.- Suma de racionales"<<endl
        <<"2.- Resta de racionales"<<endl
        <<"3.- Multiplicacion de racionales"<<endl
        <<"4.- Division de racionales"<<endl
        <<"5.- Salir"<<endl<<endl
        <<"Introduzca opcion: ";
        
        cin>>Op;
        flag=ValidarOp(Op);
        
       if(flag==false)
          {
                  cout<<endl<<"Opcion incorrecta. Introduzca nuevamente opcion"<<endl<<endl;   
                  system("pause");  
          }
    };      
    return Op;
}

bool ValidarOp(const int Op)
{
     bool flag=true;
     
     if(Op<1||Op>5)
     {
                    flag=false;
     }
     return flag;
}

istream &operator>>(istream &E, Racional *AptR)
{
	char Diag;
	
	cout<<"Ej = A/B"<<endl;
	
	cin>>AptR->Num>>Diag;
	 
    AptR->Den=AptR->ValidarDen();
    
    return E;
	
}

ostream &operator<<(ostream &S,const Racional *AptR)
{
	cout<<AptR->Num
	    <<'/'
	    <<AptR->Den;
 
 return S;
}

