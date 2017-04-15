cmake_minimum_required(VERSION 3.7.1)

# hunter: CMake on steroids ;)
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.18.31.tar.gz"
    SHA1 "4ef305dffd0483325ef1096865e151cb162e53a0"
)

project(crasis-experimental VERSION 0.99.1)

add_subdirectory(src)

add_subdirectory(benchmark)

include(CTest)
enable_testing()
add_subdirectory(test)
