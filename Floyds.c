#include <stdio.h>
int a[10][10], D[10][10], n;
void floyd(int[][10], int);
int min(int, int);
int main()
{
    printf("Enter the no. of vertices:");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    floyd(a, n);
    printf("Distance Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void floyd(int a[][10], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            D[i][j] = a[i][j];
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                D[i][j] = min(D[i][j], (D[i][k] + D[k][j]));
            }
        }
    }
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// OUTPUT:
// Enter the no. of vertices:4
// Enter the cost adjacency matrix:
// 0 99 3 99
// 2 0 99 99
// 99 6 0 1
// 7 99 99 0
// Distance Matrix:
// 0 9 3 4
// 2 0 5 6
// 8 6 0 1
// 7 16 10 0
