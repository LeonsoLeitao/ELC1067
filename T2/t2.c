#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Leonso R. Leitão

void le_alunos(int* matriculas, char** nomes, int *n){
    int mat, i, linha;
    char c;
    char* nome;
    nome = (char*)malloc(50*sizeof(char));
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
        nomes[linha] = ((char*)malloc((strlen(nome)+1)*sizeof(char)));
        strcpy(nomes[linha], nome);
        linha++;
    }
    *n = linha;
    fclose(f);
}

void leitor_nota(float* media, int* matritest){
    int i = 0, mat;
    float nota1, nota2;
    FILE*f = fopen("notas.txt", "r");
    while(feof(f) == 0){
        if(fscanf(f, "%d %f %f\n", &mat, &nota1, &nota2) <= 0)
            break;
        matritest[i] = mat;
        media[i] = (nota1 + nota2)/2;
        i++;
    }
    fclose(f);
}

void procurar_alunos(char* nome, char** nomes, int* matriculas, int* matritest, int *n, float* media){
    int i, j;
    for(i = 0; i < *n; i++){
        j = 0;
        if(strstr(nomes[i], nome) != NULL){
            while(matriculas[i] != matritest[j] && matritest[j]>0)
                j++;
            printf("%.2f %s\n", media[j], nomes[i]);
        }
    }
}

int main(int argc, char** argv){
    char *nome;
    float *med;
    int i, n;
    med = (float*)malloc(50*sizeof(float));
    nome = (char*)malloc(50*sizeof(char));
    if(argc > 1){
        nome = argv[1];
        }
    printf("%s\n", nome);
    int *matriculas, *matritest;
    matriculas = (int*)malloc(50*sizeof(int));
    matritest = (int*)malloc(50*sizeof(int));
    char** nomes;
    nomes = (char**)malloc(50*sizeof(char*));
    le_alunos(matriculas, nomes, &n);
    leitor_nota(med, matritest);
    procurar_alunos(nome, nomes, matriculas, matritest, &n, med);
    free(med);
    free(matriculas);
    free(matritest);
    for(i = 0; i < n; i++){
        free(nomes[i]);
    }
     free(nomes);

    return (0);
}
