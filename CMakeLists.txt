# defines a projects structure and dependencies, very useful for scalability

cmake_minimum_required(VERSION 3.10)

project(UC_Addmission_Trends LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
src/csv_reader.cpp
src/database.cpp
src/main.cpp
src/university.cpp
)

add_executable(UC_Addmission_Trends ${SOURCES})

find_package(Matplot++ QUIET)

if(Matplot++_FOUND)
    message(STATUS "Matplot++ found!")
    target_link_libraries(UC_Addmission_Trends PUBLIC Matplot++)
    target_compile_definitions(UC_Addmission_Trends PRIVATE USE_MATPLOT)
else()
    message(WARNING "Matplot++ not found.")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(UC_Addmission_Trends PRIVATE -Wall -Wextra -pedantic)
endif()