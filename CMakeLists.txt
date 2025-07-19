cmake_minimum_required(VERSION 3.22.1)
project(libredwg_java_wrapper)

set(CMAKE_C_STANDARD 99)

set(JAVA_HOME "/usr/lib/jvm/java-11-openjdk-amd64")
include_directories(
    ${JAVA_HOME}/include
    ${JAVA_HOME}/include/linux
)

include_directories("${PROJECT_SOURCE_DIR}/libs/include")
link_directories("${PROJECT_SOURCE_DIR}/libs")
include_directories(${PROJECT_SOURCE_DIR}/native/util)


file(GLOB ENTITY_SOURCES "${PROJECT_SOURCE_DIR}/native/entity/*.c")
file(GLOB OBJ_SOURCES "${PROJECT_SOURCE_DIR}/native/obj/*.c")
file(GLOB UTIL_SOURCES "${PROJECT_SOURCE_DIR}/native/util/*.c")

add_library(dwg_java SHARED native/dwg.c ${OBJ_SOURCES} ${ENTITY_SOURCES} ${UTIL_SOURCES})

target_link_libraries(dwg_java redwg m)
