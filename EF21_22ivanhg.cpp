//============================================================================
// Name        : EF21_22ivanhg
// Author      : Ivan Herculano Garcia
// Description : Practica Final de Programacion
//============================================================================

using namespace std;

//INCLUDES--------------------------------------------------------------------
#include <iostream>
#include <conio2.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>

//DEFINE----------------------------------------------------------------------
//Margenes----------------------------------------------------------------
#define xmin 15 
#define ancho 90
#define ymin 1
#define alto 23 //Hasta final de pagina. Sin incluir la caja de opciones
#define colorpagina 15
//Ejemplos----------------------------------------------------------------
#define PI 3.1416
#define e 2.7183

//Minimo y Maximo para asignar al menu principal------------------------------
#define min 1
#define max 10

//MODULOS---------------------------------------------------------------------
typedef char TITULO[ancho-xmin-2];
void titulo(TITULO nombre);

void pagina(); //Siempre usar tras borrar alguna linea!!
void caja_opciones();
void endline(int y); //(comenzar en 1)
int opcion(int minimo,int maxaximo);
int conversor(char aux[]); //convierte valor char a int (si detecta algo que no sea un numero, dira que el valor es 0)
char fin_opciones();

//MODULOS PRINCIPALES---------------------------------------------------------
void principal(); //Pagina Principal
void opciones(int num);
void fin(); //Pagina final

void intercambio_AB(int &A,int &B);

//VECTORES---------------------------------------------------------------------
typedef int vector[6];
typedef int matriz[2][3];

//REGISTROS--------------------------------------------------------------------
typedef struct personaje
{
	char nombre[50];
	int vidas;
	int nivel;
};

//MAIN-----------------------------------------------------------------------------
int main()
{
	int num=0;


	while(num!=max)
	{
		//Pantalla Principal------------------------------------------------------------
		principal();

		//Opciones------------------------------------------------------------------
		num = opcion(min,max);

		//OPCIONES------------------------------------------------------------------
		opciones(num);
	}

	fin();

	return 0;
}

//MODULOS------------------------------------------------------
void principal()
{
	titulo("FUNDAMENTOS DE PROGRAMACION 2021-2022");

	cout<<"1. Variables y constantes.";endline(1);
	cout<<"2. Estructuras de control de flujo.";endline(2);
	cout<<"3. Modulos.";endline(3);
	cout<<"4. Vectores y Matrices.";endline(4);
	cout<<"5. Algoritmo de la Burbuja.";endline(5);
	cout<<"6. Tipos de datos.(typedef)";endline(6);
	cout<<"7. Ficheros de texto.";endline(7);
	cout<<"8. Prohibiciones de la asignatura.";endline(8);
	cout<<"9. Buenas practicas de programacion.";endline(9);
	textcolor(12);
	cout<<"10. Salir";
}

