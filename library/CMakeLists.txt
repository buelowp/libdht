set (CMAKE_C_FLAGS "-std=gnu99 -g")
set (CMAKE_SHARED_LINKER_FLAGS "-lrt")

add_library (dhtsensor SHARED dht_read.c mmio.c common.c)
