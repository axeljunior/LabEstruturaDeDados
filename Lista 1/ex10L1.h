#include <stdio.h>
#include <stdlib.h>

/*
10) Escreva um programa que leia 50 valores inteiros e insira-os numa pilha. Em seguida, leia um número 50 valores inteiros e insira-os numa fila circular com contador. 
Logo após, forneça o maior, o menor e a média aritmética dos elementos na pilha e na fila, respectivamente.
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

// =========== FILA Cirular (Contador)=========== //
typedef struct tfila_circC {
	int ini;
	int fim;
	int cont;
	int fila[TAM];
}FILAcc;

void inicializaFila(struct tfila_circC *pf);
int fila_vazia(struct tfila_circC *pf);
int fila_cheia(struct tfila_circC *pf);
int insere_fila(struct tfila_circC *pf, int valor);
int remove_fila(struct tfila_circC *pf);
void exibeFila(struct tfila_circC *pf,int aux);
// =========== FILA Cirular (Contador)=========== //

int main(){
	srand(time(NULL));
	PILHA pilha;
	FILAcc f1;
	int teste=5;
	inicializaPilha(&pilha);
	inicializaFila(&f1);

	int i,aux;

	for(i=0;i<teste;i++){
		printf("\nInforme um valor para a Pilha (%d/50): ",i+1);
		scanf("%d",&aux);
		empilha(&pilha, aux);
		//insere_fila(&f1, i); TESTE
	}

	for(i=0;i<teste;i++){
		printf("\nInforme um valor para a Fila (%d/50): ",i+1);
		scanf("%d",&aux);
		insere_fila(&f1, aux);
		//insere_fila(&f1, i); TESTE
	}

	exibePilha(&pilha, 0);
	printf("\n\n");
	exibeFila(&f1, 0);
	printf("\n\n");

	int maior=0,menor=50;
	float media=0.0;
	for(i=0;i<teste;i++){
		aux = desempilha(&pilha);
		if(aux > maior)
			maior = aux;
		if(aux < menor)
			menor = aux;
		media = media + aux;
	}
	printf("\nMaior Elemento na Pilha: %d\nMenor Elemento na Pilha %d\nMedia dos elementos na Pilha: %f",maior,menor,media/50);

	printf("\n\n");

	media=.0,maior=0,menor=50;
	for(i=0;i<teste;i++){
		aux = remove_fila(&f1);
		if(aux > maior)
			maior = aux;
		else if(aux < menor)
			menor = aux;
		media = media + aux;
	}
	printf("\nMaior Elemento na Fila: %d\nMenor Elemento na Fila %d\nMedia dos elementos na Fila: %f",maior,menor,media/50);
}

// =========== FILA Cirular (Contador)=========== //

// (1) Inicialização
void inicializaFila(struct tfila_circC *pf) {
	pf->ini=0;
	pf->fim=-1;
	pf->cont=0;
}
// (2) Testar fila vazia
int fila_vazia(struct tfila_circC *pf){
	if(pf -> cont == 0)
		return 1;
	return 0;
}
// (3) Testar fila cheia
int fila_cheia(struct tfila_circC *pf){
	if(pf->cont == TAM)
		return 1;
	return 0;
}
// (4) Inserção
int insere_fila(struct tfila_circC *pf, int valor){
	if(fila_cheia(pf))
		return 0;
	pf -> cont++;
	pf -> fim = (pf -> fim == TAM-1) ? 0 : pf ->fim+1;
	pf -> fila[pf -> fim] = valor;
	return 1;
}
// (5) Remoção
int remove_fila(struct tfila_circC *pf){
	int elem;
	if(fila_vazia(pf))
		return -1;
	pf->cont--;
	elem=pf->fila[pf->ini];
	pf -> ini = (pf ->ini==TAM-1) ? 0 : pf->ini+1;
	return elem;
}
// (6) Exibição

void exibeFila(struct tfila_circC *pf,int aux){
	if(aux==0)
		for(int i=pf->ini; i<pf->fim+1; i++){

			printf("%d ", pf->fila[i]);
		}
	else if(aux>0 && aux<TAM){
		for(int i=0; i<aux; i++){
			printf("%d ", pf->fila[i]);
		}
	}
	else
		printf("\n~Posição fora da Pilha~\n");
}
// =========== FILA Cirular (Contador)=========== //

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
int empilha(struct tpilha *ps, int valor){
	if(pilhaCheia(ps))
		return 0;
	ps->topo++;
	ps->pilha[ps -> topo] = valor;
	return 1;
}

// (5) Desempilha
int desempilha (struct tpilha *ps){
	int elem;
	if (pilhaVazia(ps)){
		printf("\nPilha Vazia");
		return -1;
	}
	elem = ps->pilha[ps->topo];
	ps->topo--;
	return elem;
}

// (6) Exibe pilha
void exibePilha(struct tpilha *ps,int aux){
	if(aux==0)
		for(int i=0; i<ps->topo+1; i++){

			printf("%d ", ps->pilha[i]);
		}
	else if(aux>0 && aux<TAM){
		for(int i=0; i<aux; i++){
			printf("%d ", ps->pilha[i]);
		}
	}
	else
		printf("\n~Posição fora da Pilha~\n");
}
// =========== PILHA =========== //