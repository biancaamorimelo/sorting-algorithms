#include <stdio.h>
#include <stdlib.h>

    /***************************************************************************
     *  Aluna:          Bianca Karla Amorim de S. Melo 							*
     *	Matricula:      11408143                         						*
     *  									 							        *	 
     *  Implementacao do algoritmo de ordenacao por heapSort.    				*         
     *  									 							        *
     **************************************************************************/
     

struct maxHeap
{
	int tam;
	int *V;
}

int pai(int i){
	return (i-1)/2;  
}

int esquerdo(int i){
	return (i*2+1);
}

int direito(int i){
	return (i*2+1)+1;
}

void troca(int *V, int *V2){
	int aux;
	
	aux = *V;
	*V = *V2;
	*V2 = aux; 
}

void maxHeapify(struct maxHeap* maxHeap, int i){
	int filhoEsquerdo, filhoDireito, maior;
	
	filhoEsquerdo = esquerdo(i);
	filhoDireito = direito(i);
	maior = i;
	
	// Verifica se o filho da esquerda e maior 
	if(filhoEsquerdo < maxHeap->tam && maxHeap->V[filhoEsquerdo] > maxHeap->V[maior]){
		maior = filhoEsquerdo;
	}
	
	// Verifica se o filho da direita e maior
	if(filhoDireito < maxHeap->tam && maxHeap->V[filhoDireito] > maxHeap->V[maior]){
		maior = filhoDireito;
	}
	
	// Ao encontrar o maior, faz a troca 
	if(maior != i){
		troca(&maxHeap->V[maior], &maxHeap->V[i]);
		maxHeapify(V, maior); //Recursivamente
	}	
}

struct maxHeap* buildMaxHeap(int *V, int tam){
	int i;
	
	struct maxHeap* maxHeap = (struct maxHeap*) malloc(sizeof(struct maxHeap));
	
	maxHeap->tam = tam;
	maxHeap->V = V;
		
	for(i = (maxHeap->tam-2)/2; i >= 0; --i){
		maxHeapify(maxHeap, i);
	}
	
	return maxHeap;
}

void heapSort(int *V, int n){
	
	struct maxHeap* maxHeap = buildMaxHeap(V, n);
    
	//Troca a raiz com a o último elemento e subtrai o tamanho do Heap
    //Raiz do heap é sempre o maior elemento
	while(maxHeap->n > 1){
		troca(&maxHeap->V[0], &maxHeap->V[maxHeap->tam-1]);
		--maxHeap->tam;   //Diminui o tamanho do heap
	
		maxHeapify(maxHeap, 0);
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
	heapSort(V, numElementos);
	
	//Exibe os elementos do array ordenados.
	printf("Array ordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	
	return 0;
     	
}




