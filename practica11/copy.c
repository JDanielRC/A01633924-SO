#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 512


int main (int argc, char** argv) {

    int from, to, nr, nw, n;
    char buf[BUFSIZE];
    //los ints regresados de open, creat, y read, son como IDS para usar mas adelante en otras funciones como write
    if ((from = open(argv[1], O_RDONLY)) < 0) { //abriendo archivo en modo lectura
        printf("Error al abrir el archivo origen");
        exit(1);
    }
    if ((to = creat(argv[2], 0666)) < 0) { //creando archivos con permisos de escritura
        printf("Error creando el archivo destino");
        exit(2);
    } 
    while((nr = read(from, buf, sizeof( buf))) != 0) { //leyendo el archivo, agarra los primeros 512 bytes con sizeof y de ahi empieza
        if (nr < 0) {
            printf("Error leyendo el archivo origen");
            exit(3);
        }
        nw=0; 
        do {
            if ((n = write(to, &buf[nw], nr-nw)) < 0) { //nw es el numero de lineas ya leidas, entonces se resta
                printf("Error escribiendo en el archivo destino");
                exit(4);
            }
            nw += n; //almacenando el número de lineas leídas, n es el numero de lineas leidas
            } while (nw < nr);
        }
    close(from);
    close(to);

}