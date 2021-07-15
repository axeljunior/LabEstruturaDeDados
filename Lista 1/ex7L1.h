#include <stdio.h>
#include <stdlib.h>

/*
7) Escreva um programa que leia 30 números inteiros e insira-os numa fila f1. Imprima a fila f1.
Logo após, inverta o conteúdo de f1 nela mesma utilizando uma pilha auxiliar. Imprima a fila f1 invertida.
*/

#define TAM 100
// ========== PILHA ========== //

typedef struct tpilha {
	int topo;
	char pilha[TAM];
}PILHA;

void inicializaPilha(struct tpilha *);
int pilhaVazia(struct tpilha *);
int pilhaCheia(struct tpilha *);
int empilha(struct tpilha *, int);
int desempilha (struct tpilha *);
void exibePilha(struct tpilha *,int);
// =========== PILHA ========== //
// =========== FILA =========== //
typedef struct tfilaS {
	int F, R;
	int fila[TAM];
}FILA;

void inicializaFila(struct tfilaS *);
int fila_vazia(struct tfilaS *);
int fila_cheia (struct tfilaS *);
int insere_fila(struct tfilaS *, int);
int remove_fila(struct tfilaS *pf);
void exibeFila(struct tfilaS *,int);
// =========== FILA =========== //

int main() {
	PILHA pilha;
	FILA f1;
	
	inicializaPilha(&pilha);
	inicializaFila(&f1);

	int i,aux;

	for(i=0;i<30;i++){
		printf("\nInforme um valor para a Fila (%d/30): ",i+1);
		scanf("%d",&aux);
		insere_fila(&f1, aux);
		//insere_fila(&f1, i); TESTE
	}
	
	printf("Fila\n");
	exibeFila(&f1, 0);

	for(i=0;i<30;i++){
		aux = remove_fila(&f1);
		empilha(&pilha, aux);
	}

	inicializaFila(&f1);
	for(i=0;i<30;i++){
		aux = desempilha(&pilha);
		insere_fila(&f1, aux);
	}

	printf("\n\n");
	printf("Fila Invertida\n");
	exibeFila(&f1, 0);
}

// =========== FILA =========== //
//1) Inicialização
void inicializaFila(struct tfilaS *pf){
	pf->R = -1;
	pf->F = 0;
}

//2) Verificar Fila Vazia
int fila_vazia(struct tfilaS *pf){
	if(pf->F > pf->R)
		return 1;
	return 0;
}

//3) Verificar Fila Cheia
int fila_cheia (struct tfilaS *pf){
	if(pf->R == TAM-1)
		return 1;
	return 0;
}

//4) Inserção
int insere_fila(struct tfilaS *pf, int valor){
	if(fila_cheia(pf))
		return 0;
	pf->R++;
	pf->fila[pf->R] = valor;
	return 1;
}

//5) Remoção
int remove_fila(struct tfilaS *pf){
	int elem;
	if(fila_vazia(pf))
		return -1;
	elem = pf->fila[ pf->F ];
	pf->F++;
	return elem;
}

// (6) Exibe fila
void exibeFila(struct tfilaS *pf,int aux){
	int i;
	if(aux==0)
		for(i=0; i<pf->R+1; i++){
			printf("%d ", pf->fila[i]);
		}
	else if(aux>0 && aux<TAM){
		for(int i=0; i<aux; i++){
			printf("%d ", pf->fila[i]);
		}
	}
	else
		printf("\n~Posição fora da Filha~\n");
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