/*
26) Faça uma função recursiva que retorne a quantidade de nós de uma árvore 
binária de busca que possuem apenas um filho.
*/

int nosComUmFilho(struct tree *raiz){
	if(!raiz)
		return 0;
	if(raiz->esq || raiz->dir){
		if(!raiz->esq || !raiz->dir){
			return 1 + nosComUmFilho(raiz->esq) + nosComUmFilho(raiz->dir);
		}
	}
	return nosComUmFilho(raiz->esq) + nosComUmFilho(raiz->dir);
}