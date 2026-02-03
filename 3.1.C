#include <stdio.h>

int main()
{
    int a[100], n, key, count = 0, found = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    for(int i = 0; i < n; i++)
    {
        count++;
        if(a[i] == key)
        {
            found = 1;
            break;
        }
    }

    if(found == 1)
        printf("Element found\n");
    else
        printf("Element not found\n");

    printf("Comparisons = %d", count);

    return 0;
}