void opciones(int num)
{
	int subnum1=0,subnum2=0;
	char letra=0;
	char aux[10],aux2[10];

	int ejemploint,ejemploint2,resultado,A=0,B;
	char ejemplochar;
	vector ejemplovector;
	matriz ejemplomatriz;
	personaje ejemplopersonaje;

	ofstream escritura;
	ifstream lectura;

	switch(num)
	{
	//VARIABLES Y CONSTANTES----------------------------------------------------------------------------------------------------------------------
	case 1:
		while(letra!='A')
		{
			titulo("VARIABLES Y CONSTANTES");

			cout<<"	* Una ";textcolor(14);cout<<"VARIABLE ";textcolor(15);cout<<"es un elemento almacenado en un espacio de memoria, cuyo valor";endline(1);
			cout<<"puede cambiar a lo largo que el programa se ejecute. Ademas, su tamanio dependera";endline(2);
			cout<<"del tipo de variable. Se define asi:";endline(3);
			textcolor(4);cout<<"tipo-de-variable ";textcolor(12);cout<<"nombre";textcolor(15);cout<<";";endline(4);

			endline(5);

			cout<<"	* Una ";textcolor(14);cout<<"CONSTANTE ";textcolor(15);cout<<"es un elemento almacenado en un espacio de memoria, cuyo valor";endline(6);
			cout<<"no cambia durante la ejecucion del algoritmo. Se define asi:";endline(7);
			textcolor(4);cout<<"#define "; textcolor(2); cout<<"nombre "; textcolor(15); cout<<"valor";endline(8);

			letra=fin_opciones();

			if(letra=='D')
			{
				titulo("EJEMPLOS");

				textcolor(14);cout<<"VARIABLES";textcolor(15);cout<<": int numero, char letra";endline(1);
				endline(2);
				textcolor(14);cout<<"IMPLEMENTACION";textcolor(15);cout<<":";endline(3);
				cout<<"Producto de un numero por 2";endline(4);
				cout<<"Introduce x: ";
				cin>>ejemploint;endline(5);
				cout<<"El resultado es: "<<ejemploint*2;endline(6);
				endline(7);
				cout<<"Introducir y mostrar un caracter";endline(8);
				cout<<"Introduce un caracter: ";
				cin>>ejemplochar;endline(9);
				cout<<"Tu caracter es: "<<ejemplochar;endline(10);
				endline(11);
				textcolor(14);
				system("PAUSE");

				titulo("EJEMPLOS");

				textcolor(14);cout<<"CONSTANTES";textcolor(15);cout<<": #define PI 3.1416, #define e 2.7183";endline(1);
				endline(2);
				textcolor(14);cout<<"IMPLEMENTACION";textcolor(15);cout<<":";endline(3);
				cout<<"Perimetro de una circunferencia [2*PI*r]";endline(4);
				cout<<"Introduce el radio: ";
				cin>>ejemploint;endline(5);
				cout<<"El resultado es: "<<ejemploint*2*PI;endline(6);
				endline(7);
				cout<<"Un numero por e [x*e]";endline(8);
				cout<<"Introduce un numero: ";
				cin>>ejemploint;endline(9);
				cout<<"El resultado es: "<<ejemploint*e;endline(10);
				endline(11);
				textcolor(14);
				system("PAUSE");

			}
		}
		letra=0;
		break;

		//ESTRUCTURAS DE FLUJO----------------------------------------------------------------------------------------------------------------
	case 2:
		while(subnum1!=4)
		{
			titulo("ESTRUCTURAS DE CONTROL DE FLUJO");

			cout<<"1. Secuencial.";endline(1);
			cout<<"2. Alternativas o Selectivas.";endline(2);
			cout<<"3. Bucles o Repetitivas.";endline(3);
			textcolor(12);
			cout<<"4. Atras";

			subnum1=opcion(1,4);
			switch(subnum1)
			{
			//SECUENCIAL------------------------------------------------------------------------------------------------------------------------
			case 1:
				while(letra!='A')
				{
					titulo("SECUENCIAL");

					cout<<"	* Las instrucciones se ejecutan una detras de otra, en el mismo orden en que";endline(1);
					cout<<"aparecen. Ademas, todas las acciones que la componen se ejecutan 1 sola vez.";endline(2);

					letra=fin_opciones();

					if(letra=='D')
					{
						titulo("EJEMPLOS");

						cout<<"Vamos a calcular el perimetro de un cuadrilatero.";endline(1);
						cout<<"Introduce la base: ";
						cin>>ejemploint;endline(2);
						cout<<"Introduce la altura: ";
						cin>>ejemploint2;endline(3);
						resultado=2*ejemploint+2*ejemploint2;
						cout<<"Su perimetro sera de: "<<resultado<<" unidades.";endline(4);
						endline(5);
						textcolor(14);
						system("PAUSE");
					}
				}
				letra=0;
				break;
				//ALTERNATIVAS O SELECTIVAS-------------------------------------------------------------------------------------------------------
			case 2:
				while(subnum2!=4)
				{
					titulo("ALTERNATIVAS O SELECTIVAS");

					cout<<"	* Permite elegir entre la realizacion de una accion u otra segun una condicion.";endline(1);
					cout<<"En las estructuras selectivas se evalua una condicion y en funcion de su resultado";endline(2);
					cout<<"se determina cual sera el siguiente paso.";endline(3);
					endline(4);
					cout<<"1. if";endline(5);
					cout<<"2. if else";endline(6);
					cout<<"3. switch case";endline(7);
					textcolor(12);
					cout<<"4. Atras.";

					subnum2=opcion(1,4);

					switch(subnum2)
					{
					//IF----------------------------------------------------------------------------------------------------------------------
					case 1:
						while(letra!='A')
						{
							titulo("IF");

							cout<<"	* En primer lugar se evalua la condicion, si el resultado de la expresion logica";endline(1);
							cout<<"es verdadero se ejecuta la accion indicada; en caso contrario, no se ejecutara,";endline(2);
							cout<<"continuara con la siguiente instruccion.";endline(3);
							endline(4);
							textcolor(14);
							cout<<"USO:";endline(5);
							textcolor(4);
							cout<<"if(condicion a seguir)";endline(6);
							textcolor(15);
							cout<<"{";endline(7);
							cout<<"	CODIGO";endline(8);
							cout<<"}";

							letra=fin_opciones();

							if(letra=='D')
							{
								titulo("EJEMPLOS");

								cout<<"Quieres que muestre en pantalla un numero aleatorio?[S/N]: ";endline(1);
								cout<<"(En caso negativo no realizara el ejemplo): ";
								cin>>ejemplochar;endline(2);
								ejemplochar=toupper(ejemplochar);
								while(ejemplochar!='S' && ejemplochar!='N')
								{
									endline(0);
									cout<<"Quieres que muestre en pantalla un numero aleatorio?[S/N]: ";endline(1);
									clreol();
									pagina();
									cout<<"(En caso negativo no realizara el ejemplo): ";
									cin>>ejemplochar;endline(2);
									ejemplochar=toupper(ejemplochar);
								}
								if(ejemplochar=='S')
								{
									ejemploint=rand();
									cout<<"Su numero aleatorio es: "<<ejemploint;endline(3);
								}
								endline(4);
								textcolor(14);
								system("PAUSE");
							}
						}
						letra=0;
						break;

						//IF ELSE------------------------------------------------------------------------------------------------------------------
					case 2:
						while(letra!='A')
						{
							titulo("IF ELSE");

							cout<<"	* El algoritmo seleccionara entre 2 posibles acciones en funcion del resultado";endline(1);
							cout<<"de una condicion, de forma que si la condicion se cumple se seleccione una";endline(2);
							cout<<"alternativa y en caso contrario se seleccione la otra.";endline(3);
							endline(4);
							textcolor(14);
							cout<<"USO:";endline(5);
							textcolor(4);
							cout<<"if(condicion a seguir)";endline(6);
							textcolor(15);
							cout<<"{";endline(7);
							cout<<"	CODIGO";endline(8);
							cout<<"}";endline(9);
							textcolor(4);
							cout<<"else";endline(10);
							textcolor(15);
							cout<<"{";endline(11);
							cout<<"	CODIGO";endline(12);
							cout<<"}";

							letra=fin_opciones();

							if(letra=='D')
							{
								titulo("EJEMPLOS");

								cout<<"Vamos a ver si un numero introducido es mayor o menor que 10.";endline(1);
								cout<<"Introduzca su numero: ";
								cin>>aux;
								ejemploint=conversor(aux);

								if(ejemploint<10)
								{
									endline(2);
									cout<<"Su numero es menor que 10.";endline(3);
								}
								else if(ejemploint==10)
								{
									endline(2);
									cout<<"Su numero es igual a 10.";endline(3);
								}
								else
								{
									endline(2);
									cout<<"Su numero es mayor que 10.";endline(4);
								}

								textcolor(14);
								system("PAUSE");
							}
						}
						letra=0;
						break;

						//SWITCH CASE------------------------------------------------------------------------------------------------------------
					case 3:
						while(letra!='A')
						{
							titulo("SWITCH CASE");

							cout<<"	* La estructura selectiva multiple permite seleccionar una alternativa de entre";endline(1);
							cout<<"varias posibles, en funcion del valor de una expresion.";endline(2);
							endline(3);
							textcolor(14);
							cout<<"USO:";endline(4);
							textcolor(4);
							cout<<"switch(expresion)";endline(5);
							textcolor(15);
							cout<<"{";endline(6);
							textcolor(4);
							cout<<"case n:";endline(7);
							textcolor(15);
							cout<<"	CODIGO";endline(8);
							textcolor(4);
							cout<<"	break;";endline(9);
							textcolor(15);
							cout<<"...";endline(10);
							cout<<"}";

							letra=fin_opciones();

							if(letra=='D')
							{
								titulo("EJEMPLOS");

								cout<<"Que color te gusta mas?";endline(1);
								cout<<"1[rojo], 2[azul], 3[amarillo], 4[verde]: ";
								cin>>aux;
								ejemploint=conversor(aux);
								while(ejemploint<1 || ejemploint>4)
								{
									endline(1);
									clreol();
									pagina();
									endline(1);
									cout<<"1[rojo], 2[azul], 3[amarillo], 4[verde]: ";
									cin>>aux;
									ejemploint=conversor(aux);
								}
								switch(ejemploint)
								{
								case 1:
									endline(2);
									textcolor(4);
									cout<<"Tu color favorito es el rojo!!";endline(4);
									break;
								case 2:
									endline(2);
									textcolor(1);
									cout<<"Tu color favorito es el azul!!";endline(4);
									break;
								case 3:
									endline(2);
									textcolor(14);
									cout<<"Tu color favorito es el amarillo!!";endline(4);
									break;
								case 4:
									endline(2);
									textcolor(2);
									cout<<"Tu color favorito es el verde!!";endline(4);
									break;
								}

								textcolor(14);
								system("PAUSE");
							}
						}
						letra=0;
						break;

					case 4:
						break;
					}
				}
				subnum2=0;
				break;
			case 3:
				while(letra!='A')
				{
					titulo("BUCLES O REPETITIVAS");

					cout<<"	* Estructura de control de flujo que describe la repeticion de una accion un";endline(1);
					cout<<"numero de veces determinado o indeterminado (apriori) apartir de una condicion.";endline(2);
					endline(3);
					textcolor(14);
					cout<<"USO:";endline(4);
					textcolor(4);
					cout<<"while(expresion)";endline(5);
					textcolor(15);
					cout<<"{";endline(6);
					cout<<"	CODIGO";endline(7);
					cout<<"}";endline(8);

					letra=fin_opciones();

					if(letra=='D')
					{
						titulo("EJEMPLOS");

						cout<<"Mientras tu respuesta no sea positiva, siempre preguntara lo mismo.";endline(1);
						cout<<"Quieres repetir?[S/N]: ";
						cin>>letra;
						letra=toupper(letra);

						while(letra!='N')
						{
							endline(1);
							clreol();
							pagina();
							endline(1);
							cout<<"Quieres repetir?[S/N]: ";
							cin>>letra;
							letra=toupper(letra);
						}

						endline(3);
						textcolor(14);
						system("PAUSE");
					}
				}
				break;
			case 4:
				break;
			}
		}
		subnum1=0;
		break;

		//Modulos-------------------------------------------
	case 3:
		while(subnum1!=3)
		{
			titulo("MODULOS");

			cout<<"	* Un modulo o subprograma, es un pequenio programa dentro de otro al que podemos";endline(1);
			cout<<"llamar cuando queramos.";endline(2);
			endline(3);
			cout<<"1. Funciones.";endline(4);
			cout<<"2. Procedimientos.";endline(5);
			textcolor(12);
			cout<<"3. Exit";

			subnum1=opcion(1,3);

			switch(subnum1)
			{
			case 1:
				while(subnum2!=3)
				{
					titulo("FUNCIONES");

					cout<<"	* Son aquellos modulos que devuelven un valor. Es necesario invocarla desde";endline(1);
					cout<<"otro modulo dado que la invocacion se sustituira por el valor devuelto.";endline(2);
					cout<<"Se representan asi:";endline(3);
					textcolor(4);cout<<"tipo de dato que devuelve ";textcolor(2);cout<<"nombre del modulo";textcolor(15);cout<<"(x)";endline(4);
					cout<<"{";endline(5);
					cout<<"	CODIGO";endline(6);
					cout<<"	return dato;";endline(7);
					cout<<"}";endline(8);
					cout<<"x puede referirse a nada (Sin paso de parametros) o a los valores que se le pase.";endline(9);

					endline(10);
					textcolor(14);
					cout<<"EJEMPLOS:";endline(11);
					textcolor(15);
					cout<<"1. Sin paso de parametros.";endline(12);
					cout<<"2. Con paso de parametros por valor.";endline(13);
					textcolor(12);
					cout<<"3. Exit";

					subnum2=opcion(1,3);

					switch(subnum2)
					{
					case 1:
						titulo("SIN PASO DE PARAMETROS");

						cout<<"El ejemplo mas sencillo para este caso seran los numeros aleatorios.";endline(1);
						cout<<"La funcion en cuestion seria rand()";endline(2);
						endline(3);
						ejemploint=rand();
						cout<<"El numero aleatorio esta vez es: "<<ejemploint;endline(4);
						endline(5);
						textcolor(14);
						system("PAUSE");

						break;
					case 2:
						titulo("CON PASO DE PARAMETROS POR VALOR");

						cout<<"El ejemplo mas sencillo para este caso seran las coordenadas.";endline(1);
						cout<<"La funcion en cuestion seria gotoxy(x,y)";endline(2);
						endline(3);
						cout<<"En la posicion que digas (ha de ser positiva) se escribira: HOLA";endline(4);
						cout<<"Introduce la x: ";
						cin>>ejemploint;
						while(ejemploint<0)
						{
							endline(4);
							clreol();
							pagina();
							endline(4);
							cout<<"Introduce la x: ";
							cin>>ejemploint;
						}
						endline(5);
						cout<<"Introduce la y: ";
						cin>>ejemploint2;
						while(ejemploint2<0)
						{
							endline(5);
							clreol();
							pagina();
							endline(5);
							cout<<"Introduce la y: ";
							cin>>ejemploint2;
						}
						textcolor(4);
						gotoxy(ejemploint-1,ejemploint2-1);
						cout<<"------";
						gotoxy(ejemploint-1,ejemploint2+1);
						cout<<"------";
						gotoxy(ejemploint-1,ejemploint2);
						cout<<"|";
						gotoxy(ejemploint+4,ejemploint2);
						cout<<"|";
						textcolor(15);
						gotoxy(ejemploint,ejemploint2);
						cout<<"HOLA";

						endline(7);
						textcolor(14);
						system("PAUSE");

						break;
					case 3:
						break;
					}
				}
				subnum2=0;
				break;
			case 2:
				while(subnum2!=4)
				{
					titulo("PROCEDIMIENTOS");

					cout<<"	* Son aquellos modulos que NO devuelven ningun valor, y se representan asi:";endline(1);
					textcolor(4);cout<<"void ";textcolor(2);cout<<"nombre del modulo";textcolor(15);cout<<"(x)";endline(2);
					cout<<"{";endline(3);
					cout<<"	CODIGO";endline(4);
					cout<<"}";endline(5);
					cout<<"x puede referirse a nada (Sin paso de parametros) o a los valores que se le pase.";endline(6);
					endline(7);
					textcolor(14);
					cout<<"EJEMPLOS:";endline(8);
					textcolor(15);
					cout<<"1. Sin paso de parametros.";endline(9);
					cout<<"2. Con paso de parametros por valor.";endline(10);
					cout<<"3. Con paso de parametros por variable.";endline(11);
					textcolor(12);
					cout<<"4. Exit";

					subnum2=opcion(1,4);

					switch(subnum2)
					{
					case 1:
						titulo("SIN PASO DE PARAMETROS");

						cout<<"	* Su uso habitual es para mostrar, ya que no devolvera ningun valor.";endline(1);
						cout<<"Un ejemplo muy claro son las paginas de este programa. No devuelven nada, sin";endline(2);
						cout<<"embargo se muestran siempre.";endline(3);
						endline(4);

						textcolor(14);
						system("PAUSE");

						break;
					case 2:
						titulo("CON PASO DE PARAMETROS POR VALOR");

						cout<<"	* Aqui se pasara el valor de una variable, pero jamas sera modificada.";endline(1);
						cout<<"Un ejemplo sera el cambio de colores de los caracteres.";endline(2);
						cout<<"Introduce tu nombre: ";
						cin>>aux;endline(3);
						cout<<"Ahora el color que desees 1[rojo] 2[azul] 3[amarillo] : ";
						cin>>aux2;
						ejemploint=conversor(aux2);
						while(ejemploint<1 || ejemploint>3)
						{
							endline(3);
							clreol();
							pagina();
							endline(3);
							cout<<"Ahora el color que desees 1[rojo] 2[azul] 3[amarillo] : ";
							cin>>aux2;
							ejemploint=conversor(aux2);
						}
						endline(5);
						switch(ejemploint)
						{
						case 1:
							textcolor(4);
							cout<<aux;

							textcolor(14);
							endline(7);
							system("PAUSE");
							break;
						case 2:
							textcolor(1);
							cout<<aux;

							textcolor(14);
							endline(7);
							system("PAUSE");
							break;
						case 3:
							textcolor(14);
							cout<<aux;

							textcolor(14);
							endline(7);
							system("PAUSE");
							break;
						}

						break;
						case 3:
							titulo("CON PASO DE PARAMETROS POR VARIABLE");

							cout<<"	* Aqui se pasara el valor de una variable y SI sera modificada.";endline(1);
							cout<<"Como ejemplo vamos a intercambiar el valor de 2 variables A y B";endline(2);
							cout<<"Introduce A: ";
							cin>>A;endline(3);
							cout<<"Introduce B: ";
							cin>>B;endline(4);
							intercambio_AB(A,B);
							cout<<"Ahora A vale: "<<A<<" y ahora B vale: "<<B;endline(5);
							endline(6);

							textcolor(14);
							system("PAUSE");

							break;
						case 4:
							break;
					}
				}
				subnum2=0;
				break;
			case 3:
				break;
			}
		}
		subnum1=0;
		break;

		//Vectores y Matrices------------------------------
	case 4:
		while(letra!='A')
		{
			titulo("VECTORES Y MATRICES");

			cout<<"	* Surge de la necesidad de tratar conjuntos de datos DEL MISMO TIPO relacionados";endline(1);
			cout<<"entre si, deforma que mediante un nombre comun y una variable o valor indicador";endline(2);
			cout<<"podamos referirnos bien a todos ellos o a uno en particular. Es una estructura de";endline(3);
			cout<<"datos estatica.";endline(4);
			endline(5);
			cout<<"Se puede representar en forma de vector:";endline(6);
			cout<<"1,2,3,4,5...";endline(7);
			endline(8);
			cout<<"O una matriz:";endline(9);
			cout<<"1 2 3";endline(10);
			cout<<"4 5 6";

			letra=fin_opciones();

			if(letra=='D')
			{
				clrscr();
				titulo("EJEMPLOS");

				cout<<"Para el ejemplo de vector vas a introducir un vector de tamanio 6 y se mostrara.";endline(1);
				for(int i=0;i<6;i++)
				{
					endline(1);
					clreol();
					pagina();
					endline(1);
					cout<<"Introduce el valor "<<i+1<<" del vector: ";
					cin>>ejemplovector[i];
				}
				endline(2);
				cout<<"Su vector es: ";
				for(int i=0;i<6;i++)
				{
					cout<<ejemplovector[i]<<" ";
				}
				endline(3);
				endline(4);
				cout<<"Ahora vas a hacer una matriz 2(filas)x3(columnas).";endline(5);
				for(int i=0;i<2;i++)
				{
					for(int j=0;j<3;j++)
					{
						endline(5);
						clreol();
						pagina();
						endline(5);
						cout<<"Introduce el valor "<<i+1<<"x"<<j+1<<" de la matriz: ";
						cin>>ejemplomatriz[i][j];
					}
				}
				endline(6);
				cout<<"Su matriz es: ";endline(7);
				for(int i=0;i<2;i++)
				{
					endline(7+i);
					for(int j=0;j<3;j++)
					{
						cout<<ejemplomatriz[i][j]<<" ";
					}
				}
				endline(10);
				textcolor(14);
				system("PAUSE");
			}
		}
		letra=0;
		break;

		//Algoritmo de la burbuja------------------------------------------------------------------------------------------------------------
	case 5:
		while(letra!='A')
		{
			titulo("ALGORITMO DE LA BURBUJA");

			cout<<"	* Recorre el vector con dos bucles for anidados, si N es el numero de elementos";endline(1);
			cout<<"del vector, el primer for se inicia en 1 y llegara hasta N menos 1. Y el segundo for";endline(2);
			cout<<"se inicia en 0 y llegara hasta N menos el indice del primer for.";endline(3);
			cout<<"	* El cuerpo del bucle mas interno se compone de una estructura de control de";endline(4);
			cout<<"flujo alternativa simple que compara la posicion del vector actual con la siguiente,";endline(5);
			cout<<"si es mayor se produce el intercambio de sus valores.";endline(6);

			letra=fin_opciones();

			if(letra=='D')
			{
				titulo("EJEMPLO");

				textcolor(14);cout<<"Ejemplo";textcolor(15);cout<<": define un vector de enteros, llenalo, ordenalo y muestra los valores antes y";endline(1);
				cout<<"despues de ordenarlos con el algoritmo de la burbuja.";endline(2);
				endline(3);

				for(int i=0;i<6;i++)
				{
					endline(3);
					clreol();
					pagina();
					endline(3);
					cout<<"Introduce el valor numero "<<i+1<<" del vector: ";
					cin>>aux;
					ejemplovector[i]=conversor(aux);
				}
				endline(5);

				cout<<"Su vector desordenado es: ";
				for(int i=0;i<6;i++)
				{
					cout<<ejemplovector[i]<<" ";
				}
				endline(6);

				for(int i=1;i<=5;i++)
				{
					for(int j=0;j<=6-i;j++)
					{
						if(ejemplovector[j]>ejemplovector[j+1])
						{
							intercambio_AB(ejemplovector[j],ejemplovector[j+1]);
						}
					}
				}

				endline(7);
				cout<<"Su vector ordenado es: ";
				for(int i=0;i<6;i++)
				{
					cout<<ejemplovector[i]<<" ";
				}

				endline(9);
				textcolor(14);
				system("PAUSE");
			}
		}
		letra=0;
		break;
		//Tipos de datos--------------------------------------------------------------------------------------------------------------------
	case 6:
		while(letra!='A')
		{
			titulo("TIPOS DE DATOS");

			cout<<"	* Un registro es una estructura de datos estatica, cuyos elementos pueden ser de";endline(1);
			cout<<"tipos distintos. A cada elemento del registro se accede por su nombre.";endline(2);
			endline(3);
			cout<<"Su estructura seria algo asi:";endline(4);
			textcolor(4);cout<<"typedef struct ";textcolor(1);cout<<"nombre";endline(5);
			textcolor(15);cout<<"{";endline(6);
			cout<<"	TipodeDato Dato";endline(7);
			cout<<"	...";endline(8);
			cout<<"}";

			letra=fin_opciones();

			if(letra=='D')
			{
				titulo("EJEMPLO");

				cout<<"Para este ejemplo daremos caracteristicas a un personaje.";endline(1);

				cout<<"Introduce su nombre: ";
				cin>>ejemplopersonaje.nombre;endline(2);

				cout<<"Introduce su nivel: ";
				cin>>aux;ejemploint=conversor(aux);
				while(ejemploint<=0)
				{
					endline(2);
					clreol();
					pagina();
					endline(2);
					cout<<"Su nivel debe ser mayor a 0: ";
					cin>>aux;ejemploint=conversor(aux);
				}
				ejemplopersonaje.nivel=ejemploint;endline(3);

				cout<<"Introduce sus vidas: ";
				cin>>aux;ejemploint=conversor(aux);
				while(ejemploint<=0)
				{
					endline(3);
					clreol();
					pagina();
					endline(3);
					cout<<"Su numero de vidas debe ser mayor a 0: ";
					cin>>aux;ejemploint=conversor(aux);
				}
				ejemplopersonaje.vidas=ejemploint;endline(4);
				endline(5);
				cout<<"Ahora mostraremos las caracteristicas de su personaje:";endline(6);
				cout<<"Nombre: "<<ejemplopersonaje.nombre;endline(7);
				cout<<"Nivel: "<<ejemplopersonaje.nivel;endline(8);
				cout<<"Vidas: "<<ejemplopersonaje.vidas;
				endline(10);

				textcolor(14);
				system("PAUSE");
			}
		}
		letra=0;
		break;

		//Ficheros de texto--------------------------------
	case 7:
		while(subnum1!=3)
		{
			titulo("FICHEROS DE TEXTO");

			cout<<"	* Es una coleccion de elementos logicamente relacionados y almacenados en";endline(1);
			cout<<"memoria secundaria. Es una estructura de datos dinamica.";endline(2);
			endline(3);
			cout<<"1. Escritura.";endline(4);
			cout<<"2. Lectura.";endline(5);
			textcolor(12);
			cout<<"3. Exit.";

			subnum1=opcion(1,3);

			switch(subnum1)
			{
			case 1:
				titulo("ESCRITURA");

				cout<<"Para el siguiente ejemplo vamos a usar el fichero *Prueba*.";endline(1);
				cout<<"Siguiendo el ejemplo de registros, vamos a guardar nuestro personaje.";endline(2);
				endline(3);

				escritura.open("prueba.txt");
				if(escritura.fail())
				{
					textcolor(4);
					cout<<"Error en la lectura del fichero.";
					textcolor(14);
					system("PAUSE");
				}
				else
				{
					textcolor(2);
					cout<<"El fichero se abrio correctamente.";endline(4);
					textcolor(15);
					endline(5);
					cout<<"Inserte el Nombre del personaje: ";
					cin>>ejemplopersonaje.nombre;
					escritura<<ejemplopersonaje.nombre<<" ";endline(6);
					cout<<"Inserte el Nivel del personaje: ";
					cin>>aux;ejemploint=conversor(aux);
					while(ejemploint<=0)
					{
						endline(6);
						clreol();
						pagina();
						endline(6);
						cout<<"Inserte el Nivel del personaje: ";
						cin>>aux;ejemploint=conversor(aux);
					}
					ejemplopersonaje.nivel=ejemploint;
					escritura<<ejemplopersonaje.nivel<<" ";endline(7);
					cout<<"Inserte las Vidas del personaje: ";
					cin>>aux;ejemploint=conversor(aux);
					while(ejemploint<=0)
					{
						endline(7);
						clreol();
						pagina();
						endline(7);
						cout<<"Inserte las Vidas del personaje: ";
						cin>>aux;ejemploint=conversor(aux);
					}
					ejemplopersonaje.vidas=ejemploint;
					escritura<<ejemplopersonaje.vidas<<" ";
					escritura.close();
				}

				endline(9);
				textcolor(14);
				system("PAUSE");

				break;
			case 2:
				titulo("LECTURA");

				cout<<"Para el siguiente ejemplo vamos a usar el fichero *Prueba*.";endline(1);
				cout<<"Vamos a visualizar nuestro personaje a partir de lo introducido en el apartado";endline(2);
				cout<<"escritura.";endline(3);
				endline(4);

				lectura.open("prueba.txt");
				if(lectura.fail())
				{
					textcolor(4);
					cout<<"Error en la lectura del fichero.";
					textcolor(14);
					system("PAUSE");
				}
				else
				{
					textcolor(2);
					cout<<"El fichero se abrio correctamente.";endline(5);
					textcolor(15);
					endline(6);
					lectura>>ejemplopersonaje.nombre;
					cout<<"Nombre del personaje: "<<ejemplopersonaje.nombre;endline(7);
					lectura>>ejemplopersonaje.nivel;
					cout<<"Nivel del personaje: "<<ejemplopersonaje.nivel;endline(8);
					lectura>>ejemplopersonaje.vidas;
					cout<<"Vidas del personaje: "<<ejemplopersonaje.vidas;
					lectura.close();
				}

				endline(10);
				textcolor(14);
				system("PAUSE");

				break;
			case 3:
				break;
			}
		}
		subnum1=0;
		break;

		//Prohibiciones en la asignatura-------------------
	case 8:
		titulo("PROHIBICIONES EN LA ASIGNATURA");

		cout<<"* Usar variables globales.";endline(1);
		cout<<"* Tener mas de ";textcolor(4);cout<<"un return ";textcolor(15);cout<<"en ";textcolor(4);cout<<"main() ";textcolor(15);cout<<"o en cualquier otra funcion o";endline(2);
		cout<<"  procedimiento.";endline(3);
		cout<<"* Usar ";textcolor(4);cout<<"break ";textcolor(15);cout<<"en cualquier lugar que no sea un switch.";endline(4);
		cout<<"* Salir de un ";textcolor(4);cout<<"for ";textcolor(15);cout<<"antes de su finalizacion.";endline(5);
		cout<<"* Usar ";textcolor(4);cout<<"exit() ";textcolor(15);cout<<"para finalizar el programa.";endline(6);
		endline(7);
		textcolor(14);
		system("PAUSE");

		break;

		//Buenas practicas de programacion-----------------
	case 9:
		titulo("BUENAS PRACTICAS DE PROGRAMACION");

		cout<<"* En las funciones ";textcolor(4);cout<<"solo ";textcolor(15);cout<<"debe haber parametros por valor, ";textcolor(4);cout<<"NO ";textcolor(15);cout<<"se debe pasar";endline(1);
		cout<<"  parametros por variable.";endline(2);
		cout<<"* Una funcion ";textcolor(4);cout<<"NO ";textcolor(15);cout<<"puede devolver un vector o matriz, ni un fichero.";endline(3);
		cout<<"* En los procedimientos, si existen parametros por variable de tipo simple o";endline(4);
		cout<<"  struct, siempre deberan ser ";textcolor(4);cout<<"mas de uno";textcolor(15);cout<<", si es solo uno, implicara que es una";endline(5);
		cout<<"  funcion.";endline(6);
		cout<<"* Los vectores son direcciones de memoria al primer elemento. Cuando se pasan a";endline(7);
		cout<<"  los modulos como parametros por variable ";textcolor(4);cout<<"NO ";textcolor(15);cout<<"se debe poner ";textcolor(4);cout<<"& ";textcolor(15);cout<<"y si se pasan por";endline(8);
		cout<<"  valor, es recomendable usar la palabra reservada ";textcolor(4);cout<<"const";textcolor(15);cout<<".";endline(9);
		cout<<"* Para gestionar ficheros, se deben usar las funciones propias de ficheros";endline(10);
		cout<<"  (eof(), fail(), open(), close(),...)";endline(11);
		endline(12);
		textcolor(14);
		system("PAUSE");

		break;

		//Salir--------------------------------------------
	case 10:
		break;
	}
}

