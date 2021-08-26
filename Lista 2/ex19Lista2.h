#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista_LDE{
	int mat;
	char nome[50];
	float media;
	struct lista_LDE *eprox;
	struct lista_LDE *dprox;
};

/*
19) Escreva um programa que insira (usando chamada de função) os dados de n (lido via
teclado) alunos de uma turma numa Lista Duplamente Encadeada cujo tipo que representa
um nó da lista é dado por:
	struct aluno{
		int mat;
		char nome[80];
		float media;
		struct aluno *eprox;
		struct aluno *dprox;
	};
	
Imprima a lista (usando chamada de função). 
Busque uma matricula lida via teclado na lista (usando chamada de função), mostre se achou ou não achou.
Implemente uma função que receba a lista criada e retorne uma nova lista dos alunos aprovados, ou
seja, os alunos com média maior ou igual a 6.0. Imprima a nova lista. 
Crie uma outra função que recebe a lista e retorne uma nova lista dos alunos que estão reprovados, ou
seja, com média menor do que 4.0. Imprima a lista resultante.
*/

// ======================  Funções da Lista ====================== // 
// =============================================================== //

// 1) Função para imprimir a LDE.
int exibe(struct lista_LDE *positInicial){
	if(!positInicial)
		return 0;
	while(positInicial){
		printf("\n --------\n Matricula: %d", positInicial->mat);
		printf("\n Nome: %s", positInicial->nome);
		printf("\n Media: %.2f\n --------\n ", positInicial->media);

		positInicial = positInicial->dprox;
	}
	return 1;
}

// 2) Função para contar os nós da LDE. 
int conta_nos(struct lista_LDE *positInicial){
	if(!positInicial)
		return 0;

	int cont=0;
	while(positInicial){
		cont++;
		positInicial = positInicial->dprox;
	}
	return cont;
}

// 3) Função para inserir um nó no final da LDE.
struct lista_LDE *insere(struct lista_LDE *positInicial, int valor){
	struct lista_LDE *novoNo, *positAtual;

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	novoNo->mat = valor;

	if(!positInicial){
		novoNo->eprox = novoNo->dprox = NULL;
		return novoNo;
	}
	else{
		positAtual = positInicial;

		while(positAtual->dprox)
			positAtual = positAtual->dprox;

		positAtual->dprox = novoNo;
		novoNo->eprox = positAtual;
		novoNo->dprox = NULL;

		return positInicial;
	}
} 
// 3.1) Função para inserir um nó na frente da LDE.
struct lista_LDE *insere_frente(struct lista_LDE *positInicial, int valor){
	struct lista_LDE *novoNo;

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	novoNo->mat = valor;
	novoNo->eprox = NULL;

	if(!positInicial){
		novoNo->dprox = NULL;
		return novoNo;
	}else{
		novoNo->dprox = positInicial;
		positInicial->eprox = novoNo;
		return novoNo;
	}
}

//3.2) Função para inserir um nó antes do k-ésimo nó na LSEC.
void insereNo(struct lista_LDE *noInserido, struct lista_LDE *noDaLista){ 
	if( noDaLista->eprox != NULL )
		noDaLista->eprox->dprox = noInserido;     // A 1 2 B 3 4 | 2 -> B |
	noInserido->eprox = noDaLista->eprox; 	  	  // A 1 2 B 3 4  | 2 <- B |
	noInserido->dprox = noDaLista; 				 // A 1 2 B 3 4   | B -> 3 |
	noDaLista->eprox = noInserido; 				// A 1 2 B 3 4    | 3 <- B |
}
// 
struct lista_LDE *insere_AntesNo(struct lista_LDE *positInicial, int no, int valor){
	struct lista_LDE *positAtual, *novoNo;
	int cont=1;

	if( no < 1 || no > conta_nos(positInicial) ){
		printf("\nValor do nó não existe na lista\n");
		return positInicial;
	}

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	novoNo->mat = valor;

	positAtual = positInicial;
	while(cont != no) {
		positAtual = positAtual->dprox;
		cont++;
	}
	
