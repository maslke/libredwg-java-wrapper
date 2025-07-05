cmake_minimum_required(VERSION 3.22.1)
project(libredwg_java_wrapper)

set(CMAKE_C_STANDARD 99)

set(JAVA_HOME "/usr/lib/jvm/java-11-openjdk-amd64")
include_directories(
    ${JAVA_HOME}/include
    ${JAVA_HOME}/include/linux
)

include_directories("/usr/local/include")
link_directories("/usr/local/lib")

add_library(dwg_java SHARED native/dwg.c)

target_link_libraries(dwg_java redwg cjson m)
