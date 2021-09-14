#include <stdio.h>
#include <stdlib.h>

#define TAM 5

/*
1) Faça uma função recursiva que receba um vetor de inteiros e dobre os valores de todos seus componentes. Escreva também a chamada a função.
*/

int *dobra_vetor(int *v, int tam, int posit){
	v[posit] *= 2;
	if(posit < tam)
		return v = dobra_vetor(v, tam, posit+1);
	else
		return v;
}

int main(){
	int i;
	int *vetor = (int*) malloc(TAM * sizeof(int));

	for(i=0; i<TAM; i++)
		vetor[i] = i;
		
	printf("\nValor do vetor: \n");
	for(i=0; i<TAM; i++)
		printf("%d\t", vetor[i]);

	vetor = dobra_vetor(vetor, TAM, 0);

	printf("\nValor do vetor dobrado: \n");
	for(i=0; i<TAM; i++)
		printf("%d\t", vetor[i]);
	
	free(vetor);
}