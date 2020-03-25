#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void testfork() 
{ 
    pid_t proceso = fork();
    if (proceso == 0){
        execlp("ls", "ls", "-a", "/", (char*) NULL);
    } else{ 
        printf("Soy el padre\n");
    }


} 
int main() 
{ 
    testfork(); 
    return 0; 
} 