	insereNo(novoNo, positAtual);
	if(no == 1)
		return novoNo;
	return positInicial;
}
// 3.3) Função para inserir de maneira ordenada
struct lista_LDE *insereOrd(struct lista_LDE *positInicial, char nome[], float media, int valor){
	struct lista_LDE *novoNo, *positAtual;

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));

	// ----
	strcpy(novoNo->nome, nome);
	novoNo->mat = valor;
	novoNo->media = media;
	// ----

	if(!positInicial){
		novoNo->eprox = novoNo->dprox = NULL;
		return novoNo;
	}else{
		positAtual = positInicial;
		while(positAtual->dprox && valor > positAtual->mat)
			positAtual = positAtual->dprox;

		if(!positAtual->dprox && valor > positAtual->mat){ 
			positAtual->dprox = novoNo;
			novoNo->eprox = positAtual;
			novoNo->dprox = NULL;
			return positInicial;
		}
		if(valor < positAtual->mat){
			insereNo(novoNo, positAtual);

			if(positAtual==positInicial)
				return novoNo;
		}

		return positInicial;
	}
}
// 4) Função para remover o k-ésimo nó da LDE.
struct lista_LDE *remove_no(struct lista_LDE *positInicial, int no){
	struct lista_LDE *positAtual, *positAux, *positAux2;
	int cont;
	if( no<1 || no>conta_nos(positInicial) ){
		printf("\nValor do nó não existe na lista\n");
		return positInicial;
	}else if(no == 1){
		if(!positInicial->dprox){
			free(positInicial);
			return NULL;
		}else{
			positAux = positInicial;
			positInicial = positInicial->dprox;
			positInicial->eprox = NULL;

			free(positAux);
			return positInicial;
		}
	}else{
		cont = 1;
		positAtual = positInicial;
		while(cont != no){ 
			positAtual = positAtual->dprox;
			cont++;
		}

		positAux = positAtual->dprox;
		positAux2 = positAtual->eprox;
		positAux2->dprox = positAux;

		if(positAux != NULL)
			positAux->eprox = positAux2;
		free(positAtual);
	}
	return(positInicial);
} 

// 5) Copia lista Deepcopy
struct lista_LDE *copia_lista(struct lista_LDE *lista, char criterio){
	struct lista_LDE *novaLista=NULL,*positAtual;

	if(!lista){
		return NULL;
	}
	positAtual = lista;

	while(positAtual){	
		if(criterio == 'A'){
			if(positAtual->media >= 6.0)
				novaLista = insereOrd(novaLista, positAtual->nome, positAtual->media, positAtual->mat);
		}
		else if(criterio == 'R'){
			if(positAtual->media < 4.0)
				novaLista = insereOrd(novaLista, positAtual->nome, positAtual->media, positAtual->mat);
		}
		positAtual = positAtual->dprox;
	}
	return novaLista;
}

// 6) Concatena
struct lista_LDE *concatena(struct lista_LDE *lista1, struct lista_LDE  *lista2){
	struct lista_LDE *listaAux;
	if(!lista1)
		return lista2;
	listaAux = lista1;
	while(listaAux->dprox)
		listaAux = listaAux->dprox;

	listaAux->dprox = lista2;
	return lista1;
}

// 7) Busca em uma lista Ordenada
int busca_seqOrd(struct lista_LDE *lista, int tamanho, int alvo) {
	int i;
	for(i=0; i < tamanho && alvo > lista->mat; i++)
		lista = lista->dprox;

	if((i==tamanho) || (alvo != lista->mat))
		return 0;
	return 1;
}
// =============================================================== // 
/*
(X) - Imprima a lista (usando chamada de função). 
(X) - Busque uma matricula lida via teclado na lista (usando chamada de função), mostre se achou ou não achou.
(X) - Implemente uma função que receba a lista criada e retorne uma nova lista dos alunos aprovados, ou seja, os alunos com média maior ou igual a 6.0. Imprima a nova lista. 
(X) - Crie uma outra função que recebe a lista e retorne uma nova lista dos alunos que estão reprovados, ou seja, com média menor do que 4.0. Imprima a lista resultante.
*/
// =============================================================== // 

int main(){
	struct lista_LDE *listaAlunos = NULL;
	struct lista_LDE *listaAprovados = NULL;
	struct lista_LDE *listaReprovados = NULL;
	int n=5,k;
	
	/*
		Ao contrario das outras questões a 10 - 18 - 19 não citam "menu" no enunciado então imagino que a ideia era fazer ao longo da main mesmo.
	*/

	listaAlunos = insereOrd(listaAlunos, "Axel", 8.9, 1);
	listaAlunos = insereOrd(listaAlunos, "Dre", 9.2, 2);
	listaAlunos = insereOrd(listaAlunos, "Jordy", 2.6, 3);
	listaAlunos = insereOrd(listaAlunos, "Josh", 4.4, 4);

	//(X) - Imprima a listaAlunos (usando chamada de função). 
	printf("\nLista de alunos");
	exibe(listaAlunos);

	if(busca_seqOrd(listaAlunos, conta_nos(listaAlunos), 3))
		printf("\nAchou");
	else
		printf("\nNão achou");

	// (X) - Implemente uma função que receba a lista criada e retorne uma nova lista dos alunos aprovados, ou seja, os alunos com média maior ou igual a 6.0. Imprima a nova lista. 
	listaAprovados = copia_lista(listaAlunos,'A');
	printf("\n\nAlunos Aprovados\n");
	exibe(listaAprovados);

	// (X) - Crie uma outra função que recebe a lista e retorne uma nova lista dos alunos que estão reprovados, ou seja, com média menor do que 4.0. Imprima a lista resultante.
	listaReprovados = copia_lista(listaAlunos,'R');
	printf("\n\nAlunos Reprovados\n");
	exibe(listaReprovados);

	free(listaAlunos);
	free(listaAprovados);
	free(listaReprovados);
}