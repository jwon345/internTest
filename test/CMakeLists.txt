# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)

CPMAddPackage(
  NAME doctest
  GITHUB_REPOSITORY onqtam/doctest
  GIT_TAG v2.4.8
)

# ---- Create binary ----
file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
add_executable(test_commandstore ${sources})
target_link_libraries(test_commandstore doctest CommandStore)

if(MSVC)
  target_compile_definitions(test_commandstore PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
endif()

enable_testing()
add_test(test test_commandstore)

# Note: doctest and similar testing frameworks can automatically configure CMake tests For other
# testing frameworks add the tests target instead: ADD_TEST(test_commandstore test_commandstore)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(test_commandstore)

# ---- code coverage ----

if(ENABLE_TEST_COVERAGE)
  target_compile_options(CommandStore PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(CommandStore PUBLIC -fprofile-arcs -ftest-coverage)
endif()
