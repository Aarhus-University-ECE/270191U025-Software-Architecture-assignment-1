cmake_minimum_required(VERSION 3.10)
project(template)
include(CTest)

# option(ENABLE_CPPCHECK "Run code analysis using cppcheck" OFF)
# option(ENABLE_CLANG_TIDY "Run code analysis using clang-tidy" OFF)
# option(ENABLE_STRICT "Compile in strict mode" OFF)

if(ENABLE_STRICT)
  if(MSVC)
    add_compile_options(/W4 /WX)
  else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
  endif()
endif()


# set include directory of all targets to the 'include' folder, this is similar
# to '-I include' in gcc
include_directories(include)

# define library called queue that can imported into other targets via
# 'target_link_libraries'
add_library(matlib src/my_math.cpp)

# define executable named main for experimenting and debugging code
add_executable(main src/main.cpp)

# tests are added by declaring a target, in this case 'tests'. additional tests
# can be added by expanding the test cases in 'src/tests.cpp' or an additional
# target via 'add_executable'
enable_testing()
add_executable(tests src/tests.cpp)
target_link_libraries(tests matlib)
add_test(usage_test tests)