void fin(){
	clrscr();

	titulo("FIN");

	cout<<"		  __^__                                      __^__";endline(1);
	cout<<"	         ( ___ )------------------------------------( ___ )";endline(2);
	cout<<"	          | | |                                      | | |";endline(3);
	cout<<"	          | | |        Gracias por su atencion       | | |";endline(4);
	cout<<"	          |___|                                      |___|";endline(5);
	cout<<"	         (_____)------------------------------------(_____) ";endline(6);

	caja_opciones();
	textcolor(14);
	gotoxy(xmin+2,ymin+alto+3);
	system("PAUSE");
}

void intercambio_AB(int &A,int &B)
{
	int aux;
	aux=A;
	A=B;
	B=aux;
}

//MODULOS--------------------------------------------------------------------------------------------------------------------------------
int opcion(int minimo,int maximo){
	char aux[max];
	int num;

	caja_opciones();

	gotoxy(xmin+2,ymin+alto+3);
	textcolor(15);
	cout<<"Selecciona una opcion: ";
	cin>>aux;
	num=conversor(aux);

	while(num<minimo || num>maximo)
	{
		gotoxy(xmin+2,ymin+alto+3);
		textcolor(14);
		cout<<"Debe seleccionar un numero entre "<<minimo<<" y "<<maximo<<endl;
		clreol();

		caja_opciones();

		gotoxy(xmin+2,ymin+alto+4);
		textcolor(15);
		cout<<"Selecciona una opcion: ";
		cin>>aux;
		num=conversor(aux);
	}
	return num;
}

