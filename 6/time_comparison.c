#include <stdlib.h>

int main()
{
    system("gcc integral_stcalc.c -o straight");
    system("gcc integral_thcalc.c -o threads");

    system("./straight 1000000000");
    system("./threads 1000000000 10");

    return 0;
}
