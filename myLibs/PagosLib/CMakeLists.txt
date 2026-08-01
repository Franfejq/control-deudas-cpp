add_library(PagosLib SHARED Src/frn_deuda.cpp)

target_include_directories(PagosLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

