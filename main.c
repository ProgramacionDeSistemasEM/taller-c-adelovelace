#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
 
int main(int argc, char **argv){
	
	int elementos = 0;
	char c = 0;
	
	
	//Aqui manejamos las opciones.
	//El argumento -p tiene un argumento, que es 
	//el numero de elementos a pedir (por eso el :)
	while ((c = getopt (argc, argv, "p:")) != -1){
		switch(c){
			case 'p':
				elementos = atoi(optarg);
				break;
			default:
				printf("Argumento invalido\n");
				exit(1);
		}
	}

	//Los resultados de sus calculos van en estas variables.
	//Puede declarar más variables si lo necesita.
	float sum = 0.0f;
	float max_imc = 0.0f;
	

	//declaracion de variable peso y altura
	float peso = 0.0;
	float altura = 0.0;

	//arreglo de los elementos 
	char Peso[elementos];
	char Altura[elementos];


	for(int i =0 ; i < elementos ; i++){
	
		printf("Peso:");
		scanf("%2f",&peso);
 		
	
		if(peso == 0.0){
			printf("Numero invalido\n");
			exit(1);
		}

	
		printf("Altura:");
		scanf("%2f", &altura);
		

		if (altura == 0.0){
			printf("Numero invalido\n");
			exit(1);
		}
		

		Peso[i] = peso;
	      	Altura[i] = altura;	
	      	
	 
	}
	
	char IMC[elementos];
	
	//calculo del ICM
	for(int i = 0;i <elementos;i++){
		IMC[i] = Peso[i] / (Altura[i] * Altura[i]);
	}
	
	float promedioIMC = 0.0;	
	float maxIMC = 0.0;
	
	//promedio del ICM y el maximo ICM
	for(int i = 0;i <elementos;i++){
		promedioIMC += IMC[i];
		
		if(IMC[i] > IMC[i+1]){
			maxIMC = IMC[i];
		}
	}
	
	
	printf("Promedio IMC: %.2f\n",promedioIMC);
	printf("Maximo IMC: %.2f\n",maxIMC);
	
		
	
	//No modifique estas lineas
	//Guarde los resultados en las 
	//variables sum y max_imc
	printf("\npromedio IMC: %.1f\n", sum);
	printf("maximo IMC: %.1f\n", max_imc);
}	
