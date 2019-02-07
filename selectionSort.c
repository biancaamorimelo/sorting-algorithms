#include <stdio.h>
#include <stdlib.h>

    /***************************************************************************
     *  Aluna:          Bianca Karla Amorim de S. Melo 							*
     *	Matricula:      11408143                         						*
     *  									 							        *	 
     *  Implementacao do algoritmo SelectionSort.    							*         
     *  									 							        *
     **************************************************************************/

//Funcao ordenar array de inteiros
void selectionSort(int *V, int n){
	int i, j;
	int i_min, temp;
	
	for (i = 0; i < n-1; i++){
		i_min = i;
		for(j = i+1; j < n; j++){ 
			if(V[j] < V[i_min]){ 
				i_min = j;  //Atualiza o valor da menor posicao
			}
		}
		if(i != i_min){  //Troca o valor das posições atual e menor
			temp = V[i];
			V[i] = V[i_min];
			V[i_min] = temp; 
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
	selectionSort(V, numElementos);
	
	//Exibe os elementos do array ordenados.
	printf("Array ordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	
	return 0;
     	
}
