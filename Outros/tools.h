#include <time.h>
#include <unistd.h> // Precisa importar para usar o STDOUT_FILENO


int imput(n){
	return 0 + ( rand() % n );
}

void limparTela(){
	printf("\n");
    const char *CODIGO = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CODIGO, 11);
}