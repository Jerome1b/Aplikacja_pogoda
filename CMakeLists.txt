cmake_minimum_required(VERSION 3.14) # Zalecane 3.14+ dla FetchContent
project(
    JsquareWeatherApp 
    VERSION 0.0.1 
    DESCRIPTION "Sample Linux VSCode/CMake Project"
    LANGUAGES CXX
)

message("Project_Name: ${PROJECT_NAME}")
message("Project_Dir: ${CMAKE_CURRENT_SOURCE_DIR}")  

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
# Automatyczne przetwarzanie plików Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(CURL REQUIRED)
find_package(GTest REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets Charts WebEngineWidgets)
set(SOURCE 
    src/Localization.cpp
    src/Wind_inf.cpp
    src/Icon.cpp
    src/Extract_Data_Mock.cpp
    src/main.cpp
    src/ZapisDane.cpp
    src/Extract_Wykres.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    include/app.hpp
    src/weatherwindow.cpp
    include/weatherwindow.h
    src/weatherwindow.ui
)

add_executable(main ${SOURCE})
target_include_directories(main PUBLIC include)
target_link_libraries(main 
    PUBLIC 
        CURL::libcurl
        nlohmann_json::nlohmann_json
        Qt6::Widgets                  
        Qt6::Charts
        Qt6::WebEngineWidgets
)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/.env" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

#TUTAJ ZACZYNAMY TESTOWAĆ
enable_testing()
include(CTest)

#add_executable(Localization_test tests/Test_Localization.cpp src/Localization.cpp)
#add_executable(Wind_test tests/Wind_test.cpp src/Wind_inf.cpp)
#add_executable(EXD_test tests/test_mock.cpp src/Extract_Data_Mock.cpp src/ZapisDane.cpp)
#add_executable(EXW_test tests/test_mock_wyk.cpp src/Extract_Wykres.cpp src/ZapisDane.cpp src/Extract_Data_Mock.cpp )
#target_include_directories(Localization_test PUBLIC include)
#target_include_directories(Wind_test PUBLIC include)
#target_include_directories(EXD_test PUBLIC include)
#target_include_directories(EXW_test PUBLIC include)
#target_link_libraries(Localization_test PRIVATE gtest_main)
#target_link_libraries(Wind_test PRIVATE gtest_main)
#target_link_libraries(EXD_test
#    PRIVATE
#        gmock_main
#        CURL::libcurl
#        nlohmann_json::nlohmann_json
#)
#target_link_libraries(EXW_test
#    PRIVATE
#        gmock_main
#        CURL::libcurl
#        nlohmann_json::nlohmann_json
#)

#gtest_discover_tests(Localization_test)
#gtest_discover_tests(Wind_test)
#gtest_discover_tests(EXD_test)
