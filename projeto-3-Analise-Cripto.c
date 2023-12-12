#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALFABETO 26



char *Cifrado(char *crip,int chv){
	
	FILE *arquivo;
	char caractere;
	int i = 0;
	arquivo = fopen("Cifra.txt","r");
	
	if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo.\n");
        return;
    }
			
  while ((caractere = fgetc(arquivo)) != EOF) {
        if ('A' <= caractere && caractere <= 'Z') {
            crip[i] = 'A' + (caractere - 'A' + chv) % ALFABETO;
        } else if ('a' <= caractere && caractere <= 'z') {
            crip[i] = 'a' + (caractere - 'a' + chv) % ALFABETO;
        } else {
            crip[i] = caractere;
        }
        i++;
    }

    fclose(arquivo);
    crip[i] = '\0';

	return crip;
}

char *Descriptografar(char *descripto, int chv) {
    FILE *arquivo;
    char caractere;
    int i = 0;

    arquivo = fopen("Cifra.txt", "r");

    if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo.\n");
        return NULL;
    }

    while ((caractere = fgetc(arquivo)) != EOF) {
        if ('A' <= caractere && caractere <= 'Z') {
            descripto[i] = 'A' + (caractere - 'A' - chv + ALFABETO) % ALFABETO;
        } else if ('a' <= caractere && caractere <= 'z') {
            descripto[i] = 'a' + (caractere - 'a' - chv + ALFABETO) % ALFABETO;
        } else {
            descripto[i] = caractere;
        }
        i++;
    }

    fclose(arquivo);
    descripto[i] = '\0';

    return descripto;
}

char *cifraSub(char txt[],int chave){
		FILE *arquivo;
		char *cifra;
	
		
		 int tamanho = strlen(txt);
		 
		char *criptografada = (char*)malloc(tamanho+1);
		
		chave = chave % ALFABETO;
		
		arquivo = fopen("Cifra.txt","w");
		
		if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo.\n");
        return;
    }
    
    fprintf(arquivo,"%s",txt);
    fclose(arquivo);
		 
		cifra = Cifrado(criptografada,chave);
		
		return cifra;
}

char *decifraSub(char *txt,int chave) {
 	FILE *arquivo;
		char *cifra;
	
		
		 int tamanho = strlen(txt);
		 
		char *criptografada = (char*)malloc(tamanho+1); 
		
		chave = chave % ALFABETO;
		
		arquivo = fopen("Cifra.txt","w");
		
		if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo.\n");
        return;
    }
    
    fprintf(arquivo,"%s",txt);
    fclose(arquivo);
		 
		cifra = Descriptografar(criptografada,chave);
		
		return cifra;
}

	
	int main() {
	
	FILE *arquivo;
    int chave;
	char txt[1000];
	
	
	printf("Digite o Texto: ");
    scanf(" %[^\n]", txt);
	
    printf("Digite a chave (um numero inteiro): ");
    scanf("%i", &chave);

 char *mensagemCriptografada = cifraSub(txt,chave);

	arquivo = fopen("Cifra.txt","w");
		
		if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo.\n");
        return;
    }
    
    printf("\n\nmensagen: %s",mensagemCriptografada);
    fprintf(arquivo,"%s",mensagemCriptografada);

  char *mensagemDescriptografada = decifraSub(mensagemCriptografada,chave);
    printf("\nMensagem Descriptografada: %s\n", mensagemDescriptografada);

	free(mensagemCriptografada);
    free(mensagemDescriptografada);
    
    return 0;
}
