cmake_minimum_required(VERSION 3.12)
project(superficies)

set(CMAKE_CXX_STANDARD 17)

add_executable(superficies main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})