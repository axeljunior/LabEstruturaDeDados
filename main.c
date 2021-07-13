#include <stdio.h>
#include <stdlib.h>

#include "Outros/pontResumo.h"
#include "Outros/tools.h"


/*
#include "ordenation.h"
#include "search.h"
#include "pilha.h"
#include "ex1.h"
#include "ex2.h"
int main() {
	srand(time(NULL));
	// Chama os exemplos
	//ex1(); // Ex: Ordenação e Busca
	ex2();
}
*/

/*
5) Escreva um programa que utilizando uma pilha, determine se uma string lida é um palíndromo ou não, isto é, se a string pode ser lida da mesma maneira para frente ou para trás. Ex: ovo, arara, osso.
*/

#define TAM 100

typedef struct tpilha {
	int topo;
	char pilha[TAM];
}PILHA;

void inicializaPilha(struct tpilha *);
int pilhaVazia(struct tpilha *);
int pilhaCheia(struct tpilha *);
int empilha(struct tpilha *, char);
char desempilha (struct tpilha *);
void exibePilha(struct tpilha *,int);

int main() {
	PILHA pilha;
	inicializaPilha(&pilha);
	int i;
	char aux, string[25];

	printf("\nDigite uma string: ");
	gets(string);

	for(i=0;string[i]!='\0';i++){
		empilha(&pilha,string[i]);
	}

	for(i=0;string[i]!='\0';i++){
		aux = desempilha(&pilha);
		printf("\nComparando %c com %c\n",string[i],aux);

		if(string[i] != aux){
			printf("\nNão é palindromo");
			break;
		}
	}

	if(pilhaVazia(&pilha))
		printf("\nÉ palindromo");
}

// =========== PILHA =========== //

// (1) Inicializar a pilha:
void inicializaPilha(struct tpilha *ps){
	ps->topo = -1;
}

// (2) Testar pilha vazia
int pilhaVazia(struct tpilha *ps){
	if(ps->topo == -1)
		return 1;
	return 0;
}

// (3) Testar pilha cheia
int pilhaCheia(struct tpilha *ps){
	if(ps->topo == TAM-1)
		return 1;
	return 0;
}

// (4) Empilhamento
int empilha(struct tpilha *ps, char valor){
	if(pilhaCheia(ps))
		return 0;
	ps->topo++;
	ps->pilha[ps -> topo] = valor;
	return 1;
}

// (5) Desempilha
char desempilha (struct tpilha *ps){
	char elem;
	if (pilhaVazia(ps)){
		printf("\nPilha Vazia");
		return '\0';
	}
	elem = ps->pilha[ps->topo];
	ps->topo--;
	return elem;
}

// (6) Exibe pilha
void exibePilha(struct tpilha *ps,int aux){
	if(aux==0)
		for(int i=0; i<ps->topo+1; i++){
			printf("%c ", ps->pilha[i]);
		}
	else if(aux>0 && aux<TAM){
		for(int i=0; i<aux; i++){
			printf("%c ", ps->pilha[i]);
		}
	}
	else
		printf("\n~Posição fora da Pilha~\n");
}


