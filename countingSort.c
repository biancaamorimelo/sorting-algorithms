#include <stdio.h>
#include <stdlib.h>

#define MAX 100

    /***************************************************************************
     *  Aluna:          Bianca Karla Amorim de S. Melo 							*
     *	Matricula:      11408143                         						*
     *  									 							        *	 
     *  Implementacao do algoritmo CountingSort.    							*         
     *  									 							        *
     **************************************************************************/
     

void countingSort(int *V, int n){
	int i, j, k;
	int bucket[MAX];  //Onde cada valor ordenado será armazenado
	
	// Preenchendo o vetor com zeros
	for(i = 0; i < MAX; i++){
		bucket[i] = 0;
	}
	
	//Armazena no balde o número de ocorrências de cada elemento do array no índice correspondente
	for(i = 0; i < n; i ++){
		bucket[V[i]]++;  
	}
	
	for(i = 0, j = 0; j < MAX; j++){
		for(k = bucket[j]; k > 0; k--){
			V[i++] = j;
		}
	}
}


int main(){
	
	int i, numElementos;
	int *V;
	
	printf("Informe o tamanho do vetor a ser ordenado: \n");
	scanf("%d", &numElementos);	
	
	V = (int*)malloc(numElementos*sizeof(int));
	
	printf("Informe o vetor a ser ordenado: \n");
	for(i = 0; i < numElementos; i++){
		scanf("%d", &V[i]);
	}
	
	//Exibe os elementos do array antes de serem ordenados.
	printf("Array desordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	
	printf("\n");
	
	//Chamada da funcao para ordenacao dos elementos.
	countingSort(V, numElementos);
	
	//Exibe os elementos do array ordenados.
	printf("Array ordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	
	return 0;	
	
}
