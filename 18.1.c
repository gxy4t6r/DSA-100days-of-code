#include <stdio.h>

int main() {
    int n, k, i;
    scanf("%d", &n);
    
    int arr[n];
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    k = k % n;
