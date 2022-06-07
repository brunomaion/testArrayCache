#include <stdio.h>

int main(){


    //ESCREVER CSV
    
    //CRIAR ARQUIVO
    FILE *file;
    file = fopen("resultados.csv", "w");
    fprintf(file, "OPERAÇÃO;MATRIZ;TEMPO DE EXECUÇÃO;\n");
    fclose(file);

    return 0;

}

