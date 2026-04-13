#include <stdio.h>

char firstRepeated(char *str) {
    int hash[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        if (hash[str[i]] == 1)
            return str[i];
        hash[str[i]]++;
    }

    return '\0';
}

int main() {
    char str[] = "programming";

    char result = firstRepeated(str);

    if (result)
        printf("First repeated character: %c\n", result);
    else
        printf("No repeated character\n");

    return 0;
}
