#include <stdio.h>
#include <stdlib.h>

/*
9) Escreva uma função recursiva que calcule o valor da série S descrita a seguir para um valor de n>0 a ser fornecido como parâmetro para a mesma: S = 1 + (1/2!) + (1/3!) + ... + 1/n!. 
OBS. A função fatorial também deve ser recursiva.
*/

int fatorial(int n){
	if(n==0)
		return 1;
	else
		return n * fatorial(n-1);
}
float sequencia(int val){
	float S = 1.0/ fatorial(val);
	if(val>1)
		return S + sequencia(val-1);
	else
		return S;
}

int main(){
	int n=4;
	printf("\nValor: %d\nResultado da Sequencia: %f", n, sequencia(n));
}