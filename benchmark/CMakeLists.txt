# Benchmarks
set(CRASIS__EXPERIMENTAL_BENCHMARKS_SOURCES
  bench01.cpp
)
add_executable(crasis-experimental-benchmarks ${CRASIS__EXPERIMENTAL_BENCHMARKS_SOURCES})

hunter_add_package(benchmark)
find_package(benchmark CONFIG REQUIRED)

target_link_libraries(crasis-experimental-benchmarks benchmark::benchmark)
target_include_directories(crasis-experimental-benchmarks
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../src/>
)
set_target_properties(crasis-experimental-benchmarks PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)
target_compile_options(crasis-experimental-benchmarks PUBLIC -std=c++1z)
add_test(NAME crasis-experimental-benchmarks COMMAND crasis-experimental-benchmarks)
