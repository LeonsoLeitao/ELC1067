#include <stdio.h>
#include <string.h>

//Leonso R. Leitão

void le_alunos(int* matriculas, char** nomes, int* n){
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

void leitor_nota(float* media){
    int i = 0, mat;
    float nota1, nota2;
    FILE*f = fopen("notas.txt", "r");
    while(feof(f) == 0){
        if(fscanf(f, "%d %f %f\n", &mat, &nota1, &nota2) <= 0)
            break;
        media[i] = (nota1 + nota2)/2;
        i++;
    }
    fclose(f);
}

void procurar_alunos(char* nome, char** nomes, int* n, float* media){
    int i;
    for(i = 0; i < *n; i++){
        if(strstr(nomes[i], nome) != NULL){
            printf("%.2f %s\n", media[i], nomes[i]);
        }
    }
}

int main(int argc, char** argv){
    char* nome;
    char* busca = nome;
    float* med;
    med = (float*)malloc(50*sizeof(float));
    nome = (char*)malloc(50*sizeof(char));
    if(argc > 1){
        strcpy(busca, argv[1]);
        }
    printf("%s\n", nome);
    int* matriculas;
    matriculas = (int*)malloc(50*sizeof(int));
    char nomes[50][50];
    int* n;
    n = (int*)malloc(50*sizeof(int));
    le_alunos(matriculas, nomes, n);
    leitor_nota(med);
    procurar_alunos(nome, nomes, n, med);
    free(nome);
    free(med);
    free(matriculas);
    free(n);
    free(nomes);

    return (0);
}
