add_library(libA src/libA.c)

# libA는 자기 include 디렉토리를 외부에 공개
target_include_directories(libA PUBLIC include)

# libA는 sub 라이브러리 사용
add_subdirectory(sub)
target_link_libraries(libA PRIVATE libA_sub libB_sub)
