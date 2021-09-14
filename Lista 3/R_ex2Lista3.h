#include <stdio.h>
#include <stdlib.h>

/*
2) Escreva uma função recursiva para apresentar a soma de todos os números inteiros pares de zero até um número informado pelo usuário.

Por exemplo: Para n = 9 a função deve retornar 0 + 2 + 4 + 6 + 8 = 20
*/

int somatorio(int val, int somat){
	if(val%2 == 0){
		printf("%d +\t", val);
		somat += val;
	}

	if(val == 0)
		return somat;
	else
		return somatorio(val-1,somat);
}

int main(){
	int soma, n = 9;
	printf("\nSomatorio: ");
	printf("= %d", somatorio(n,0));
}