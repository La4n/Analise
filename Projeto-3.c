#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TAMANHO_MAX_LINHA 1000

int contar_passos(FILE *arquivo) {
    char linha[TAMANHO_MAX_LINHA];
    int passos = 0;
    int dentro_de_comentario = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    	int i;
        for (i = 0; linha[i] != '\0'; i++) {
          
            if (linha[i] == '/' && linha[i + 1] == '/') {
                break;
            } else if (linha[i] == '/' && linha[i + 1] == '*') {
                dentro_de_comentario = 1; 
                i++;
            } else if (linha[i] == '*' && linha[i + 1] == '/') {
                dentro_de_comentario = 0; 
                i++;
            }

         
            if (dentro_de_comentario) {
                continue;
            }

          
            if (linha[i] == '{' || linha[i] == '}') {
                passos++;
            }

           
            if (isalpha(linha[i])) {
                char palavra[TAMANHO_MAX_LINHA];
                int j = 0;
                while (isalpha(linha[i]) || linha[i] == '_') {
                    palavra[j++] = linha[i++];
                }
                palavra[j] = '\0';
                if (strcmp(palavra, "for") == 0 || strcmp(palavra, "while") == 0 || strcmp(palavra, "if") == 0 || strcmp(palavra, "else") == 0 || strcmp(palavra, "switch") == 0 || strcmp(palavra, "case") == 0 || strcmp(palavra, "do") == 0 || strcmp(palavra, "return") == 0) {
                    passos++;
                }
            }
        }
    }

    return passos;
}

int main() {
    FILE *arquivo;
    clock_t inicio, fim;
    double tempo_execucao;

  
    arquivo = fopen("Untitled.c", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    
    inicio = clock();
    int passos = contar_passos(arquivo);
    fim = clock();

    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Quantidade total de passos: %i\n", passos);
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    
    fclose(arquivo);

    return 0;
}

