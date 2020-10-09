project(NesEmulator)
cmake_minimum_required(VERSION 3.0)

SET(GCC_COVERAGE_LINK_FLAGS "-static-libgcc")
SET(CMAKE_CXX_FLAGS  "-std=c++17 -Wuninitialized -Wtype-limits -Wdelete-incomplete -Wall -pedantic ${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wno-expansion-to-defined")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_compile_options(
    -std=c++17
    -O3
)

include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

set(UTSource
../../UT/main.cpp
)

add_executable(NesEmulatorTestsExe ${UTSource})
add_dependencies(NesEmulatorTestsExe googletest gmock)
target_link_libraries(NesEmulatorTestsExe gtest gmock gtest_main pthread)

set(Source
../../Source/main.cpp
)
#add_library(NesEmulatorLib ${Source})
add_executable(NesEmulatorExe ${Source})