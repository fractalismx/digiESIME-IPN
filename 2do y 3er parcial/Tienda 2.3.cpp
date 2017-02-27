#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>


using namespace std;

class Tienda
{
	private:
       string Nombre;
       double Precio;
       double *AptCosto;
       double *AptV;
       int Dias;
    
	public:
		Tienda(string Nombre=" ", double P=0.0, int D=1);
		Tienda(const Tienda &RefT);
    	int Asignar(void);
		void Leer(void);
        double Ventas(void)const;
        double Bruto(void)const;
        double Neto(void)const;
        void Imprimir(void)const;
        ~Tienda(void);
    	
};

Tienda::Tienda(string Nombre, double P, int D)
{	
    cout<<"Aqui actua el constructor"
        <<endl
        <<endl;

	AptCosto = new double;
	
	*AptCosto =0.0;
	
	Tienda::Nombre=Nombre;
	
	Precio=P;
	
	Dias=(D<1)?D:Asignar();
	
	AptV = new double[Dias];	
	
	for(int i=0;i<Dias;i++)
	{
            AptV[i]=0;
    }
	
}

Tienda::Tienda(const Tienda &RefT)
{
 
 AptCosto = new double;
 
	
	*AptCosto=*RefT.AptCosto;
	Dias=RefT.Dias;
	
	 AptV = new double[Dias];
	 
	 *AptV=*RefT.AptV;
	 for(int i=0;i<Dias;i++)
             AptV[i]=RefT.AptV[i];
  
  Nombre=RefT.Nombre;
  Precio=RefT.Precio;
}

int Tienda::Asignar(void)
{
	int S,D;
	
	cout<<"Teclee numero de dias"<<endl;
	cin>>S;
	
	if(S<1)
	{   
	    cout<<"no hay dias negativos (se igualara a 1)"
		    <<endl
			<<endl;
		D=1;
	}
	else
	{
		D=S;
	}
return D;
}

void Tienda::Leer(void)
{     
              
		 cout<<"Nombre del producto: ";
         cin.ignore();
         
		 getline(cin,Nombre);
         
         cout<<endl
		     <<"Costo unitario: ";
         cin>>*AptCosto;
         
		cout<<endl
		    <<"Dias de venta: "
		    <<endl
		    <<Dias
		    <<endl
			<<"Ventas del dia: "
			<<endl;
         
         for(int i=0;i<Dias;i++)
         {
           cin>>AptV[i];
         }
        
         
         cout<<endl
             <<endl
             <<"Precio al publico"
             <<endl;
         cin>>Precio;
         
		 system("cls");
}

double Tienda::Ventas(void)const
{
       double Z=0;

       for(int i=0;i<Dias;i++)
       {
         Z=Z+AptV[i];
       }
       
	   return Z;     
}

double Tienda::Bruto(void)const
{              
       return (Ventas()*Precio);     
}

double Tienda::Neto(void)const
{
       return (Bruto()-Ventas()*(*AptCosto));
}

void Tienda::Imprimir(void)const
{
     cout<<"====="
	     <<Nombre
		 <<"====="
	     <<endl
		 <<endl
         <<"Costo Unitario:    $"
		 <<*AptCosto
		 <<endl
         <<"Precio al publico: $"
		 <<Precio
		 <<endl
         <<"Total Ventas:      "
		 <<Ventas()
		 <<endl
		 <<endl;
}

Tienda::~Tienda(void)
{
	cout<<"Aqui actua el destructor"<<endl<<endl;
	
     delete AptCosto;
     delete []AptV;
   
}

void Imprimir2(const double S, double T);
int Numero(void);

int main(void)
{
  /*  Tienda *AptIng;
    
    int N;
    int i;
    double S=0;
    double T=0;
    
	N=Numero();
    
	AptIng = new Tienda[N];
	
	system("pause");
	system("cls");
    
    for(i=0;i<N;i++)
    {
     
	 AptIng[i].Leer();
     S=S+AptIng[i].Bruto();
     T=T+AptIng[i].Neto(); 
	  
    }
    
    for(i=0;i<N;i++)
    {
      
	  AptIng[i].Imprimir();
    
	}
    
    Imprimir2(S,T); 
      
    system("pause");
    system("cls");
 
	delete []AptIng;*/
    
    Tienda *A;
    A=new Tienda;
    A -> Leer();
    A -> Imprimir();
    
    Tienda *B = new Tienda(*A);
    
    B -> Imprimir();
    
    delete A;
    delete B;
    
    system("pause");
    return 0;
}

int Numero(void)
{
     int N;
     
     cout<<"Este programa proporciona sus ingresos"
	    <<endl
	    <<endl
        <<"Introduzca Numero de sus productos ";
    
     cin>>N;
     
     system("pause");
     system("cls");
     
	 return (N);

}

void Imprimir2(const double S, double T)
{
     cout<<"Ingreso Bruto:     $"<<S<<endl;
                    if(T<0)
                    {
                           T=T*-1.0;
                          cout<<"Tiene perdida de:  $"<<T<<endl<<endl;
                    }
					else if(T==0)
					{
						cout<<" Negocio sin ganancias "<<endl; 
					}
                    else
                    {
                         cout<<"Ingreso Neto:      $"<<T<<endl<<endl;
                    }
system("pause");
system("CLS");

}
