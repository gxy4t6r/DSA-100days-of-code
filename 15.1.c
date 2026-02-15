#include <stdio.h>

int main()
{
    int n, i, j, sum = 0;
    scanf("%d", &n);

    int matrix[n][n];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        sum += matrix[i][i];
        if(i != n - i - 1)
            sum += matrix[i][n - i - 1];
    }

    printf("%d", sum);

    return 0;
}
