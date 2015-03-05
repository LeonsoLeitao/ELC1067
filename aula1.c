#include <stdio.h>
#include <stdlib.h>

FILE*f;

void main(){
	int matricula;
	char nome[100];
	printf("Digite Matrícula: ");
	scanf("%d", &matricula);
	printf("Digite Nome: ");
	scanf("%s", &nome);
	f = fopen("saida.txt", "w");
	fprint(f, "%d%s\n", matricula, nome);
	fclose(f);
}
