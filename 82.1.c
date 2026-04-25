#include <stdio.h>

// Lower Bound: first index where arr[i] >= key
int lowerBound(int arr[], int n, int key) {
    int low = 0, high = n;   // note: high = n

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Upper Bound: first index where arr[i] > key
int upperBound(int arr[], int n, int key) {
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    int lb = lowerBound(arr, n, key);
    int ub = upperBound(arr, n, key);

    printf("Lower Bound index: %d\n", lb);
    printf("Upper Bound index: %d\n", ub);

    return 0;
}
