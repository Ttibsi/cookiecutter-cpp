include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/include)

# add_library(lib
#     # list cpp/hpp files here
# )

add_executable(${PROJECT_NAME}
    main.cpp
    # lib
)
