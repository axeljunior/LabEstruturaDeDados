#include <stdio.h>
#include <stdlib.h>

/*
13) Escreva uma função recursiva recebe um número inteiro n > 0, conta e retorna o número de dígitos pares do número.

*/

int contaDigitosPares(int n, int cont){
	int digito = n % 10;

    if(n != 0){
		if(digito%2 == 0)
			cont++;
		return contaDigitosPares(n/10,cont);
    }
    return cont;
}

int main(){
	int numero = 106;

	printf("\nNumero: %d\nQuantidade de Digitos Par: %d", numero, contaDigitosPares(numero, 0));

}