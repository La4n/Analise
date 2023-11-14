#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char Produto[50], linha[1000];
    int Qtd, Indent, t, encerrar = 0;
    long posicaoInicial = -1;

    arquivo = fopen("Estoque", "r+"); 

    // Verifica se o arquivo foi aberto com sucesso
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (encerrar != 1) {
        for (t = 0; t < 1; t++) {
            printf("Produto: ");
            scanf("%s", Produto);

            printf("Quantidade: ");
            scanf("%i", &Qtd);

            printf("Indentificador: ");
            scanf("%i", &Indent);
        }

        fseek(arquivo, 0, SEEK_SET);  // Posiciona o ponteiro no início do arquivo

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            if (strstr(linha, Produto) != NULL) {
                posicaoInicial = ftell(arquivo) - strlen(linha);
                break;
            }
        }

        if (posicaoInicial != -1) {
            printf("\n\nProduto encontrado. Atualizando informacoes...\n");

            // Atualiza a quantidade e o identificador
            fseek(arquivo, posicaoInicial, SEEK_SET);
            fprintf(arquivo, "roduto: %s | Quantidade: %i | Indentificador: %i\n", Produto, Qtd, Indent);

            printf("Informacoes atualizadas com sucesso.\n\n");
        } else {
            // Move o ponteiro para o final do arquivo
            fseek(arquivo, 0, SEEK_END);
            // Adiciona uma nova linha com as informações do produto
            fprintf(arquivo, "Produto: %s | Quantidade: %i | Indentificador: %i\n", Produto, Qtd, Indent);
            printf("Produto adicionado com sucesso.\n");
        }

        printf("Para encerrar, digite '1': ");
        scanf("%i", &encerrar);
    }

    fclose(arquivo);

    printf("Operação concluída com sucesso.\n");

    return 0;
}

