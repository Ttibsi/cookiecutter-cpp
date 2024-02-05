include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/include)

include(FetchContent)
{% if cookiecutter.test_framework == "gtest" -%}
fetchcontent_declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
fetchcontent_makeavailable(googletest)
include(GoogleTest)

add_library(GTest INTERFACE IMPORTED)
target_link_libraries(GTest INTERFACE gtest_main)
{% elif cookiecutter.test_framework == "catch2" -%}
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)

FetchContent_MakeAvailable(Catch2)
{% endif -%}

add_executable(test_exe
    # test files here
    main.cpp
)

{% if cookiecutter.test_framework == "gtest" -%}
target_link_libraries(test_exe PRIVATE lib GTest)
{% elif cookiecutter.test_framework == "catch2" -%}
target_link_libraries(test_exe PRIVATE lib Catch2::Catch2WithMain)
{% endif -%}
gtest_discover_tests(test_exe)
