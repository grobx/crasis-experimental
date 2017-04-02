set(CRASIS__EXPERIMENTAL_INCLUDES
    crasis/experimental/is.hpp
    crasis/experimental/length.hpp
)
add_library(crasis-experimental_objs OBJECT ${CRASIS__EXPERIMENTAL_INCLUDES})
set_target_properties(crasis-experimental_objs PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)
target_compile_options(crasis-experimental_objs PUBLIC -std=c++1z)
target_include_directories(crasis-experimental_objs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(crasis-experimental_interface INTERFACE)
target_compile_definitions(crasis-experimental_interface INTERFACE
    LIBRARY_HEADER_ONLY
)
target_link_libraries(crasis-experimental_interface INTERFACE crasis-experimental_objs)