void titulo(TITULO nombre)
{
	int i;
	int largo;

	clrscr();
	pagina();

	textcolor(colorpagina);

	//Vertical1----------------
	gotoxy(xmin,ymin+1);
	for(i=0;i<ymin+2;i++)
	{
		gotoxy(xmin,ymin+1+i);
		cout<<"|";
	}
	//Vertical2----------------
	gotoxy(xmin+ancho,ymin+1);
	for(i=0;i<ymin+2;i++)
	{
		gotoxy(xmin+ancho,ymin+1+i);
		cout<<"|";
	}
	//Horizontal1--------------
	gotoxy(xmin,ymin);
	for(i=xmin;i<=xmin+ancho;i++)
	{
		cout<<"-";
	}
	//Horizontal2--------------
	gotoxy(xmin,ymin+4);
	for(i=xmin;i<=xmin+ancho;i++)
	{
		cout<<"-";
	}
	//Titulo-------------------
	largo=strlen(nombre);
	textcolor(4);
	gotoxy(xmin+((xmin+ancho-xmin)/2)-(largo/2),ymin+2);
	cout<<nombre;
	textcolor(15);

	gotoxy(xmin,ymin+4);
	endline(0);
}
void pagina()//Siempre usar al final!!
{
	int i;

	textcolor(colorpagina);
	gotoxy(xmin,ymin);
	for(i=5;i<ymin+alto;i++){
		gotoxy(xmin,ymin+i);
		cout<<"|";
	}
	gotoxy(xmin+ancho,ymin);
	for(i=5;i<ymin+alto;i++){
		gotoxy(xmin+ancho,ymin+i);
		cout<<"|";
	}
	gotoxy(xmin,ymin+alto+1);
	for(i=xmin;i<=xmin+ancho;i++){
		cout<<"-";
	}

	textcolor(15);
	gotoxy(xmin+5,ymin+7);
}

