cmake_minimum_required(VERSION 3.10)

# Keep MSVC hot-reload policy enabled if supported (no debug-format override).
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()

project("solid-ecommerce-order-system")

# Add sources (explicit, minimal)
add_executable(
  solid_ecommerce_order_system
  src/main.cpp
 "tests/test_main.cpp")

# Include dirs
target_include_directories(
  solid_ecommerce_order_system
  PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    C:/boost_1_90_0
)
