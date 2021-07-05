#include <stdio.h>
#include <stdlib.h>

#include <time.h>
//#include <stdbool.h>
 
struct FILA{
	int a,b;
	int posicao;
};

typedef struct FILA fila;

fila GameT[5];

void init(){
	srand(time(NULL));
	for(int i=0;i<5;i++){
		GameT[i].posicao = i;
		GameT[i].a = 1 + ( rand() % 10 );
		GameT[i].b = 1 + ( rand() % 10 );
	}
}
void ExibeTela(){
	//system("cls");
	for(int i=0;i<5;i++)
		printf("Teste: %d \n%d + %d = ?\n",GameT[i].posicao+1,GameT[i].a,GameT[i].b);

}
int main() {
	init();
	ExibeTela();
}

/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
}*FILA;
//typedef struct Node node;

int main(void)
{
 *FILA = (Node *) malloc(sizeof(Node));
 if(!FILA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 	printf("Memoria Alocada");
 }
}
*/