#include <stdio.h>

void libA_func(void) {
    printf("libA_func called\n");
    libA_sub_func();
    libB_sub_func();
}
