cmake_minimum_required(VERSION 3.5)


project(Toyshell)


# name of executeable
set(TARGET toyshell)


set(HEADERS
)

set(SOURCES
    toyshell.cpp
)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()

add_executable(${TARGET} ${SOURCES} ${HEADERS}) 

if(CONAN_LIB_DIRS_READLINE)
    message(STATUS "readline includes: ${CONAN_INCLUDE_DIRS_READLINE}")
    target_include_directories(${TARGET} PRIVATE ${CONAN_INCLUDE_DIRS_READLINE})

    message(STATUS "readline libs: ${CONAN_LIB_DIRS_READLINE}")
    target_link_libraries(${TARGET} "${CONAN_LIB_DIRS_READLINE}/libreadline.so.8.0" ncurses)
else()
    target_link_libraries(${TARGET} readline)
endif()





