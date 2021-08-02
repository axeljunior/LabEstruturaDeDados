void Resumo(){

  int X;
  int *pX; // Declarando ponteiro

  pX = &X; // Ponteiro pX aponta para o endereço da variavel x

  printf("\n\n ---- Ponteiros ---- \n\n");

  printf("\n\n Ponteiros apontam no endereço de memoria de variavei de mesmo tipo, ou seja, um ponteiro do tipo int vai apontar no endereço de memoria de uma variavel do tipo int");

  printf("\n\n '&' Indica endereço de memoria da variavel, ou seja, &X é o endereço onde esta armazenado o valor da variavel 'X'\n\n '*' indica o valor armazenado no endereço para onde um ponteiro aponta, ou seja, se pX aponta na variavel X e se x = 10 então *pX = 10");

  printf("\n\n Valor da Variavel x: %d\n Endereço da Variavel: %p\n Endereço para onde o Ponteiro aponta: %p\n Valor no Endereço do Ponteiro: %d", X, &X, pX, *pX);

  printf("\n\n Note que, como previsto, o endereço de 'X' %p = 'pX' %p",&X,pX);

  printf("\n\n Porem perceba que o Endereço de memoria de um ponteiro é diferente do endereço para onde ele aponta, ou seja, '&pX' %p ≠ 'pX' %p",&pX,pX);

  printf("\n\n\n ---- Ponteiros e Vetores ----");

  int VET[5] = {1,2,3,4,5};
  int *pVET = VET;

  printf("\n\nPara os exemplos considere um vetor \n\nVET[5] = {1,2,3,4,5}\n\nE um ponteiro\n\n*pVET = VET\n\n");

  printf("\n\n Em relação a vetores, o 'nome' de um vetor nada mais é que um ponteiro que aponta para o endereço de memoria do primeiro elemento do vetor. 'VET[0]'\n");
  
  printf("\n Ou seja: 'VET''%p', 'pVET''%p' são ambos ponteiros que apontam para o mesmo endereço de memoria 'VET[0]''%p'",VET,pVET,&VET[0]);

  printf("\n\n Alem disso nesse caso particular o endereço do ponteiro 'VET''%p' é igual ao endereço que ele aponta 'VET[0]'%p'",&VET,&VET[0]);

  //printf("\n\n %p - %p - %p - %p",VET,pVET,&VET,&VET[0]);

  printf("\n\nSe tratando de acessar a informação no vetor a forma usual 'VET[n]' funciona também para 'pVET[n]'\n\n");

  printf("\nVET[n]\n");
  for(int i = 0;i<5;++i){
    
    printf("%d ",VET[i]);
  }
  printf("\npVET[n]\n");  
  for(int i = 0;i<5;++i){
    
    printf("%d ",pVET[i]);
  }

 printf("\n\nUma outra forma seria '*(VET+n)' ou '*(pVET+i)'\n\n");

  printf("\n*(VET+n)\n");
  for(int i = 0;i<5;++i){
    
    printf("%d ",*(VET+i));
  }
  printf("\n*(pVET+i)\n");  
  for(int i = 0;i<5;++i){
    
    printf("%d ",*(pVET+i));
  }

  printf("\n\nClaro que, como o esperado, o valor de 'VET[0]''%d' sera igual ao de '*pVET''%d' e '*VET''%d'",VET[0], *pVET, *VET);

  printf("\n\n ---- FIM ---- \n\n");
}