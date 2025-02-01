#include <unistd.h>
#include <stdio.h>


int     main(void)
{
        char buf[1000];
        getcwd(buf, 1000);
        printf("result: %s", buf);
        return (0);
}
