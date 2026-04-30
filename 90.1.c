#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (time + arr[i] > maxTime) {
            painters++;
            time = arr[i];

            if (painters > k)
                return 0;
        } else {
            time += arr[i];
        }
    }

    return 1;
}

int painterPartition(int arr[], int n, int k) {
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int k = 2;

    printf("%d", painterPartition(boards, n, k));

    return 0;
}
