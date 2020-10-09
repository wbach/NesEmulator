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
../../UT/Olc6502Tests.cpp
)

set(Source
../../Source/Cpu/AddressingModes.cpp
../../Source/Cpu/Opcodes.cpp
../../Source/Cpu/Olc6502.cpp
../../Source/Bus/Bus.cpp
../../Source/NesEmulator.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Source/
)

add_library(NesEmulatorLib ${Source})

add_executable(NesEmulatorTestsExe ${UTSource})
add_dependencies(NesEmulatorTestsExe NesEmulatorLib googletest)
target_link_libraries(NesEmulatorTestsExe NesEmulatorLib gtest gmock gtest_main pthread)

add_executable(NesEmulatorExe ../../Source/main.cpp)
target_link_libraries(NesEmulatorExe NesEmulatorLib pthread)