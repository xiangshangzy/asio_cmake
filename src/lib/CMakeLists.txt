aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRCS)
add_library(lib ${SRCS})
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
