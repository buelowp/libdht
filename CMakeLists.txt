cmake_minimum_required(VERSION 3.0)

project (dhtsensor)

add_library (dhtsensor SHARED bbb_dht_read.c bbb_mmio.c common_dht_read.c)

set (CMAKE_C_FLAGS "-std=gnu99")
set (CMAKE_SHARED_LINKER_FLAGS "-lrt")

install (TARGETS dhtsensor DESTINATION /usr/lib)
#install (FILES bbb_dht_read.h common_dht_read.h DESTINATION /usr/include)
