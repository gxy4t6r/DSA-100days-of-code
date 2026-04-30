#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

int cmp(const void *a, const void *b) {
    Meeting *m1 = (Meeting*)a;
    Meeting *m2 = (Meeting*)b;
    return m1->end - m2->end;
}

int maxMeetings(int start[], int end[], int n) {
    Meeting arr[n];

    for (int i = 0; i < n; i++) {
        arr[i].start = start[i];
        arr[i].end = end[i];
    }

    qsort(arr, n, sizeof(Meeting), cmp);

    int count = 1;
    int lastEnd = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start > lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }

    return count;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 6, 7, 9, 9};
    int n = 6;

    printf("%d", maxMeetings(start, end, n));

    return 0;
}
