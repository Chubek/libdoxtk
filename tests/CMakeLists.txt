add_executable(doxtk_tests test_core.cpp)
target_link_libraries(doxtk_tests PRIVATE DoxTk::DoxTk)
add_test(NAME doxtk_core COMMAND doxtk_tests)
