# set(CMAKE_CXX_FLAGS -Wno-non-pod-varargs)

set(BINARY ${CMAKE_PROJECT_NAME}_SimpleExample)
add_executable(${BINARY} sosh.cpp)
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib)
