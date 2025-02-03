#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int slot = ttyslot();
    printf("%d\n", slot);
    return 0;
}
