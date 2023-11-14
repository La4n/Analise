#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char Produto[50], linha[100];
     int totalLinhas = 0; 
    int somaComprimentos = 0;
	double h;
    
    printf("Digite o produto a ser procurado: ");
    scanf("%s", Produto);

    arquivo = fopen("Estoque", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int encontrado = 0; 

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        totalLinhas++; 
        somaComprimentos += strlen(linha);  
        
        if (strstr(linha, Produto) != NULL) {
            printf("Produto encontrado!\n\n");
            printf("\t%s", linha);
            encontrado = 1; 
            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }

    fclose(arquivo);
    
    if (totalLinhas > 0) {
        double comprimentoMedio = (double)somaComprimentos / totalLinhas;
        printf("\nComprimento medio das linhas: %.2f\n", comprimentoMedio);
        
		printf("Complexidade estimada: O(%i * %f) = (", totalLinhas,comprimentoMedio);
   		h =  (totalLinhas * comprimentoMedio) / 6;
			printf("%.2f) \n",h);

    } else {
        printf("Nenhum dado no arquivo.\n");
    }
   /*
   No pior dos casos de busca, o algoritmo ira percorre todo o arquivo
   com isso o 'totalLinhas ' ira aumentar, consequentemente tambem
   aumenta a complexidade do algoritmo, ou seja o pior dos casos depende
   do 'totalLinhas', quanto maior for, mais complexo sera o algoritmo.
   'h' seria igual a complexidade do tempo.c
   
   */
    return 0;
}

