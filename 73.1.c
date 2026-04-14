#include <stdio.h>

int main() {
    char str[1000];
    int freq[256] = {0};

    scanf("%s", str);

    // Count frequency
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // Find first non-repeating character
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            printf("%c\n", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character\n");
    return 0;
}
