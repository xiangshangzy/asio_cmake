set(Boost_LIB_DIR "F:/boost_1_85_0/stage/lib")
set(Boost_HDR_DIR "F:/boost_1_85_0")
#link_libraries(${Boost_LIB_DIR})
include_directories(${Boost_HDR_DIR})


add_executable(main main.cpp)
target_link_libraries(main static)
