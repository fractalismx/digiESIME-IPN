#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

class Racional
{
      private:
              int Num;
              int Den;
      public:
             Racional(int N=0,int D=1);
             void Leer(void);
             int Seleccion(void);

             void setNumerador(const int Num);
             void setDenominador(const int Den);
             int getNumerador(void)const;
             int getDenominador(void)const;
      
             int ValidarDen(void);
             
             Racional Suma(const Racional *R2)const;
             Racional Resta(const Racional *R2)const;
             Racional Multiplicacion(const Racional *R2)const;
             Racional Division(const Racional *R2)const;
             
             void Imprimir(const Racional *R1,
                           const Racional *R2,
                           const char S)const;
              
             int RetN()const;
             ~Racional(void);
             Racional (const Racional &RefR);
};

Racional::Racional(int N,int D)
{
                          Num=N;
                          Den=(D==0)?1:D;
}

Racional::Racional(const Racional &RefR)//Sobrecarga de funcion
{
                         cout<<"Aqui actua el constructor de copia"<<endl;
  Den=RefR.Den;
  Num=RefR.Num;                         
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

void Racional::Leer(void)
{          
                    cout<<endl<<"Introduzca Numerador: ";
                    cin>>Num;
                    cout<<endl<<"Introduzca Denominador: ";
                    Den=ValidarDen();
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

Racional Racional::Suma(const Racional *R2)const
{
   Racional R;         
         R.Num=Num*R2->Den+
               Den*R2->Num;   
         R.Den=Den*R2->Den;
         
         return R;
}

Racional Racional::Resta(const Racional *R2)const
{
   Racional R;         
         R.Num=Num*R2->Den-
               Den*R2->Num;   
         R.Den=Den*R2->Den;
         
         return R;         
}      

Racional Racional::Multiplicacion(const Racional *R2)const
{
   Racional R;
         R.Num=Num*R2->Num;
         R.Den=Den*R2->Den;
         
         return R;
}

Racional Racional::Division(const Racional *R2)const
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
                 
void Racional::Imprimir(const Racional *R1,
                        const Racional *R2,
                        const char S)const
{
                           cout<<R1->Num<<'/'
                               <<R1->Den
							   <<' '
							   <<S
                               <<' '
                               <<R2->Num
							   <<' '
							   <<'/'
                               <<R2->Den
							   <<' '
							   <<'='
							   <<' '
                               <<Num<<'/'
                               <<Den<<endl;
}

int Racional::RetN()const
{
    return Num;
}    

Racional::~Racional(void)
{
                         cout<<endl<<endl<<"Se esta liberando memoria"<<endl<<endl;
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
                R1->Leer();//Aqui Recibe en la direccion
                R2->Leer();
              }
    switch(Op)
    {
              case 1:
                   *R3=R1->Suma(R2);//Aqui recibe valores
                   S='+';
                   Operacion="Suma";
                   break;
              case 2:
                   *R3=R1->Resta(R2);
                   S='-';
                   Operacion="Resta";
                   break;
              case 3:
                   *R3=R1->Multiplicacion(R2);
                   S='*';
                   Operacion="Multiplicacion";
                   break;
              case 4:
                   *R3=R1->Division(R2);
                   S='/';
                   Operacion="Division";
                   break;     
              case 5:
                   break;     
    }               
    
    if(R2->RetN()==0&&Op==4||Op==5)
    {
      cout<<endl;
    }
    else
    {
        cout<<"El resultado de la "<<Operacion<<" es"<<endl;
        R3->Imprimir(R1,R2,S);
    }
    
    cout<<endl<<endl<<"Desea calcular nuevamente?: ";
    cin>>Ans;
    Ans=toupper(Ans);
   
    }while(Ans=='S');
    
    Racional *B=new Racional(*R3);
    
    B->Imprimir(R1,R2,S);
    
    system("pause");
   
    
    delete R1;
    delete R2;
    delete R3;
    delete B;
    
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
