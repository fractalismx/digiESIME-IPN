#include <cstdlib>
#include <iostream>

using namespace std;

class Tienda
{
	private:
		int Proto;
		double Precio;
	public:
		Tienda(int Pro=0,double Pre=0.0);
		int getProto(void)const;
		double getPrecio(void)const;
		void setProto(const int Proto);
		void setPrecio(const double Precio);
		void Leer(void);
		double ValidarD(void);
		int ValidarE(void);
		double Costo(void)const;
		void Imprimir(void)const;
	
	friend int VPD(Tienda *AptT);
	friend int Resto(const Tienda *AptT,int G);
	friend double Venta(const Tienda *AptT,int G); 
	friend double CostoF(const Tienda *AptT, int G);
	
};

Tienda::Tienda(int Pro,double Pre)
{
	Proto=(Pro<0)?0:Pro;
	Precio=(Pre<0)?0.0:Pre;
}

void Tienda::setPrecio(const double Precio)
{
	Tienda::Precio=Precio;
}

void Tienda::setProto(const int Proto)
{
	Tienda::Proto=Proto;
}

double Tienda::getPrecio(void)const
{
	return Precio;
}

int Tienda::getProto(void)const
{
	return Proto;
}

void Tienda::Leer(void)
{
	cout<<"introduzca numero de protos en el almacen(inicio) ";
	
	Proto=ValidarE();
	
	cout<<"introduzca precio unitario ";
	
	Precio=ValidarD();
}

double Tienda::ValidarD(void)
{
	double V;
	
	do
	{
	  cin>>V;
	  
	   if(V<0)
	   {
	   	cout<<"Valor Invalido"<<endl;
	   }
	}
	while(V<0);

return V;
}

int Tienda::ValidarE(void)
{
	int V;
	
	do
	{
	  cin>>V;
	  
	   if(V<0)
	   {
	   	cout<<"Valor Invalido"<<endl;
	   }
	}
	while(V<0);

return V;
}

double Tienda::Costo(void)const
{
	return(Proto*Precio);
}

void Tienda::Imprimir(void)const
{
	cout<<"Al inicio del dia"<<endl
	    <<"Sus protobaords eran de "
		<<Proto<<endl
		<<"Y su precio unitario fue de "
		<<Precio<<endl
		<<"Y el costo total fue de "
		<<Costo()<<endl;
}

void Imprimir2(const Tienda *AptT, int G);

int main (void)
{
	Tienda *AptT;
	
	int H;
	
	AptT=new Tienda;
	
	system("color f0");
	
	AptT->Leer();
	
	H=VPD(AptT);
	
	system("pause");
	
	system("cls");
	
	system("color 0f");
	
	AptT->Imprimir();
	
	Imprimir2(AptT,H);
	
	delete AptT;
	
	system("Pause");
	
	return 0;
}

int VPD(Tienda *AptT)
{
	int F;
	
	cout<<"Introduzca los protos que se vendieron ";
     
	 F=	AptT->ValidarE();
	 
	 return F;
}

int Resto(const Tienda *AptT,int G)
{	
	return (AptT->Proto-G);
	
}

double Venta(const Tienda *AptT,int G)
{
	return (G*AptT->Precio);
}

double CostoF (const Tienda *AptT,int G)
{
  return (Resto(AptT,G)*(AptT->Precio));	
}

void Imprimir2(const Tienda *AptT, int G)
{
	cout<<"Al final del dia "<<endl
	    <<"Se vendieron "
		<<G
		<<" Protoboards"<<endl
		<<"Por ende en almacen quedan "
		<<Resto(AptT,G)
		<<endl
		<<"En efectivo esto representa "
		<<Venta(AptT,G)
		<<endl
		<<"Y el costo nuaevo del inventario es "
		<<CostoF(AptT,G)
		<<endl;
}
