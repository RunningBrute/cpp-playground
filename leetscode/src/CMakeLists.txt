file(GLOB SRC_FILES *.cpp)

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(TEST_NAME ${SRC_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${SRC_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain)
    include(Catch)
    catch_discover_tests(${TEST_NAME})
endforeach()