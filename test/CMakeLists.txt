# Tests
set(CRASIS__EXPERIMENTAL_TESTS_SOURCES
  main.cpp
  test01-is-in-sparse-alphabet.cpp
  test02-is-in-range-alphabet.cpp
)
add_executable(crasis-experimental-tests ${CRASIS__EXPERIMENTAL_TESTS_SOURCES})

hunter_add_package(doctest)
find_package(doctest CONFIG REQUIRED)

target_link_libraries(crasis-experimental-tests doctest::doctest)
target_include_directories(crasis-experimental-tests
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../src/>
)
set_target_properties(crasis-experimental-tests PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)
target_compile_options(crasis-experimental-tests PUBLIC -std=c++1z)
add_test(NAME crasis-experimental-tests COMMAND crasis-experimental-tests -fc)
