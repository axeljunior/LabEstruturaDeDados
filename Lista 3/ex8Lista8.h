#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3
/*
8) Escreva uma função recursiva para retornar o tamanho de uma string (não é para usar a função strlen()). Escreva também a chamada da função.
*/

int length(char s1[], int tam){
	if(s1[tam] == '\0')
		return tam;
	else
		return length(s1,tam+1);
}

int main(){
	char string[10] = "Testando";
	printf("\n%s, Tamanho: %d", string, length(string,0));
}