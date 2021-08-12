
void Ihanoi(struct tpilha *t1,struct tpilha *t2,struct tpilha *t3);

void phase1(struct tpilha *t1,struct tpilha *t2,struct tpilha *t3);
void phase2();

void ex2(){
	pilha torre1,torre2,torre3;
	int aux,max = 4;
	inicializaPilha(&torre1);
	inicializaPilha(&torre2);
	inicializaPilha(&torre3);

	/*
	for(int i=0; i<3; i++){
		empilha(&p1,imput(100));
		empilha(&p2,imput(100));
	}
	*/

	for(int i=0; i<max; i++){
		empilha(&torre1,max-i);
	}

	Ihanoi(&torre1,&torre2,&torre3);

/*
	Ihanoi(&torre1,&torre2,&torre3);
	aux = desempilha(&torre1);
	empilha(&torre2,aux);

	Ihanoi(&torre1,&torre2,&torre3);
	aux = desempilha(&torre1);
	empilha(&torre3,aux);

	Ihanoi(&torre1,&torre2,&torre3);
	aux = desempilha(&torre2);
	empilha(&torre3,aux);
*/

	printf("\n========= INICIO =========\n");

	phase1(&torre1,&torre2,&torre3);

	printf("\n_____Fim Phase 1_______\n");

	// Se torre 1 não estiver vazia //
	// ======================== //

	aux = desempilha(&torre3);
	empilha(&torre2,aux);
	Ihanoi(&torre1,&torre2,&torre3);
		
	aux = desempilha(&torre3);
	empilha(&torre1,aux);
	Ihanoi(&torre1,&torre2,&torre3);
			
	aux = desempilha(&torre2);
	empilha(&torre1,aux);
	Ihanoi(&torre1,&torre2,&torre3);
	
	aux = desempilha(&torre2);
	empilha(&torre3,aux);
	Ihanoi(&torre1,&torre2,&torre3);
	/*				
	aux = desempilha(&torre2);
	empilha(&torre3,aux);
	Ihanoi(&torre1,&torre2,&torre3);

	aux = desempilha(&torre3);
	empilha(&torre1,aux);
	Ihanoi(&torre1,&torre2,&torre3);
	*/
	/*	
	printf("\n_____Fim Phase 2_______\n");
	
	phase1(&torre1,&torre2,&torre3);
	*/
	//printf("\n_____Fim Phase 1_______\n");
	



}
void phase1(struct tpilha *t1,struct tpilha *t2,struct tpilha *t3){
	int aux;

	aux = desempilha(t1);
	empilha(t2,aux);
	Ihanoi(t1,t2,t3);

	aux = desempilha(t1);
	empilha(t3,aux);
	Ihanoi(t1,t2,t3);

	aux = desempilha(t2);
	empilha(t3,aux);
	Ihanoi(t1,t2,t3);

	aux = desempilha(t1);
	empilha(t2,aux);
	Ihanoi(t1,t2,t3);

}

void Ihanoi(struct tpilha *t1,struct tpilha *t2,struct tpilha *t3){
	
	printf("\n____________\n");
	exibePilha(t1,0);
	printf("\n------------\n");

	printf("\n____________\n");
	exibePilha(t2,0);
	printf("\n------------\n");

	printf("\n____________\n");
	exibePilha(t3,0);
	printf("\n------------\n");

	printf("\nxxxxxxxxxxxxxxxx\n");

}