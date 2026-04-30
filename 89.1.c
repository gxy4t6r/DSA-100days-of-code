#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];

            if (students > m)
                return 0;
        } else {
            pages += arr[i];
        }
    }

    return 1;
}

int allocatePages(int arr[], int n, int m) {
    if (m > n)
        return -1;

    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    printf("%d", allocatePages(arr, n, m));

    return 0;
}
