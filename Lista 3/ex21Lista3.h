#include <stdio.h>
#include <stdlib.h>

/*
21) Escreva uma função recursiva para testar se um número é primo.
*/

int testaMultiplo(int val,int seq){
	if(val%seq == 0 && seq < val)
		return 0;
	else if(val == seq)
		return 1;
	return testaMultiplo(val,seq+1);
}
int primo(int valor){
	if(valor == 1)
		return 0;
	else if(valor == 2)
		return 1;
	if(testaMultiplo(valor,2))
		return 1;
	else
		return 0;
}

int main(){
	int numero = 113;
	printf("\nNumero: %d\nÉ primo? %s", numero, primo(numero) == 1 ? "Sim" : "Não");
}