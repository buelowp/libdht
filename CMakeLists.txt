cmake_minimum_required(VERSION 3.0)

project (dhtsensor)

include_directories ("${PROJECT_SOURCE_DIR}/library")
add_subdirectory (library)
add_subdirectory (examples)

add_library (dhtsensor SHARED bbb_dht_read.c bbb_mmio.c common_dht_read.c)
add_executable (dhtdaemon examples/dhtdaemon.c)

set (CMAKE_C_FLAGS "-std=gnu99")
set (CMAKE_SHARED_LINKER_FLAGS "-lrt")

install (TARGETS dhtsensor DESTINATION /usr/lib)
install (FILES bbb_dht_read.h common_dht_read.h DESTINATION /usr/include)
