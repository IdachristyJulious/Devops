#include <assert.h>
#include "add.c"
#include <stdio.h>
void test() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
}

int main() {
    test();
    printf("All tests passed!\n");
    return 0;
}
