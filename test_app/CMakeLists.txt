cmake_minimum_required (VERSION 2.6)
project (test_motor_cape)

include_directories(include)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

include_directories(${i2cpp_SOURCE_DIR}/include)
include_directories(${motor_cape_SOURCE_DIR}/include)
# include_directories(${CMAKE_SOURCE_DIR}/bbg_motor_cape)


add_compile_options(-Wall)
add_compile_options(-Wextra)
add_executable(test_motor_cape ${SOURCES})
set_property(TARGET test_motor_cape PROPERTY CXX_STANDARD 14)
set_property(TARGET test_motor_cape PROPERTY CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

target_link_libraries(test_motor_cape motor_cape i2c++)
