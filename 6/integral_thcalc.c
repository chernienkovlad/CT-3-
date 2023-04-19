#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

// sqrt(4 - x^2) | 0-2

typedef struct
{
    double dx;
    double x_1;
    double x_2;
    double sum;
} SumThread;

double get_func_value(double x)
{
    return (sqrt(4 - x*x));
}

void* calc(void* tmp)
{
    SumThread* sumthrd = (SumThread*)tmp;
    int i_tau = (sumthrd->x_2 - sumthrd->x_1) / sumthrd->dx;
    sumthrd->sum = 0;

    for (int i = 1; i < i_tau; i++)
        sumthrd->sum += get_func_value(sumthrd->x_1 + sumthrd->dx*i);

    sumthrd->sum = sumthrd->dx*((get_func_value(sumthrd->x_1) + get_func_value(sumthrd->x_2))/2 + sumthrd->sum);

    pthread_exit(NULL);
}

double get_integral(int i_tau, int threads_count)
{
    double dx = 2.0 / i_tau;
    pthread_t t[threads_count];
    int segs_count = i_tau / threads_count;
    SumThread* sumthrds = (SumThread*)calloc(threads_count, sizeof(SumThread));

    double sum = 0;
    for (int i = 0; i < threads_count; i++)
    {
        sumthrds[i].dx = dx;
        sumthrds[i].x_1 = segs_count*dx*i;

        if (i != threads_count - 1)
        {
            sumthrds[i].x_2 = segs_count*dx*(i+1);
            pthread_create(&t[i], NULL, calc, &sumthrds[i]);
        }
        else
        {
            sumthrds[i].x_2 = 2.0;
            pthread_create(&t[i], NULL, calc, &sumthrds[i]);
        }
    }

    for (int i = 0; i < threads_count; i++)
        pthread_join(t[i], NULL);

    for (int i = 0; i < threads_count; i++)
        sum += sumthrds[i].sum;

    free(sumthrds);
    return sum;
}

int main(int argc, char** argv)
{
    clock_t start, end;

    int i_tau = atoi(argv[1]);
    int threads_count = atoi(argv[2]);

    start = clock();
    double sum = get_integral(i_tau, threads_count);
    end = clock();

    printf("------------\nTHREADS CALC\n------------\nValue: %lf\nTime: %lf\n\n", sum, difftime(end, start) / CLOCKS_PER_SEC);

    return 0;
}
