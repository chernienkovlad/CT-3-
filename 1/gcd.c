#include <stdio.h>

int main()
{
    unsigned int a = 0, b = 0;
    scanf("%d %d", &a, &b);

    unsigned int min = (a < b) ? a : b;
    unsigned int gcd = 1;

    for (int i = 1; i < min; i++)
        if (a % i == 0 && b % i == 0)
            gcd = i;

    printf("%d\n", gcd);

    return 0;
}
