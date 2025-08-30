add_library(libB src/libB.c)

target_include_directories(libB PUBLIC include)

add_subdirectory(sub)
target_link_libraries(libB PRIVATE libB_sub libA_sub)