char fin_opciones(){
	char variable;

	caja_opciones();

	textcolor(15);
	gotoxy(xmin+2,ymin+alto+4);
	cout<<"[A] Atras";
	gotoxy(xmin+ancho-15,ymin+alto+4);
	cout<<"[D] Ejemplos";

	gotoxy(((xmin+ancho)/2)-13,ymin+alto+3);
	textcolor(14);
	cout<<"Que desea hacer ahora?: ";
	textcolor(15);
	variable=getch();
	variable=toupper(variable);

	while(variable!='A' && variable!='D'){
		gotoxy((xmin+ancho)/2,ymin+alto+3);
		clreol();

		caja_opciones();

		gotoxy(((xmin+ancho)/2)-13,ymin+alto+3);
		textcolor(14);
		cout<<"Que desea hacer ahora?: ";
		textcolor(15);
		variable=getch();
		variable=toupper(variable);
	}
	return variable;
}

void caja_opciones(){ //Siempre usar antes de las opciones!!
	int i;

	textcolor(colorpagina);

	//Verticales
	gotoxy(xmin,ymin+alto+2);
	for(i=0;i<4;i++){
		gotoxy(xmin,ymin+alto+2+i);
		cout<<"|";
	}
	gotoxy(xmin+ancho,ymin+alto+2);
	for(i=0;i<4;i++){
		gotoxy(xmin+ancho,ymin+alto+2+i);
		cout<<"|";
	}

	//Horizontales
	gotoxy(xmin,ymin+alto+1);
	for(i=xmin;i<=xmin+ancho;i++){
		cout<<"-";
	}
	gotoxy(xmin,ymin+alto+6);
	for(i=xmin;i<=xmin+ancho;i++){
		cout<<"-";
	}
	textcolor(15);
}

int conversor(char aux[])
{
	int largo;
	int num=0;
	int i;
	bool letra=false;

	largo=strlen(aux);

	i=0;
	while(i<largo && letra==false)
	{
		if(aux[i]!='0' && aux[i]!='1' && aux[i]!='2' && aux[i]!='3' && aux[i]!='4' && aux[i]!='5' && aux[i]!='6' && aux[i]!='7' && aux[i]!='8' && aux[i]!='9')
		{
			letra=true;
		}
		i++;
	}

	if(letra==false)
	{
		num=atoi(aux);
	}
	else
	{
		num=0;
	}
	return num;
}
void endline(int y)
{
	gotoxy(xmin+5,ymin+6+y);
}
