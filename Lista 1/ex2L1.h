#include <stdio.h>
#include <stdlib.h>

/*
(2) Escreva um programa que leia o tamanho n do vetor e aloque memória para um vetor com n elementos inteiros, leia os valores e preencha o vetor.Imprima o vetor. 

Em seguida, ordene o vetor na ordem decrescente modificando um dos três algoritmos de ordenação simples estudado. 

Chame uma função que faça a busca sequencial de um elemento (lido via teclado na main) no vetor de valores inteiros ordenados em ordem decrescente. A função deve retornar 1 se o elemento estiver presente no vetor e 0, caso contrário. 

Imprima uma mensagem na main se achou ou não achou o elemento procurado.
*/

int *alocaMemoria(int);
void exibeVetor(int *,int);
void troca(int *, int *);

void inserctionSortD(int *, int);
int buscaSeqOrd(int *,int, int);

int main(){
	int *vetor,imp, tamanho_vetor = 5;

	printf("\n Informe o tamanho do vetor: ");
	scanf("%d",&imp);

	vetor = alocaMemoria(tamanho_vetor);

	int i;
	for(i=0; i<tamanho_vetor;i++){
		printf("\n Informe elementos para o vetor %d/%d \n(Não deve haver elemento repetidos)\n", i+1,tamanho_vetor);
		scanf("%d",&vetor[i]);

	}
	
	exibeVetor(vetor,tamanho_vetor);

	inserctionSortD(vetor, tamanho_vetor);

	exibeVetor(vetor,tamanho_vetor);

	int valor;
	printf("\nInforme o valor que deseja buscar no vetor: ");
	scanf("%d",&valor);

	if(buscaSeqOrd(vetor,tamanho_vetor, valor))
		printf("\n Achou!");
	else
		printf("\n Não Achou!");

}

int *alocaMemoria(int tam){
	int *Mry;
	Mry = (int*) malloc(tam*sizeof(int));
	if(*Mry){
		printf("\nSem memoria disponivel!\n");
		exit(1);
	}
	else{
		printf("\nMemoria alocada para %d elementos\n", tam);
		return Mry;
	}
}

void exibeVetor(int *vet,int vet_tam){
	int i;
	printf("\n[");
	for(i=0;i<vet_tam;i++)
		printf(" %d ",vet[i]);
	printf("]\n");
}

void troca(int *elemento_a, int *elemento_b){
	int aux;
	aux = *elemento_a;
	*elemento_a = *elemento_b;
	*elemento_b = aux;
}

void inserctionSortD(int *vetor, int tam){
	int i,j;
	for(j=1; j<tam; j++) {
		for(i=j; i>0 && vetor[i-1]<vetor[i] ; i--){
			troca(&vetor[i-1], &vetor[i]);
		}
	}
}

int buscaSeqOrd(int *vetor,int tamanho_vetor, int valAlvo) {
	int i;
	for(i=0; i< tamanho_vetor && valAlvo < vetor[i]; i++);

	if((i==tamanho_vetor) || (valAlvo != vetor[i]))
		return 0;
	return 1;
}