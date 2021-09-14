#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
/*
20) Escreva uma função recursiva para contar o número de caracteres maiúsculos que a string possui.
*/

int upperCount(char s[],int i, int count){
	if(s[i] >= 'A' && 'Z' >= s[i]){
		count++;
	}
    if(s[i] != '\0')
		return upperCount(s,i+1,count);
	return count;
}

int main(){
	char string[MAX] = "TeStAnDo";
	printf("\nString: %s\nQuantidade de maiusculas: %d", string, upperCount(string,0,0));
}