#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Times_Max 20 


struct Time {
    int posicao;
    char nome[50];
    int pontos;
};

void Pesquisa(){
	 FILE *arquivo;
	 char time[50],linha[30];
	 
printf("\nTime procurado, Pontos ou Posicao: ");
scanf("%s",time);

arquivo = fopen("brasileirao","r");

while(fgets(linha,sizeof(linha),arquivo) != NULL){
	if(strstr(linha,time) != NULL){
		printf("\n\n");
		  printf("\t%s", linha);
	}
}
fclose(arquivo);
}

void Cinco(){
	 FILE *arquivo;
	 char time[50],linha[30];
	 int totalLinhas = 0;
	 
	 	arquivo = fopen("brasileirao","r");
	 	
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {	
	 	while(totalLinhas<20){
	 		
	 			totalLinhas++; 
	 			
			if(totalLinhas<=5){
			 printf("\t%s", linha);
			 } break;
		 }
	}

fclose(arquivo);
}

void Ultimo(){
		FILE *arquivo;
	 char linha[30];
	 int totalLinhas = 0;
	 
	 	arquivo = fopen("brasileirao","r");
	 	
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {	
	 	while(totalLinhas<22){	
		 		totalLinhas++;			  
	 			 if(totalLinhas>17){
				printf("\t%s", linha);
				}break;	
					  
		 }	
	}

fclose(arquivo);
}

void PontosP(){
    FILE *arquivo;
    char linha[100];
    int totalLinhas = 0,i,diferenca,a,b;
    int pontos[5] = {0};

    arquivo = fopen("brasileirao", "r");

    while (totalLinhas < 5 && fgets(linha, sizeof(linha), arquivo) != NULL) {

        if (strstr(linha, "Pontos:") != NULL) {
         
            int pontosLinha = atoi( strstr(linha, "Pontos:") + strlen("Pontos="));
            pontos[totalLinhas] = pontosLinha;
        }
        totalLinhas++;
    }
    
    do{
    printf("time A: ");
    scanf("%i",&a);
    printf("time B: ");
    scanf("%i",&b);
    
}while(a>5||a<0 || b>5 || b<0);

 diferenca = pontos[a-1]-pontos[b-1];
 
 printf("diferenca do Time A[%i] e B[%i] eh %i",a,b,diferenca);
    

    fclose(arquivo);
}

void PontosU(){
	    FILE *arquivo;
    char linha[100];
    int totalLinhas = 0,i,diferenca,a,b;
    int pontos[5] = {0};

    arquivo = fopen("brasileirao", "r");

    while (totalLinhas < 20 && fgets(linha, sizeof(linha), arquivo) != NULL) {
 totalLinhas++;
        if (strstr(linha, "Pontos:") != NULL && totalLinhas>15) {
        
            int pontosLinha = atoi( strstr(linha, "Pontos:") + strlen("Pontos:"));
            pontos[totalLinhas] = pontosLinha;
        }
    }
  
    do{
    printf("time A: ");
    scanf("%i",&a);
    printf("time B: ");
    scanf("%i",&b);
    
}while(a>20||a<16 || b>20 || b<16);

 diferenca = pontos[a]-pontos[b];
 
 printf("diferenca do Time A[%i] e B[%i] eh %i",a,b,diferenca);
    

    fclose(arquivo);
}

int compararPontos(const void *a, const void *b) {
    return ((struct Time *)b)->pontos - ((struct Time *)a)->pontos;
}

void TimesRec(struct Time times[], int totalTimes, int atual) {
    if (atual < totalTimes / 2) {
        printf("%d | %s | Pontos: %d\n", times[atual].posicao, times[atual].nome, times[atual].pontos);
        TimesRec(times, totalTimes, atual + 1);
    }
}

void MetadeTimes() {
    FILE *arquivo;
    struct Time times[Times_Max];
    int totalTimes = 0;

 
    arquivo = fopen("brasileirao", "r");

    if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo.\n");
        return;
    }
    while (fscanf(arquivo, "%d | %49[^|] | Pontos: %d\n", &times[totalTimes].posicao, times[totalTimes].nome, &times[totalTimes].pontos) == 3) {
        totalTimes++;
    }
    fclose(arquivo);
    
    qsort(times, totalTimes, sizeof(struct Time), compararPontos); 
    TimesRec(times, totalTimes, 0);
}

void menu(){
	int i;
	do{
	printf("\n1 - Pesquisar\n2 - Cinco Primeiros\n3 - Cinco Ultimos\n4 - Diferenca Primeiros\n5 - Diferenca Ultimos\n6 - Reordena Tabela \n0 - Sair\n\n");
	scanf("%i",&i);
	switch(i){
		case 1:
			system("cls");
			Pesquisa();
			break;
		case 2:
			system("cls");
			Cinco();
			break;
		case 3:
			system("cls");
			Ultimo();
			break;
		case 4:
			system("cls");
			PontosP();
			break;
		case 5:
			system("cls");
			PontosU();
			break;
		case 6:
			system("cls");
			MetadeTimes();
			break;
		default:
			system("cls");
			menu();
			break;
		case 0:
			exit;
			break;
	}
}while(i!=0);

}

int main(){

menu();



return 0;
}
