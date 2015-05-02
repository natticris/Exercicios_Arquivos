//Le e imprimi o arquivo

#include "stdafx.h"
#include <stdio.h>
int _tmain(void)
{
	int aux = 0;
	char name[1000];


	FILE *cfPtr;
	if ((cfPtr = fopen("jornal.txt", "r")) == NULL){
		printf("Arquivo nao pode ser aberto\n");

	}
	else{
		printf("%s\n", "Texto");
		fscanf(cfPtr, "%s", name);
		while (!feof(cfPtr)){
			printf("%s\n", name);
			fscanf(cfPtr, "%s", name);

		}

		fclose(cfPtr);
	}
	scanf("%d", aux);

	return 0;
}
