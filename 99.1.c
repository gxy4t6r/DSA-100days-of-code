#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

int cmp(const void *a, const void *b) {
    Car *c1 = (Car*)a;
    Car *c2 = (Car*)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double lastTime = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > lastTime) {
            fleets++;
            lastTime = cars[i].time;
        }
    }

    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    printf("%d", carFleet(target, position, speed, n));

    return 0;
}
