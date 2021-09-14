#include <stdio.h>
#include <stdlib.h>
#define TAM 9
/*
14) Escreva uma função recursiva que calcule e retorne a soma dos elementos positivos do vetor de inteiros.
*/

int somaElementosPositivos(int v[], int tam, int soma){
    if(tam >= 0){
		if(v[tam] > 0)
			soma += v[tam];
		return somaElementosPositivos(v,tam-1,soma);
    }
    return soma;
}

int main(){
	int vetor[TAM] = {1,-2,3,-4,5,-6,7,-8,9};
	int i;
	printf("Elementos do Vetor: ");
	for(i=0;i<TAM;i++)
		printf("%d\t",vetor[i]);
	printf("\nSoma dos elementos Positivos: %d", somaElementosPositivos(vetor, TAM-1, 0));
}