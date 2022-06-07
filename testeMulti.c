//OAC - PRATICA 3 - BRUNO MAION, LUCCA NERES

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



//GLOBAL

///////////////////////////////
int colunaA,linhaA, colunaB, linhaB;
double **matrizA, **matrizB, **matrizBT, **matrizC;
int i, j;


//FUNCOES
void printM(double **matrizA, double **matrizB, int linhaA, int colunaA, int linhaB, int colunaB);
double transpor(double **matrizB, double **matrizBT, int linhaB, int colunaB);
double multiNormal(double **matrizA, double **matrizB, int linhaA, int colunaA, int linhaB, int colunaB, double **matrizC);
double multiT(double **matrizA, double **matrizBT, int linhaA, int colunaA, int linhaB, int colunaB, double **matrizC);
void printMC(double **matrizC, int colunaA, int linhaA);

int main (int argc, char **argv) {

    //RAND
    srand(time(NULL));

    //TRANSFORMAR INT EM INTEIRO
    linhaA = atoi(argv[2]);
    colunaA = atoi(argv[3]);
    linhaB = atoi(argv[4]);
    colunaB = atoi(argv[5]);


    //ALOCAÇÃO MATRIZ 1
    matrizA = malloc(linhaA * sizeof(double*));    
    matrizB = malloc(linhaB * sizeof(double*));
    matrizC = malloc(linhaA * sizeof(double*));
    matrizBT = malloc(colunaB * sizeof(double*));


    // +ALEATORIOS 
    for (i=0; i<linhaA; i++){
        matrizA[i] = malloc(colunaA * sizeof(double));
        for(int j=0; j<colunaA; j++)
        matrizA[i][j] = rand() % 10;
    }

    for(int i=0; i<linhaB; i++){
        matrizB[i] = malloc(colunaB * sizeof(double));
        for(int j=0; j<colunaB; j++)
        matrizB[i][j] = rand() % 10;
    }

    for(int i=0; i<colunaB; i++){
        matrizC[i] = malloc(linhaB * sizeof(double));
    }

    for(int i=0; i<colunaB; i++){
        matrizBT[i] = malloc(linhaB * sizeof(double));
    }





 //STOP ERRO DE ARGUMENTO --- !! NAO CONSEGUI JUNTAR OS DOIS
    if (*argv[1]!=('t') && *argv[1]!=('o') ) {

        printf("\n!! PARÂMETROS ERRADOS !!  Argumentos = 'o | t' 'valor linha>0' 'valor coluna>0'\n");
        exit(-1);

    }
        if (linhaA==0 || colunaA==0 || linhaB==0 || colunaB==0)  {

        printf("!! PARÂMETROS ERRADO !!   Argumentos = 'o | t' 'valor linha>0' 'valor coluna>0'\n");
        exit(-1);
    }



    if (colunaA != linhaB) {

        printf("COLUNA DIFERENTE DE LINHA \n");

    } else if ((strcmp(argv[1], "o") == 0)) {
        printf("\nORIGINAL CERTO\n");

        multiNormal(matrizA, matrizB, linhaA, colunaA, linhaB, colunaB, matrizC);
        printMC(matrizC, colunaA, linhaA);
        printM(matrizA, matrizB, linhaA, colunaA, linhaB, colunaB);

    } else if ((strcmp(argv[1], "t") == 0) && (colunaA == linhaB)) {
        printf("\nTRANSPOSTA CERTO\n");
        transpor(matrizB, matrizBT, linhaB, colunaB);
        multiT(matrizA, matrizBT, linhaA, colunaA, linhaB, colunaB, matrizC);
        printMC(matrizC, colunaA, linhaA);
        printM(matrizA, matrizB, linhaA, colunaA, linhaB, colunaB);
    } 
    


    return 0;
}

void printM(double **matrizA, double **matrizB, int linhaA, int colunaA, int linhaB, int colunaB) {
        printf("MATRIZ A\n");
        
        for (i = 0; i < linhaA; i++) {
            for (j = 0; j < colunaA; j++) {
            printf("%.2f ", matrizA[i][j]);
            }
        printf(" \n");
        }

        printf(" \nMATRIZ B\n");

        for (i = 0; i < linhaB; i++) {
            for (j = 0; j < colunaB; j++) {
            printf("%.2f ", matrizB[i][j]);
            }
        printf(" \n");
        }

        printf(" \nMATRIZ BT\n");

        for (i = 0; i < colunaB ; i++) {
            for (j = 0; j < linhaB; j++) {
            printf("%.2lf ", matrizBT[i][j]);
            }
        printf(" \n");
        } 

}

double transpor(double **matrizB, double **matrizBT,int linhaB, int colunaB) {


        for (i = 0; i < linhaB; i++) {
            for (j = 0; j < colunaB; j++) {
            matrizBT[j][i]=matrizB[i][j];
            }
        }

    return **matrizBT;
    
}

double multiNormal(double **matrizA, double **matrizB, int linhaA, int colunaA, int linhaB, int colunaB, double **matrizC) {

    double aux=0;
    int x;

	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {	
			matrizC[i][j] = 0;
			for(x = 0; x < colunaB; x++) {
				aux +=  matrizA[i][x] * matrizB[x][j];
			}
			matrizC[i][j] = aux;
			aux = 0;
		}
	}


    return **matrizC;

}

double multiT(double **matrizA, double **matrizBT, int linhaA, int colunaA, int linhaB, int colunaB, double **matrizC) {

    double aux=0;
    int x;

	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {	
			matrizC[i][j] = 0;
			for(x = 0; x < linhaB; x++) {
				aux +=  matrizA[i][x] * matrizBT[j][x];
			}
			matrizC[i][j] = aux;
			aux = 0;
		}
	}


    return **matrizC;

}

void printMC(double **matrizC, int colunaA, int linhaA) {

        printf(" \nMATRIZ C- RESULTADO\n");

        for (i = 0; i < linhaA; i++) {
            for (j = 0; j < colunaA; j++) {
            printf("%.2f ", matrizC[i][j]);
            }
        printf(" \n");
        }
            
    printf(" \n");
}

void a();