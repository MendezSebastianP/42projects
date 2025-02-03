
#include <unistd.h>
#include <stdio.h>


int main() {
  char *ret, tty[40];

  if ((ret = ttyname(STDIN_FILENO)) == NULL)
    perror("ttyname() error");
  else {
    printf("The ttyname associated with my stdin is %s\n", ret);
  }
}
