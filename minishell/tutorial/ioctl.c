#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

int main(void) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printf("Taille du terminal : %d lignes, %d colonnes, %d pixels en largeur, %d pixels en hauteur\n",
    w.ws_row, w.ws_col, w.ws_xpixel, w.ws_ypixel);

    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    printf("Attributs du terminal :\n");
    printf("  c_iflag: 0x%x\n", term.c_iflag);
    printf("  c_oflag: 0x%x\n", term.c_oflag);
    printf("  c_cflag: 0x%x\n", term.c_cflag);
    printf("  c_lflag: 0x%x\n", term.c_lflag);
    return 0;
}