project(myApp)
add_executable(myApp src/main.cpp)
target_link_libraries(myApp ${SDL2_LIBRARY})
install(TARGETS myApp RUNTIME DESTINATION ${BIN_DIR})
