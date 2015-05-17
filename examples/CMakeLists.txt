add_executable (dhtdaemon dhtdaemon.c)

LINK_DIRECTORIES (${CMAKE_BINARY_DIR}/library)

TARGET_LINK_LIBRARIES(dhtdaemon dhtsensor)
