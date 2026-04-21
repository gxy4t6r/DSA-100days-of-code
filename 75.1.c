#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple hash map using arrays (for demonstration)
int hash[MAX];
int indexMap[MAX];

int largestZeroSumSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Initialize hash map
    for (int i = 0; i < MAX; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: If sum is zero, max length = i + 1
        if (sum == 0) {
            maxLen = i + 1;
        }

        int key = abs(sum) % MAX;

        // Case 2: If sum seen before
        if (hash[key] != -1 && indexMap[key] == sum) {
            int length = i - hash[key];
            if (length > maxLen) {
                maxLen = length;
            }
        } else {
            // Store first occurrence
            hash[key] = i;
            indexMap[key] = sum;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {1, 2, -3, 3, -1, 2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = largestZeroSumSubarray(arr, n);
    printf("Largest Subarray Length with Zero Sum: %d\n", result);

    return 0;
}
