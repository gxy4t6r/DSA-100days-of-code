#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int count;
} Candidate;

int findCandidate(Candidate arr[], int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0)
            return i;
    }
    return -1;
}

void winner(char votes[][100], int n) {
    Candidate arr[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int idx = findCandidate(arr, size, votes[i]);
        if (idx == -1) {
            strcpy(arr[size].name, votes[i]);
            arr[size].count = 1;
            size++;
        } else {
            arr[idx].count++;
        }
    }

    char result[100];
    int maxVotes = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i].count > maxVotes) {
            maxVotes = arr[i].count;
            strcpy(result, arr[i].name);
        } else if (arr[i].count == maxVotes) {
            if (strcmp(arr[i].name, result) < 0) {
                strcpy(result, arr[i].name);
            }
        }
    }

    printf("%s %d\n", result, maxVotes);
}

int main() {
    char votes[][100] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};
    int n = sizeof(votes) / sizeof(votes[0]);

    winner(votes, n);
    return 0;
}
