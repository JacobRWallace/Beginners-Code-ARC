#include <stdio.h>
#include <unistd.h> // usleep (microseconds)

#define SLEEP_USEC 500000 // 0.5 seconds = 500,000 microseconds

void linearLoopExample(int n)
{
    for (int i = 0; i < n; i++) {
        printf("Linear i = %d\n", i);               // O(n)
        usleep(SLEEP_USEC);
    }

    return;
}

void logarithmicLoopExample(int n)
{
    for (int i = 1; i <= n; i *= 2) {
        printf("Log i = %d\n", i);                  // O(log n)
        usleep(SLEEP_USEC);
    }

    return;
}

void nestedLoopExample(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nested i=%d j=%d\n", i, j);     // O(n^2)
            usleep(SLEEP_USEC);                     // 0.1 sec (faster so it doesn't take forever)
        }
    }

    return;
}

void linearLogarithmicExample(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j *= 2) {
            printf("nlogn i=%d j=%d\n", i, j);      // O(n log n)
            usleep(SLEEP_USEC);
        }
    }

    return;
}

int main() {
    int n = 8;

    puts("linearLoopExample");
    linearLoopExample(n);
    puts("");

    puts("logarithmicLoopExample");
    logarithmicLoopExample(n);
    puts("");

    // Warning: nested grows fast—keep n small
    // puts("nestedLoopExample");
    // nestedLoopExample(n);
    // puts("");

    puts("linearLogarithmicExample");
    linearLogarithmicExample(n);
    puts("");

    return 0;
}
