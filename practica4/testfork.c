#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void testfork() 
{ 
    printf("hola\n");
    pid_t proceso = fork();
    
    if (proceso == 0){ // comprueba si el proceso no es padre 
        printf("Soy el hijo\n");
    } else{ 
        printf("Soy el padre\n");
    }
    printf("jelou\n");
    //lo que sucede, es que al ejecutar esto, primero se va a imprimir que es el padre, ya que el primer proceso es el padre
    //y por lo tanto llega al else, y la segunda vez 

} 
int main() 
{ 
    testfork(); 
    return 0; 
} 