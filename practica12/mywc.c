#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
int main(int argn, char **argv){
    char *fileName = argv[1];
    char buffer;
    char espacio = 0;
    int numChar = 0;
    int numLines = 0;
    int numWord = 0;
    int fd = open(fileName, O_RDONLY);
    if (fd < 0){
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd, &buffer, 1)){
        //printf("%c",buffer);
        numChar++;
        if (buffer == '\n'){
            numLines++;
        }
        if ((buffer == ' ' || buffer == '\n' || buffer == EOF) && espacio == 0){
            espacio = 1;
            numWord++;
        } else if(buffer != ' ' && buffer != '\n' && buffer != EOF){
            espacio = 0;
        }
        

    }
    printf("numero de caracteres: %d \n",numChar);
    printf("numero de lineas: %d \n",numLines);
       printf("numero de palabras: %d \n",numWord);
    close(fd);
    exit(0);
}