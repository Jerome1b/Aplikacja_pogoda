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
    src/Localization.cpp
    src/Wind_inf.cpp
    src/ZapisDane.cpp
    src/Extract_data.cpp
    src/main.cpp
)
add_executable(main ${SOURCE}) #  Jako wynik kompilacji podanych plików źródłowych ma być tworzony plik wykonywalny 'main' 
target_include_directories(main PUBLIC include) # Określamy katalogi, w których kompilator ma szukać plików nagłówkowych
find_package(CURL REQUIRED)
target_link_libraries(main PUBLIC CURL::libcurl)
configure_file(.env ${CMAKE_CURRENT_BINARY_DIR}/.env COPYONLY) #Dodaliśmy plik .env aby nikt nie brał nam klucza api z githuba

include(CTest) 
find_package(GTest REQUIRED)
include(GoogleTest)
add_executable(Localization_test tests/Localization_test.cpp src/Localization.cpp)
add_executable(Wind_test tests/Wind_test.cpp src/Wind_inf.cpp)
target_include_directories(Localization_test PUBLIC include)
target_include_directories(Wind_test PUBLIC include)
target_link_libraries(Localization_test GTest::gtest_main)
target_link_libraries(Wind_test GTest::gtest_main)
enable_testing()
gtest_discover_tests(Localization_test)
gtest_discover_tests(Wind_test)
