#include <stdio.h>
#include <string.h>

//Leonso R. Leit�o

void le_alunos(int* matriculas, char nomes[][50], int* n){
    int mat;
    char c;
    char nome[50];
    int i;
    int linha;
    FILE*f = fopen("alunos.txt", "r");
    linha = 0;
    while(feof(f) == 0){
        if(fscanf(f, "%d", &mat) <= 0)
            break;
        i = 0;
        c = fgetc(f);
        while(c != '\n' && feof(f) == 0){
            nome[i] = c;
            c = fgetc(f);
            i++;
        }
        nome[i] = '\0';
        matriculas[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
    }
    *n = linha;
    fclose(f);
}

void leitor_nota(float* media){
    int i = 0, mat;
    float n1, n2;
    FILE*f = fopen("notas.txt", "r");
    while(feof(f) == 0){
        if(fscanf(f, "%d %f %f\n", &mat, &n1, &n2) <= 0)
            break;
        media[i] = (n1+n2)/2;
        i++;
    }
    fclose(f);
}

void procura(char* nome, char nomes[][50], int n, float* media){
    int i;
    for(i = 0; i<n; i++){
        if(strstr(nomes[i], nome) != NULL){
            printf("%.2f %s\n", media, nomes);
        }
    }
}

int main(int argc, char** argv){
    char* nome;
    float med[50];
    if(argc > 1){
        strcpy(nome, argv[1]);
        }
    printf("%s\n", nome);
    int matriculas[50];
    char nomes[50][50];
    int n;
    le_alunos(matriculas, nomes, &n);
    leitor_nota(med);
    procura(nome, nomes, n, med);

    return (0);
}
