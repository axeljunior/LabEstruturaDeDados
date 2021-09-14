#include <stdio.h>
#include <stdlib.h>
#define TAM 10
/*
4) Escreva um programa que leia e imprima um vetor de inteiros. Em seguida, chame as seguintes funções recursivas:
	a) Função para calcular e retornar a soma dos elementos no vetor;
	b) Função para calcular e retornar o valor mínimo do vetor;
	c) Função para calcular e retornar o valor máximo do vetor;
	d) Função para calcular e retornar a média dos valores no vetor;
	e) Função para imprimir os valores do vetor em ordem inversa (sem trocá-los de
	ordem no vetor).
*/

//(X) Função para calcular e retornar a soma dos elementos no vetor;
int somatorio(int *vet,int tam,int somat){
	somat += *(vet+tam);
	
	if(tam <= 0)
		return somat;
	else
		return somatorio(vet,tam-1,somat);
}

//(X) Função para calcular e retornar o valor máximo do vetor;
int elemento_max(int *vet,int tam,int max){
	if( *(vet+tam) > max)
		max = *(vet+tam);

	if(tam <= 0)
		return max;
	else
		return elemento_max(vet,tam-1,max);
}
//(X) Função para calcular e retornar o valor minimo do vetor;
int elemento_min(int *vet,int tam,int min){
	if( *(vet+tam) < min)
		min = *(vet+tam);
	if(tam <= 0)
		return min;
	else
		return elemento_min(vet,tam-1,min);
}

//(X) Função para calcular e retornar a média dos valores no vetor;
float media_elementos(int *vet,int tam,int media){
	media += *(vet+tam);

	if(tam <= 0)
		return (float) media/TAM;
	else
		return media_elementos(vet, tam-1, media);
}
//(X) Função para imprimir os valores do vetor em ordem inversa (sem trocá-los de ordem no vetor).
int imprime_inverso(int *vet,int tam,int somat){
	printf("%d\t",*(vet+tam));
	
	if(tam < 0)
		return somat;
	else
		return imprime_inverso(vet,tam-1,somat);
}
int main(){
	int i;
	int *vetor = (int*) malloc(TAM * sizeof(int));

	for(i=0; i<TAM; i++)
		vetor[i] = i+1;
		
	printf("\nElementos do vetor: \n");
	for(i=0; i<TAM; i++)
		printf("%d\t", vetor[i]);

	int n=5;

	printf("\n\n");
	
	printf("\nSomatorio dos elementos: %d", somatorio(vetor, TAM-1, 0));
	printf("\nMedia dos elementos: %f", media_elementos(vetor, TAM-1, 0));
	printf("\nValor máximo do vetor: %d", elemento_max(vetor, TAM-1, vetor[0]));
	printf("\nValor minimo do vetor: %d", elemento_min(vetor, TAM-1, vetor[0]));
	printf("\nOrdem inversa: ");
	imprime_inverso(vetor, TAM-1, vetor[0]);

	free(vetor);
}