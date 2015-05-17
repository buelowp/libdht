cmake_minimum_required(VERSION 3.0)

project (dhtsensor)

include_directories ("${PROJECT_SOURCE_DIR}/library")
add_subdirectory (library)
add_subdirectory (examples)
