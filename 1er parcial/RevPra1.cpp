#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>


using namespace std;

struct Reaccion
{
       double a;
       double b;
       double Carga;
       double x;
       double Mom_Inercia;
       double E;
};

void Portada(void);
void Leer(Reaccion &RefViga);
double Validar(void);
double Validar2(void);
double L(const Reaccion &RefViga);
double R_a(const Reaccion &RefViga);
double R_b(const Reaccion &RefViga);
double F_Cortante(const Reaccion &RefViga);
double Momento(const Reaccion &RefViga);
double Defleccion(const Reaccion &RefViga);
void Imprimir(const Reaccion &RefViga);


int main(void)
{   
    Reaccion Calculo;
    
    Portada();

    Leer(Calculo);
    Imprimir(Calculo);
    
    system("PAUSE");
    
    return 0;
}


void Portada(void)
{
     system ("color f4");
              
         cout<<"\t\t\tInstituto Politecnico Nacional"<<endl<<endl
         <<"\t\tEscuela Superior De Ingenieria Mecanica y Electrica"<<endl
         <<"\t\t\t\t   Zacatenco"<<endl<<endl
         <<"\t\tMateria:  Programacion Orientada a Objetos"<<endl<<endl
         <<"\t\tProfesora: Ing. Isis Espinoza Salazar"<<endl<<endl<<endl
         <<"\t\t\t\t   Practica 1:"<<endl
         <<"\t\t\t\t   -Estructuras-"<<endl<<endl<<endl
         <<"\t\tAlumnos:  Gonzalez Morales Cristian Joel"<<endl<<endl
         <<"\t\t          Tapia Marin Pablo"<<endl<<endl;
         system("pause");
         system("cls");
}


void Leer(Reaccion &RefViga)
{
     system("color 4f");
	 
     double Longitud;
	
     cout<<"\tEste programa calcula las reacciones que experimenta una viga"<<endl
         <<"Asi como tambien la Fuerza Cortante, el momento y defleccion"<<endl<<endl;

         do
            {
                cout<<"Introduzca distancia de la carga al soporte"<<endl;
               cin>>RefViga.a;
               RefViga.a=abs(RefViga.a);
               
               cout<<endl<<"Introduzca distancia de la carga al extremo libre"<<endl;
               cin>>RefViga.b;
               RefViga.b=abs(RefViga.b);
               
			   Longitud=L(RefViga);
               
               if(Longitud==0)
               {
			   cout<<endl<<"Introduzca valor valido"<<endl;
               
                }               
              }
while(Longitud==0);
 
     cout<<endl<<"Introduzca magnitud de la carga concentrada "<<endl;
     cin>>RefViga.Carga;
     RefViga.Carga=abs(RefViga.Carga);

      cout<<endl<<"Introduzca modulo de elasticidad del material"<<endl;
      RefViga.E=Validar();
 
      cout<<endl<<"Introduzca distancia donde desea calcular fuerza cortante, momemto y deflexion"
	      <<endl;
      RefViga.x=Validar();
                   
      cout<<endl<<"Introduzca Momento de inercia"<<endl;
      RefViga.Mom_Inercia=Validar2();
}


double L(const Reaccion &RefViga)
{
	return(RefViga.a+RefViga.b);	
}


double Validar(void)
{
	double valor;
	
	do
	{
		cin>>valor;
		if(valor==0||valor<0)
		{
		cout<<"Introduzca valor valido"<<endl<<endl;
        }
	}
	while(valor==0||valor<0);
    
    return(valor);	
}

double Validar2(void)
{
       double valor2;
       
       do
       {
              cin>>valor2;
              if(valor2==0)
              {
                          cout<<"Introduzca valor valido"<<endl<<endl;
              }
       }
       while(valor2==0);

       return(valor2);
}


double R_a(const Reaccion &RefViga)
{

double Long=L(RefViga);

       return (RefViga.Carga *
               RefViga.b /
               Long);
}


double R_b(const Reaccion &RefViga)
{

double Long=L(RefViga);

       return (RefViga.Carga *
               RefViga.a /
               Long);
}


double F_Cortante(const Reaccion &RefViga)
{
       if(RefViga.x<RefViga.a)
       {
            return(R_a(RefViga));
       }
       
       else 
       {
            return((R_b(RefViga))*
                   (-1.0));
       }
}


double Momento(const Reaccion &RefViga)
{

double Long=L(RefViga);

       if(RefViga.x<RefViga.a)
       {
                              return((RefViga.Carga*
                                     RefViga.b*
                                     RefViga.x)/
                                     Long);
       }
       
       else
       {
           return(RefViga.Carga*
                 (RefViga.b*
                  RefViga.x/
                 (Long-
                  RefViga.x+
                  RefViga.a)));
       }
}

double Defleccion(const Reaccion &RefViga)
{

float a,b;
double Long=L(RefViga);

       if(RefViga.x<RefViga.a)
       {
              a=(RefViga.Carga*
                 RefViga.b*
                 RefViga.x*
                (pow(Long,2)-pow(RefViga.b,2)-pow(RefViga.x,2)));
              
              b=(6*RefViga.E*
                   RefViga.Mom_Inercia*
                   Long);
              return((a/b)*(-1));
       }
       
       else 
       {
              a=(RefViga.Carga*
                 RefViga.a*
                 (Long-RefViga.x)*
                 
                 (2*Long*
                    RefViga.b-
                    pow(RefViga.b,2)-
                    (pow(Long-RefViga.x,2))));
              
              b=(6*RefViga.E*
                   RefViga.Mom_Inercia*
                   Long);
              return((a/b)*(-1));
       }
}

void Imprimir(const Reaccion &RefViga)
{
     system("cls");
                   
         cout<<"\t\tTeniendo una viga de longitud "<<L(RefViga)<<endl<<endl
             <<"Con longitud de la carga al soporte: "
             <<RefViga.a<<endl<<endl      
             <<"Longitud de la carga al extremo libre: "
             <<RefViga.b<<endl<<endl
             <<"Carga: "
             <<RefViga.Carga<<endl<<endl
             <<"Modulo de elasticidad: "
             <<RefViga.E<<endl<<endl
             <<"Distancia a realizar calculos: "
             <<RefViga.x<<endl<<endl
             <<"Momento de inercia: "
             <<RefViga.Mom_Inercia<<endl<<endl;
     
     
     
	 	 cout<<endl<<endl
             <<"Se obtuvieron los siguientes datos:"<<endl<<endl
        
         <<"Reaccion izquierda"<<endl
         <<R_a(RefViga)<<endl<<endl
        
         <<"Reaccion derecha"<<endl
         <<R_b(RefViga)<<endl<<endl
        
         <<"Fuerza cortante"<<endl
         <<F_Cortante(RefViga)<<endl<<endl
        
         <<"Momento"<<endl
         <<Momento(RefViga)<<endl<<endl

         <<"Defleccion"<<endl
         <<Defleccion(RefViga)<<endl<<endl;


}
