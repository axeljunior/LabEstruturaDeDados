#include <stdio.h>
#include <stdlib.h>

/*
11) Desenvolva um programa leia duas filas f1 e f2 circulares com nó bobo com 20 números reais cada uma. 
Imprima as filas. 
Em seguida, chame uma função para testar se a fila f1 tem mais elementos que a fila f2.
*/

#define TAM 20
// =========== FILA Cirular (No bobo)=========== //
typedef struct tfila_circB {
	int R, F;
	float fila[TAM];
}FILAcb;

void inicializaFila(struct tfila_circB *);
int fila_vazia(struct tfila_circB *);
int insereFila(struct tfila_circB *, float);
float removeFila(struct tfila_circB *);
void exibeFila(struct tfila_circB *);

void verificaTamanho(struct tfila_circB *,struct tfila_circB *);

// =========== FILA Cirular (No bobo)=========== //

int main(){
	FILAcb f1;
	inicializaFila(&f1);
	FILAcb f2;
	inicializaFila(&f2);
	int i;
	float aux;

	for(i=0;i<5;i++){
		printf("\nInforme um valor real: ");
		scanf("%f",&aux);
		insereFila(&f1, (float) aux);

		//insereFila(&f1,(float) i/100);  TESTE
	}	
	for(i=0;i<5;i++){
		printf("\nInforme um valor real: ");
		scanf("%f",&aux);
		insereFila(&f2, (float) aux);

		//insereFila(&f2,(float) (20.0+i)/100); TESTE
	}
	
	printf("\n\n");
	exibeFila(&f1);
	printf("\n\n");
	exibeFila(&f2);

	verificaTamanho(&f1,&f2);
}

void verificaTamanho(struct tfila_circB *pf1,struct tfila_circB *pf2){
	struct tfila_circB filas[2];

	filas[0]=*pf1;
	filas[1]=*pf2;

	int aux,cont=0,n=0;
	while(n<2){
		int i=filas[n].F+1;

		if(filas[n].F+1 < filas[n].R){
			for(i=filas[n].F+1;i<=filas[n].R;i++)
				cont++;
		}else{
			while(i!=filas[n].R+1){
				if(i == TAM){
					i=0;
				}
				cont++;
				i++;
			}
		}
		if(n==0){
			aux = cont;
			cont = 0;
		}
		n++;
	}
	printf("\n\nPrimeira fila %d -- Segunda fila %d\n", aux, cont);
	if(aux==cont){
		printf("\nAs filas tem a mesma quantidade de elementos\n");
	}else if(aux>cont){
		printf("\nA primeira fila tem mais elementos\n");
	}else{
		printf("\nA segunda fila tem mais elementos\n");
	}

}

// =========== FILA Cirular (No bobo)=========== //

// (1) Inicialização da fila
void inicializaFila(struct tfila_circB *pf) {
	pf->R=0;
	pf->F=0;
}
// (2) Testar fila vazia
int fila_vazia(struct tfila_circB *pf) {
	if(pf -> F == pf->R)
		return 1;
	return 0;
}
// (3) Testar fila cheia
int fila_cheia(struct tfila_circB *pf){
	if((pf -> R+1)%TAM == pf->F){
		return 1;
	}
	return 0;
}
// (4) Inserção
int insereFila(struct tfila_circB *pf, float valor) {
	if(fila_cheia(pf))
		return 0;
	pf->R=(pf->R+1)%TAM;
	pf->fila[pf ->R] = valor;
	return 1;
}
// (5) Remoção
float removeFila(struct tfila_circB *pf){
	float elem;
	if(fila_vazia(pf))
		return 0;
	pf->F = (pf->F+1)%TAM;
	elem = pf->fila[pf->F];
	return elem;
}
// (6) Exibição

void exibeFila(struct tfila_circB *pf){
	int i=pf->F+1;
	if(pf->F+1 < pf->R){
		for(i=pf->F+1;i<=pf->R;i++)
			printf("%.2f ", pf->fila[i]);
	}else{
		while(i!=pf->R+1){
			if(i == TAM){
				i=0;
			}
			printf("%.2f ", pf->fila[i]);
			i++;
		}
	}
}
// =========== PILHA Cirular (No bobo)=========== //