cmake_minimum_required(VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()

project("solid-ecommerce-order-system")

# Collect all .cpp files in src/
file(GLOB SRC_ALL ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Remove main.cpp from the library sources
list(FILTER SRC_ALL EXCLUDE REGEX ".*main\\.cpp$")

# If no sources remain, create a dummy file
if(SRC_ALL STREQUAL "")
    file(WRITE ${CMAKE_BINARY_DIR}/dummy.cpp "// Dummy file for empty library\n")
    set(SRC_ALL ${CMAKE_BINARY_DIR}/dummy.cpp)
endif()

# Core library (all code except main.cpp)
add_library(solid_ecommerce_order_system_lib STATIC ${SRC_ALL})

target_include_directories(
  solid_ecommerce_order_system_lib
  PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    C:/boost_1_90_0
)

# App executable
add_executable(
  solid_ecommerce_order_system
  src/main.cpp
)

target_link_libraries(
  solid_ecommerce_order_system
  PRIVATE
    solid_ecommerce_order_system_lib
)

target_include_directories(
  solid_ecommerce_order_system
  PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    C:/boost_1_90_0
)

# Test executable
add_executable(
  tests
  tests/test_main.cpp
)

target_include_directories(
  tests
  PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    extern/googletest/googletest/include
)

target_link_libraries(
  tests
  PRIVATE
    gtest_main
    solid_ecommerce_order_system_lib
)

enable_testing()
add_test(NAME AllTests COMMAND tests)

