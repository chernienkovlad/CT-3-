#include <stdio.h>
#include <stdlib.h>

#define SQUARE_SIZE 100

int main()
{
    unsigned int N = 0;
    scanf("%d", &N);
    
    char **points = (char**)malloc(SQUARE_SIZE * sizeof(char*) + SQUARE_SIZE * SQUARE_SIZE * sizeof(char));
    char *ptr = (char*)(points + SQUARE_SIZE);
    for (int i = 0; i < SQUARE_SIZE; i++)
        points[i] = ptr + i * SQUARE_SIZE;

    for (int i = 0; i < SQUARE_SIZE; i++)
        for (int j = 0; j < SQUARE_SIZE; j++)
            points[i][j] = 'N';

    int id, tmp_x, tmp_y;
    char tmp_clr;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &id);
        if (id == 1) {
            scanf("%d %d %c", &tmp_x, &tmp_y, &tmp_clr);
            points[tmp_x][tmp_y] = tmp_clr;
        } else if (id == 2) {
            scanf("%d %d", &tmp_x, &tmp_y);
            printf("%c\n", points[tmp_x][tmp_y]);
        }
    }

    free(points);
    return 0;
}
