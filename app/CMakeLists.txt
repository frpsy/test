add_executable(my_app main.c)

# app은 libA와 libB를 사용
target_link_libraries(my_app PRIVATE libA libB pthread)
