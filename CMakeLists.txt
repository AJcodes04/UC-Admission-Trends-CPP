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


set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};/usr/local")

find_package(Matplot++ QUIET)

if(Matplot++_FOUND)
    message(STATUS "Matplot++ found!")

    if(TARGET Matplot++::Matplot++)
        message(STATUS "Using Matplot++::Matplot++ target")
        target_link_libraries(UC_Addmission_Trends PUBLIC Matplot++::Matplot++)
    elseif(TARGET matplot++::matplot++)
        message(STATUS "Using matplot++::matplot++ target")
        target_link_libraries(UC_Addmission_Trends PUBLIC matplot++::matplot++)
    elseif(TARGET Matplot++)
        message(STATUS "Using Matplot++ target (no namespace)")
        target_link_libraries(UC_Addmission_Trends PUBLIC Matplot++)
    else()
        find_path(MATPLOT_INCLUDE_DIR matplot/matplot.h PATHS /usr/local/include /opt/matplotplusplus/include)
        if(MATPLOT_INCLUDE_DIR)
            message(STATUS "Matplot++ is header-only, adding include directory: ${MATPLOT_INCLUDE_DIR}")
            target_include_directories(UC_Addmission_Trends PUBLIC ${MATPLOT_INCLUDE_DIR})
        else()
            message(WARNING "Matplot++ found but headers not located. Trying to continue...")
        endif()
    endif()
    target_compile_definitions(UC_Addmission_Trends PRIVATE USE_MATPLOT)
else()
    message(WARNING "Matplot++ package not found. Trying to find headers directly...")
    find_path(MATPLOT_INCLUDE_DIR matplot/matplot.h PATHS /usr/local/include /opt/matplotplusplus/include)
    if(MATPLOT_INCLUDE_DIR)
        message(STATUS "Matplot++ headers found at ${MATPLOT_INCLUDE_DIR}")
        target_include_directories(UC_Addmission_Trends PUBLIC ${MATPLOT_INCLUDE_DIR})
        target_compile_definitions(UC_Addmission_Trends PRIVATE USE_MATPLOT)
    else()
        message(FATAL_ERROR "Matplot++ not found and cannot be located.")
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(UC_Addmission_Trends PRIVATE -Wall -Wextra -pedantic)
endif()