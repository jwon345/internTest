cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# ---- Project ----

# Note: update this to your new project's name and version
project(
  CommandStore
  VERSION 1.0
  LANGUAGES CXX
)

include(CTest)
include(cmake/CPM.cmake)

set (CMAKE_CXX_STANDARD 23)

# ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# ---- Add source files ----

# Note: globbing sources is considered bad practice as CMake's generators may not detect new files
# automatically. Keep that in mind when changing files, or explicitly mention them here.
file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

# ---- Create library ----
add_library(CommandStore ${headers} ${sources})

# enable compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  target_compile_options(CommandStore PUBLIC -Wall -pedantic -Wextra -Werror)
elseif(MSVC)
  target_compile_options(CommandStore PUBLIC /W4 /WX)
endif()

target_include_directories(
  CommandStore 
    PUBLIC 
      ./include
)

add_subdirectory(test)