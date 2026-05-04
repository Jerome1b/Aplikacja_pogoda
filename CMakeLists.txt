cmake_minimum_required(VERSION 3.10)
project(
    JsquareWeatherApp 
    VERSION 0.0.1 
    DESCRIPTION "Sample Linux VSCode/CMake Project"
    LANGUAGES CXX
)

# Wypisz nazwę oraz katalog główny projektu
message("Project_Name: ${PROJECT_NAME}")
message("Project_Dir: ${CMAKE_CURRENT_SOURCE_DIR}")  

# Opcje kompilatora
set(CMAKE_CXX_STANDARD 20) # Dodaj opcję '-std=c++20'
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug) # Dodaj opcję '-ggdb'

# Pliki źródłowe naszego przykładowego projektu
set(SOURCE 
    Localization.cpp
    Wind_Inf.cpp
)
add_executable(main ${SOURCE}) #  Jako wynik kompilacji podanych plików źródłowych ma być tworzony plik wykonywalny 'main' 
target_include_directories(main PUBLIC include) # Określamy katalogi, w których kompilator ma szukać plików nagłówkowych


include(CTest) 
find_package(GTest REQUIRED)
include(GoogleTest)
add_executable(test/"Lokalizacja Test")
add_executable(test/"Wind Test")
target_link_libraries("Localizacja Test" GTest::gtest_main)
target_link_libraries("Wind Test" GTest::gtest_main)
enable_testing()
gtest_discover_tests(lok)
gtest_discover_tests(Wind)