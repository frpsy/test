add_library(libA_sub src/libA_sub.c)

# libA_sub의 헤더를 libA에만 공개, 외부에는 감춤
target_include_directories(libA_sub PUBLIC include)
