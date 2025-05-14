#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 4);
    printf("Sum of 5 and 4 is: %d\n", result);
    return 0;
}
