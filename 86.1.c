#include <stdio.h>

double sqrtBinary(int n, int precision) {
    int low = 0, high = n;
    double mid, ans = 0;

    while (low <= high) {
        mid = (low + high) / 2.0;

        if (mid * mid == n)
            return mid;

        if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    double increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= n)
            ans += increment;

        ans -= increment;
        increment /= 10;
    }

    return ans;
}

int main() {
    int n = 10;
    int precision = 5;

    printf("Square root: %.5lf\n", sqrtBinary(n, precision));

    return 0;
}
