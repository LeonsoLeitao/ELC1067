#include <stdio.h>
#include <string.h>

//Leonso R. Leitão

void le_alunos(int* matriculas, char[][50] nomes, int* n){
    int mat;
    char c;
    char nome[50];
    int i;
    int linha;
    FILE*f = fopen("alunos.txt", "R");
    linha = 0;
    while(feof(f) == 0){
        if(fscanf(f, "%d", &mat) == 0)
        break;
        i = 0;
        c = fgetc(f);
        while(c != '\n'){
            nome[i] = c;
            c = fgetc(f);
            i++;
        }
        nome[i] = '\0';
        matriculas[linha]=mat;
        strcpy(nomes[linha],nome);
        linha++;
    }
    n = linha;
    fclose(f);
}

int main(int argc, char** argv){
    char* nome;
    if(argc > 1){
        nome = argv[1];
        }
        printf("%s\n", nome);
        int matriculas[50];
        char nomes[50][50];
        int n;
        le_alunos(matriculas, nomes, &n);


}
