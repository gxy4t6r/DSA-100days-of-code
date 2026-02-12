#include <stdio.h>

int main() {
    int a[10][10], i, j, n, flag = 0;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                flag = 1;
                break;
            }
        }
    }

    if(flag == 0)
        printf("Symmetric Matrix");
    else
        printf("Not Symmetric Matrix");

    return 0;
}
