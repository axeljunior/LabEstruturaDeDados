#include <stdio.h>
#include <stdlib.h>

/*
15) Escreva uma função recursiva que recebe um número inteiro positivo e mostre o dígito mais significativo.
*/

int digitoSignificativo(int n, int digito){
    if(n > 0){
		//if(n % 10 > digito) // Se o "Dígito mais significativo" for o maior retire o comentario do if, se "Dígito mais significativo" for o mais a esquerda mantenha comentado.
			digito = n % 10;
		return digitoSignificativo(n/10, digito);
    }
	return digito;
}

int main(){
	int numero = 235;
	printf("\nNumero: %d\nDigito significativo: %d", numero, digitoSignificativo(numero, 0));
}