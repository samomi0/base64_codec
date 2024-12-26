add_executable(test test.cpp)
target_link_libraries(test ${OUTPUT_LIB_NAME}_shared gtest::gtest)