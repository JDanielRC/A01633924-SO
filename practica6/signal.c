#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void processSignal(int s) {
    printf("Recibi señal %d\n", s);
}

void notKill(int s) {
    printf("No puedes matarme\n");
}

int main() {
    signal(10, processSignal);
    signal(15, notKill);
    while(1) {
        sleep(3);
        printf("Trabajando..\n");
    }
    return 0;
}