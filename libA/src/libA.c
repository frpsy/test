#include <stdio.h>
#include "libA_sub.h"
#include "libB_sub.h"

void libA_func(void) {
    printf("libA_func called\n");
    libA_sub_func();
    libB_sub_func();
}
