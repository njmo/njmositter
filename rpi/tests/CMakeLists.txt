PROJECT(tests)
add_definitions("-std=c++14 -Ofast -fPIC")

include_directories("${PROJECT_SOURCE_DIR}/../application/")

add_subdirectory(googletest)

AUX_SOURCE_DIRECTORY("${PROJECT_SOURCE_DIR}/OtherBasicTest" OtherBasicTest_SOURCES)
AUX_SOURCE_DIRECTORY("${PROJECT_SOURCE_DIR}/event" TestEvent_SOURCES)
AUX_SOURCE_DIRECTORY("${PROJECT_SOURCE_DIR}/OtherOtherBasicTest" OtherOtherBasicTest_SOURCES)

ADD_EXECUTABLE("${PROJECT_NAME}" "testMain.cpp" ${TestEvent_SOURCES} ${OtherBasicTest_SOURCES} ${OtherOtherBasicTest_SOURCES})
target_link_libraries("${PROJECT_NAME}" PRIVATE gmock gmock_main) 
target_link_libraries("${PROJECT_NAME}" LINK_PUBLIC testLibrary)
target_link_libraries("${PROJECT_NAME}" LINK_PUBLIC event_machine)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}" "${gmock_SOURCE_DIR}/include" "${gtest_SOURCE_DIR}/include")