#include <stdio.h>
#include <stdlib.h>

#define TAM 3
/*
6) Escreva uma função recursiva para fazer o produto interno entre dois vetores de mesmo
tamanho. Escreva também a chamada da função. Ex: Sejam v={1,2,3} e w={4,5,6} então o
prodint=1*4 + 2*5 + 3*6 = 4+10+18=32. Escreva também a chamada da função.
*/

int produtoInterno(int v1[],int v2[],int tam,int prod){
	prod += v1[tam] * v2[tam];
	if(tam<=0)
		return prod;
	else
		return produtoInterno(v1,v2,tam-1,prod);
}

int main(){
	int i;
	int vetor1[TAM] = {1,2,3}, vetor2[TAM] = {4,5,6};
		
	printf("\nElementos do Vetor 1: \n");
	for(i=0; i<TAM; i++)
		printf("%d\t", vetor1[i]);
	printf("\nElementos do Vetor 2: \n");
	for(i=0; i<TAM; i++)
		printf("%d\t", vetor2[i]);
	printf("\nProduto interno: %d",produtoInterno(vetor1,vetor2,TAM-1,0));
}