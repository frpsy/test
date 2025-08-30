#include <stdio.h>
#include "libB_sub.h"
#include "libA_sub.h"

void libB_func(void) {
    printf("libB_func called\n");
    libB_sub_func();
    libA_sub_func();
}
