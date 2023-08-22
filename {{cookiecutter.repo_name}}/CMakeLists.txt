cmake_minimum_required(VERSION 3.14.0)
project({{cookiecutter.exec_name}} CXX {{cookiecutter.version}})
{% if cookiecutter.tests -%}
option(RUN_TESTS "Run unit tests" ON)
{% endif -%}
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall)
add_compile_options(-Wextra)

add_subdirectory(src)

{% if cookiecutter.tests -%}
if(RUN_TESTS)
    enable_testing()
    message(STATUS "UNIT TESTS ENABLED")
    add_subdirectory(tests)
endif()
{% endif -%}
