#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *i1 = (Interval*)a;
    Interval *i2 = (Interval*)b;
    return i1->start - i2->start;
}

int mergeIntervals(Interval arr[], int n, Interval result[]) {
    qsort(arr, n, sizeof(Interval), cmp);

    int idx = 0;
    result[idx] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[idx].end) {
            if (arr[i].end > result[idx].end)
                result[idx].end = arr[i].end;
        } else {
            idx++;
            result[idx] = arr[i];
        }
    }

    return idx + 1;
}

int main() {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = 4;

    Interval result[n];
    int size = mergeIntervals(arr, n, result);

    for (int i = 0; i < size; i++)
        printf("[%d,%d] ", result[i].start, result[i].end);

    return 0;
}
