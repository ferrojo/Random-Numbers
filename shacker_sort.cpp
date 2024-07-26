//Ejemplo generar numeros aleatorios del 1 al 20.
#include <cstdlib> //tiene la definicion de la funcion RAND (random)
#include <windows.h> // Para utilizar Beep y Sleep
# include<stdio.h> // Flujo de entradas cout(imprimir) e cin(guardar valores)
# include<stdlib.h> // Gestión de memoria dinámica, control de procesos
# include <iostream> // Flujo de entradas cout(imprimir) e cin(guardar valores)
# include <conio.h> // ultilizamos los comandos getch(), clrscr(), gotoxy()


using namespace std; 

//******** Declaramos Funciones *********
int menu (void);
void ingresar(void);
void shaker(void);
void cards(void);
void mostrar(void);
void mostrar2(void);
void gotoxy(int,int);

//******** Variables generales ********
int arreglo[20];
int cantidad;
int temp; 
int resp;
void gotoxy(int,int);
int i;

int main()
{ // INICIO DEL MAIN

        char opc=0;
        
    do{
	menu:
        opc=menu();
        
        switch (opc){// INICIO SWITCH
        	
        	case 59:
        		
        		system("cls");
        		ingresar();
        		Sleep(2000);
        		goto menu;
					
        		
        		break;
        		
        	case 60:
        		
        		system("cls");
        		mostrar();
        		getch();
        		goto menu;
					
        		
        		break;
        		
        	case 61:
        		
        		system("cls");
        		mostrar2();
        	    getch();
        	    goto menu;
				
        		
        		break;
        		
        		
        	case 27:
        		
        		system("cls");
        		gotoxy(35,5); cout<<"GRACIAS POR USAR ESTE PROGRAMA";
        	    Sleep(1500);
        		return 0;
        	
        	break;
        	
        	
		}// CIERRE SWITCH
 
    }while(opc>0 && opc<5);

}// CIERRE DEL MAIN


int menu(){// INICIA MENU
 
 char opc1='\0';
 
 system("cls");
 
 gotoxy(45,3); cout<<"BIENVENIDO";
 gotoxy(28,4); cout<<"PROGRAMA QUE ORDENA NUMEROS DE MENOR A MAYOR";
 gotoxy(28,6); cout<<" [F1] Ingresar";
 gotoxy(28,7); cout<<" [F2] Shaker sort ";
 gotoxy(28,8); cout<<" [F3] Deck of cards sort";
 gotoxy(28,10); cout<<"  Esc.  SALIR ";
 
 //cin>>opc;
 opc1=getch();
 	if (opc1==0){
		
		opc1 = getch();
	}
	
	return opc1;//Retornar la opcion ingresada
 
	
}// CIERRA MENU

//**************** INGRESAR *****************
void ingresar(){
	
	system("cls");
	
	do{
	
	gotoxy(26,7); cout<<"INGRESE LA CANTIDAD DE  NUMEROS QUE DESEA ORDENAR ";
  cin>>cantidad;
  
  system("cls");
  if(cantidad<1 || cantidad>20)
  {
  gotoxy(26,7); cout<<"ERROR, INGRESE UN NUMERO POSITIVO NO MAYOR A 20";
  Beep(1000,100);
  Sleep(2000);
  system("cls");

  
  
  }
  
  if(cantidad>1 || cantidad<20)
  gotoxy(26,7); cout<<"CANTIDAD GUARDADA";
  
  }while (cantidad<1 || cantidad>20);
}



//*************** SACUDIDA ***************
void mostrar(){//inicia funcion
	
	system("cls");
	cout<<"MOSTRAMOS NUMEROS ALEATORIOS"<<endl;
  
for ( i=0; i<cantidad; i++)
{
	arreglo[i]=rand()%50;
	cout<<arreglo[i]<<endl;
}

for (int x=0; x<(cantidad-1); x++) 
{
	for (int j=x+x ; j<cantidad; j++)
	{
		if(arreglo[j]<arreglo[x])
		{
			temp=arreglo[j];
			arreglo[j]=arreglo[x];
			arreglo[x]=temp;
		}
	}
}

cout<<"MOSTRAMOS NUMEROS ORDENADOS"<<endl;

for ( i=0; i<cantidad;i++)
{
	cout<<arreglo[i]<<endl;
}
	
	
}//cierra funcion

//*************** BARAJA *****************
void mostrar2(){
	int K,AUX;
	
	cout<<"MOSTRAMOS NUMEROS ALEATORIOS"<<endl;
  
for ( i=0; i<cantidad; i++)
{
	arreglo[i]=rand()%50;
	cout<<arreglo[i]<<endl;
}


	
	for (int x=0; x<(cantidad-1); x++) 
{
	for (int j=x+x ; j<cantidad; j++)
	{
		if(arreglo[j]<arreglo[x])
		{
			temp=arreglo[j];
			arreglo[j]=arreglo[x];
			arreglo[x]=temp;
		}
	}
}

cout<<"MOSTRAMOS NUMEROS ORDENADOS"<<endl;

for ( i=0; i<cantidad;i++)
{
	cout<<arreglo[i]<<endl;
}
	
	

}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
