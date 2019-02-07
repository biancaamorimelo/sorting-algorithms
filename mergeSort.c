#include <stdio.h>
#include <stdlib.h>

    /***************************************************************************
     *  Aluna:          Bianca Karla Amorim de S. Melo 						   *
	 *	Matricula:      11408143                         					   *
   	 *  																       *	 
     *  Implementacao do algoritmo de ordenacaoo por comparacao MergeSort.     *         
     *  																       *
     **************************************************************************/


//Fun��o para fundir o lado esquerdo e direito ao array V.
//esqCont = n�mero de elementos na esquerda (E).
//dirCont = n�mero de elementos na direita (D).
void merge(int *V, int *E, int esqCont, int *D, int dirCont){
	int i, j, k;  // i (E), j (D), k (V)
	
	i = 0; j = 0; k = 0;
	
	while (i < esqCont && j < dirCont){
		if(E[i] < D[j]){
			V[k++] = E[i++];
		} else {
			V[k++] = D[j++];
		}
	}
	
	while (i < esqCont){
		V[k++] = E[i++];
	}
	
	while (j < dirCont){
		V[k++] = D[j++];
	}
}

//Fun��o recursiva para ordenar um array de inteiros
void mergeSort(int *V, int tam){
	int meio;
	int i;
	int *E, *D;
	
	if (tam < 2) return;  //Se o array possui menos de 2 elementos, n�o fazer nada.
	
	meio = tam/2; //Encontrar o �ndice do meio
	
	//Cria os subarrays da esquerda e da direita
	//Elementos do meio (do �ndice 0 at� meio-1) devem fazer parte do array da esquerda
	//Demais elementos (ou seja, meio a tam-1) s�o da direita
	
	E = (int*)malloc(meio*sizeof(int));
	D = (int*)malloc((tam-meio)*sizeof(int));
	
	for(i = 0; i < meio; i++){
		E[i] = V[i]; //Criando o array da esquerda
	}
	
	for (i = meio; i < tam; i++){
		D[i - meio] = V[i]; //Criando o array da direita
	}
	
	mergeSort(E, meio); //Ordena o array da esquerda;
	mergeSort(D, tam-meio); //Ordena o array da direita;
	merge(V, E, meio, D, tam-meio); //Unindo D e E ao array V ordenados;
	
	free(E);
	free(D);
}

int main(){
	
	int V[] = {1, 10, 12, 8, 7, 5, 6, 7, 2, 0, 9, 4, 3, 11}; //Array de inteiros
	int i, numElementos;
	
	//Realizando a contagem da quantidade de elementos no array.
	numElementos = sizeof(V)/sizeof(V[0]);
	
	//Exibe os elementos do array antes de serem ordenados.
	printf("Array desordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	
	printf("\n");
	
	
	//Chamada da fun��o para ordena��o dos elementos.
	mergeSort(V, numElementos);
	
	//Exibe os elementos do array ordenados.
	printf("Array ordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	 
	return 0;
}
