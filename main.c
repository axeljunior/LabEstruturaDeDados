#include <stdio.h>
#include <stdlib.h>

#include "ordenation.h"

#include "Outros/pontResumo.h" // Apagar
#include "Outros/tools.h" // Apagar

/*
1) Escreva um programa que leia o tamanho n do vetor, aloque memória,
leia n números inteiros sem repetição de valores e preencha o vetor.
Imprima o vetor. Em seguida, mostre um menu com as seguintes opções:

	1 - Ordenar por trocas (Bubblesort)
	2 - Seleção
	3 - Insevoid
*/

void alocaMemoria(int tam);
void preencherVetor(int *vet,int vet_tam);
void exibeVetor(int *vet,int vet_tam);
void menu(int *vet,int vet_tam);

void Selection_Sort(int *vet,int vet_tam);
void Insert_Sort(int *vet,int vet_tam);

int main() {
	srand(time(NULL)); // Apagar

	int tamanho_vetor,*Vetor;

	printf("Informe o tamanho do Vetor: ");
	scanf("%d", &tamanho_vetor);

	alocaMemoria(tamanho_vetor);
	preencherVetor(Vetor,tamanho_vetor);
	
//	exibeVetor(Vetor,tamanho_vetor); ///

//	bubbleSort(Vetor, tamanho_vetor); //

//	exibeVetor(Vetor,tamanho_vetor); //

	menu(Vetor,tamanho_vetor);
}
//===
void menu(int *vet, int vet_tam){
	int opt=0,menu=1;

	while(menu){
		exibeVetor(vet,vet_tam);
		printf("\nOque deseja fazer? Escolha uma opção: \n(1) Bubble sort \n(2) Selection sort \n(3) Inserction sort\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Bubble sort");
				bubbleSort(vet, vet_tam);
				break;
			case 2:
				printf("Selection sort");
				selectionSort(vet, vet_tam);
				break;
			case 3:
				printf("Inserction sort");
				inserctionSort(vet, vet_tam);
				break;
			default:
				printf("Opção invalida");
		}
		system("clear");
	}
}
//===
void alocaMemoria(int tam){
	int *Mry = (int*) malloc(tam*sizeof(int));
	if(*Mry){
		printf("\nSem memoria disponivel!\n");
		exit(1);
	}
	else{
		printf("\nMemoria alocada para %d elementos\n", tam);
	}
}
//===
void preencherVetor(int *vet,int vet_tam){
	int valor_imput,ctrl = 0;
	
	while(ctrl<vet_tam){
		printf("\nInforme um valor para o Vetor: ");

		valor_imput = imput(vet_tam);
		//scanf("%d",&valor_imput);

		for(int i=0;i<=ctrl;i++){
			if(valor_imput == vet[i]){
				printf("\n valor_imput = %d vet[%d] = %d",valor_imput,i,vet[i]);
				printf("\nO valor não pode ser repetido\n");
				break;
			}else if(i == ctrl){
				vet[i] = valor_imput;
				ctrl++;
				break;
			}
		}
	}
}
//===
void exibeVetor(int *vet,int vet_tam){
	printf("\n\n[");
	for(int i=0;i<vet_tam;i++){
		printf(" %d ",vet[i]);
	}
	printf("]\n");
}
