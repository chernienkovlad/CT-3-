#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int a = atoi(argv[1]), b = atoi(argv[2]);

    if (!strcmp(argv[3], "sum"))
    {
        printf("%d\n", a + b);
    }
    else if (!strcmp(argv[3], "sub"))
    {
        printf("%d\n", a - b);
    }
    else if (!strcmp(argv[3], "mul"))
    {
        printf("%d\n", a * b);
    }
    else if (!strcmp(argv[3], "div"))
    {
        printf("%d\n", a / b);
    }

    return 0;
}
