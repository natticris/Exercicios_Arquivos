// Exercicio_Arquivos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
void leitura(FILE *cfPtr, char n[1000]);
void Binario(FILE *cfPtr, char n[1000]);
void Inverso(FILE *cfPtr, char n[1000]);

int _tmain(void)
{
	
	//leitura da noticia
	int aux = 0;
	char name [1000];
	FILE *cfPtr = NULL;

	//le arquivo
	leitura(cfPtr, name);
	printf("%s", " \n");
	printf("%s", " \n");
	//guarda em binario
	Binario(cfPtr, name);
	printf("%s", " \n");
	printf("%s", " \n");
	//inverte
	Inverso(cfPtr, name);

	
	getchar();
scanf("%d", aux);

return 0;

}


void leitura(FILE *cfPtr, char n[1000]){

	if ((cfPtr = fopen("jornal.txt", "r")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	else{

		while (!feof(cfPtr)) {
			fgets(n, 1000, cfPtr);
			printf("%s", n);

		}

	}
	fclose(cfPtr);
};
void Binario(FILE *cfPtr, char n[1000]) {

	FILE *cfPtr2 = NULL;


	if ((cfPtr = fopen("jornal.txt", "r")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	if ((cfPtr2 = fopen("jornal.bin", "wb+")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	else {


		while (!feof(cfPtr)){

			fgets(n, 1000, cfPtr);
			fputs(n, cfPtr2);
			printf("%s", n);
		}

	}

	fclose(cfPtr);
	fclose(cfPtr2);

};
void Inverso(FILE *cfPtr, char n[1000]){
	FILE *cfPtr2 = NULL;
	if ((cfPtr = fopen("jornalinverso.txt", "wb+")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	if ((cfPtr2 = fopen("jornal.bin", "r")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	else {


		while (!feof(cfPtr2)){
			fseek(cfPtr2, 1000, SEEK_END);
			cfPtr2 -= sizeof(n);
			fputs(n, cfPtr);
			printf("%s", n);
		}

	}

	fclose(cfPtr);
}

	