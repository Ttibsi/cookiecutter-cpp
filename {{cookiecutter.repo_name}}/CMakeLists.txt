cmake_minimum_required(VERSION 3.22.0)
project({{cookiecutter.exec_name}} LANGUAGES CXX VERSION {{cookiecutter.version}})
{% if cookiecutter.tests -%}
option(RUN_TESTS "Run unit tests" ON)
{% endif -%}
set(CMAKE_CXX_STANDARD {{cookiecutter.cpp_standard}})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall)
if (NOT WIN32)
    add_compile_options(-Wextra)
endif()

add_subdirectory(src)

{% if cookiecutter.tests -%}
if(RUN_TESTS)
    enable_testing()
    message(STATUS "UNIT TESTS ENABLED")
    add_subdirectory(tests)
endif()
{% endif -%}
