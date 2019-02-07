#include <stdio.h>
#include <stdlib.h>

    /***************************************************************************
     *  Aluna:          Bianca Karla Amorim de S. Melo 							*
     *	Matricula:      11408143                         						*
     *  									 							        *	 
     *  Implementacao do algoritmo de ordenacao por insercao InsertionSort.    	*         
     *  									 							        *
     **************************************************************************/


void insertionSort(int *V, int n){
	int i, j;
	int pivo = 0;
	
	for(i = 1; i < n; i++){
		pivo = V[i];  // Menor numero
		for(j = i; (j > 0) && (pivo < V[j-1]); j--){
			//Troca se um elemento maior for encontrado a esquerda
			V[j] = V[j-1];
		}
		
		V[j] = pivo; //Recupera o pivo
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
	insertionSort(V, numElementos);
	
	//Exibe os elementos do array ordenados.
	printf("Array ordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	
	return 0;
     	
}


