aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRCS)
add_library(static ${SRCS})
target_include_directories(static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})