add_executable (dhtdaemon dhtdaemon.c)

set (CMAKE_C_FLAGS "-g")

LINK_DIRECTORIES (${CMAKE_BINARY_DIR}/library)

TARGET_LINK_LIBRARIES(dhtdaemon dhtsensor rt)
