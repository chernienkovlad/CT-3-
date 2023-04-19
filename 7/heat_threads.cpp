#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct
{
    int N;
    int M;
    int P;
    double* u_old;
    double* u_new;
} Heat_calc;

Heat_calc* setup(int M, int N, int P);
void heat_straight_calc(Heat_calc* rod);
void func(void* value);
void heat_threads_calc(Heat_calc* rod);
void heat_print(Heat_calc* rod, const char filename[]);
void heat_free(Heat_calc* rod);

sem_t s;

int main(int argc, char** argv)
{
    const int l = 1;
    sem_init(&s, 0, 0);

    int M = atoi(argv[1]);
    double T = atof(argv[2]);
    int P = atoi(argv[3]);

    double h = (l*1.0) / M;
    double tau = 0.3 * h*h;
    int N = T / tau;

    Heat_calc* rod = setup(M, N, P);
    
    // heat_straight_calc(rod);
    heat_threads_calc(rod);
    
    heat_print(rod, "result.txt");
    heat_free(rod);

    return 0;
}

Heat_calc* setup(int M, int N, int P)
{
    Heat_calc* tmp = (Heat_calc*)calloc(1, sizeof(Heat_calc));
    tmp->M = M;
    tmp->N = N;
    tmp->P = P;
    tmp->u_old = (double*)calloc(tmp->M, sizeof(double));
    tmp->u_new = (double*)calloc(tmp->M, sizeof(double));

    tmp->u_old[M-1] = 1;
    tmp->u_new[M-1] = 1;

    return tmp;
}

void heat_straight_calc(Heat_calc* rod)
{
    double* tmp = 0;

    for (int i = 0; i < rod->N; i++)
    {
        for (int j = 1; j < rod->M-1; j++)
        {
            rod->u_new[j] = rod->u_old[j] + 0.3*(rod->u_old[j+1] - 2*rod->u_old[j] + rod->u_old[j-1]);
        }
        if (i != rod->N-1)
        {
            tmp = rod->u_old;
            rod->u_old = rod->u_new;
            rod->u_new = tmp;
        }
    }
}

void calc(void* value)
{

}

void heat_threads_calc(Heat_calc* rod)
{
    pthread_t t[rod->P];

    for (int i = 0; i < rod->N; i++)
    {
        for (int j = 0; j < rod->P; j++)
        {
            pthread_create(&t[j], NULL, calc, );
        }
    }
}

void heat_print(Heat_calc* rod, const char filename[])
{
    FILE* f = fopen(filename, "w");

    for (int i = 0; i < rod->M; i++)
        fprintf(f, "[%d] – %lf\n", i, rod->u_new[i]);
        
    fclose(f);
}

void heat_free(Heat_calc* rod)
{
    free(rod->u_old);
    free(rod->u_new);
    free(rod);
}
