#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char *t;
    t = malloc(2 * sizeof(char));
    t[0] = '1';
    t[1] = '0';
    printf("%d", atoi(t));
    return 0;
}
