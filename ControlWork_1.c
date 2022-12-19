#include <stdio.h>
#define N 10

int main()
{
    int a[N][N] = {0}; // инициализация
    int i, x, y, k = 1;

    for (i = 0; i < N; i++) // первая часть
    {
        if (i%2 == 0) // четные диагонали
        {
            x = 0;
            y = i;
            while (y >= 0)
            {
                a[x][y] = k;
                x++; y--; k++;
            }
        }
        else // нечетные диагонали
        {
            x = i;
            y = 0;
            while (x >= 0)
            {
                a[x][y] = k;
                x--; y++; k++;
            }
        }
    }

    for (i = 1; i < N; i++) // вторая часть
    {
        if (i%2 == 0)
        {
            x = N-1;
            y = i;
            while (y <= N-1)
            {
                a[x][y] = k;
                x--; y++; k++;
            }
        }
        else
        {
            x = i;
            y = N-1;
            while (x <= N-1)
            {
                a[x][y] = k;
                x++; y--; k++;
            }
        }
    }

    for (int l = 0; l < N; l++) // вывод
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", a[l][j]);
        }
        printf("\n");
    }
    return(0);
}
