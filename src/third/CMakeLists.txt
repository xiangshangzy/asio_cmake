set(Boost_LIB_DIR "F:/boost_1_85_0/stage/lib")
set(Boost_HDR_DIR "F:/boost_1_85_0")

file(GLOB LIBS "${Boost_LIB_DIR}/libboost*.a")
target_include_directories(static PUBLIC ${Boost_HDR_DIR})
target_link_libraries(static ${LIBS})