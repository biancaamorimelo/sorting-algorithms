#include <stdio.h>
#include <stdlib.h>

    /***************************************************************************
     *  Aluna:          Bianca Karla Amorim de S. Melo 							*
     *	Matricula:      11408143                         						*
     *  									 							        *	 
     *  Implementacao do algoritmo QuickSort.      								*         
     *  									 							        *
     **************************************************************************/
     
//Funcao recursiva para ordenar um array de inteiros
void quickSort(int *V, int esq, int dir){
	int pivo;
	if(esq < dir){
		pivo = partition(V, esq, dir);  //Seperando os dados nas particoes da Direita e da Esquerda.
		quickSort(V, esq, pivo-1); //Chamando a funcao para a particao esquerda
		quickSort(V, pivo+1, dir); // Chamando a funcao para a particao direita
	}
}

//Funcao de particionamento dos elementos do vetor
int partition(int *V, int inicio, int fim){
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = fim;
	pivo = V[inicio]; //Pivo: posicao inicial do vetor
	
	while(esq < dir){
		while(V[dir] <= pivo){  //Incrementa uma posição para a esquerda
			esq = esq + 1;
		}
		while(V[dir] > pivo){  //Recua uma posição para direita
			dir = dir - 1;
		}
		if (esq < dir){   //Swap esquerda e direita
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}		
	}
	
	V[inicio] = V[dir];
	V[dir] = pivo;
	
	return dir;
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
	
	//Realizando a contagem da quantidade de elementos no array.
	numElementos = sizeof(V)/sizeof(V[0]);
		
	//Exibe os elementos do array antes de serem ordenados.
	printf("Array desordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	
	printf("\n");
	
	
	//Chamada da funcao para ordenacao dos elementos.
	quickSort(V, 0, numElementos-1);
	
	//Exibe os elementos do array ordenados.
	printf("Array ordenado: ");
	for(i = 0; i < numElementos; i++){
		printf("%d ", V[i]);
	}
	 
	return 0;
}




