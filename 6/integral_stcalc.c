#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// sqrt(4 - x^2) | 0-2

double get_func_value(double x)
{
    return (sqrt(4 - x*x));
}

double get_integral(int i_tau)
{
    double dx = 2.0 / i_tau;
    double sum = 0;

    for (int i = 1; i < i_tau; i++)
        sum += get_func_value(i*dx);

    sum = dx*((get_func_value(0) + get_func_value(i_tau*dx))/2 + sum);

    return sum;
}

int main(int argc, char** argv)
{
    clock_t start, end;

    int i_tau = atoi(argv[1]);

    start = clock();
    double sum = get_integral(i_tau);
    end = clock();

    printf("-------------\nSTRAIGHT CALC\n-------------\nValue: %lf\nTime: %lf\n\n", sum, difftime(end, start) / CLOCKS_PER_SEC);

    return 0;
}
