#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    //el 200 es la llave para que los procesos se conecten a ese bloque, 0644 son los permisos que se dan al usuario que crean el bloque
    int shmID = shmget(200, 100, 0644 | IPC_CREAT);
    int hijos[5];

    for (int i = 0; i < 5; i++){ //la i identifica el proceso
        int pid = fork();
        hijos[i] = pid;
        if (pid != 0){
            shmID = shmget(200, 100, 0644);
            char * var = (char *) shmat(shmID, NULL, 0);
            var = &var[i*10]; //& te da la dirección
            for (int j = 0; j < 10; j++){ //la j nos ayuda a navegar en el arreglo de caracteres
                var[j] = i + '0';
            }
            return 0; //el proceso hijo se saldrá del for con el return
        }
    }
    for (int i = 0; i < 5; i++){
        waitpid(hijos[i], 0, 0);
    }

    char *var = (char *)shmat(shmID, NULL, 0);
    printf("El contenido es %s\n", var);
    return 0;
    /*char *var;

    //cualquier proceso que ejecute esta funcion puede usar el bloque de memoria
    var = (char *) shmat(shmID, NULL, 0); //regresa un apuntador, pero tipo void *
    sprintf(var, "hola mundo");
    printf("esto tiene var %s", var);
    */
}