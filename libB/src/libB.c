#include <stdio.h>

void libB_func(void) {
    printf("libB_func called\n");
    libB_sub_func();
    libA_sub_func();
}
