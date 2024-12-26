add_library(${OUTPUT_LIB_NAME}_shared SHARED base64.cpp)
set_target_properties(${OUTPUT_LIB_NAME}_shared PROPERTIES OUTPUT_NAME ${OUTPUT_LIB_NAME})
set_target_properties(${OUTPUT_LIB_NAME}_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

add_library(${OUTPUT_LIB_NAME}_static STATIC base64.cpp)
set_target_properties(${OUTPUT_LIB_NAME}_static PROPERTIES OUTPUT_NAME ${OUTPUT_LIB_NAME})
set_target_properties(${OUTPUT_LIB_NAME}_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)