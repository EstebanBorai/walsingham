#include "socket.h"

int main() {
    int result = sniff();

    if (result == 1) {
        printf("Application exited. Error found.\n");
    }
}
