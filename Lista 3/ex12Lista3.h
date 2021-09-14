#include <stdio.h>
#include <stdlib.h>

/*
12) Escreva uma função recursiva que recebe um número n e retorne a soma dos dígitos do número.
*/

int somaDigitos(int n, int soma){
	int digito = n % 10;
	soma += digito;
    if(n != 0){
		return somaDigitos(n/10,soma);
		
    }
    return soma;
}

int main(){
	int numero = 235;

	printf("\nNumero: %d\nSoma dos digitos: %d", numero, somaDigitos(numero, 0));
}