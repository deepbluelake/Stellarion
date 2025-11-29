cmake_minimum_required(VERSION 3.10)
project(Stellarion)

set(CMAKE_CXX_STANDARD 17)

# Include folder for headers
include_directories(include)

# Download nlohmann/json single header file
include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp
    DOWNLOAD_NO_EXTRACT TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

# Get the source directory where the header was downloaded
FetchContent_GetProperties(nlohmann_json)
if(NOT nlohmann_json_POPULATED)
    FetchContent_Populate(nlohmann_json)
endif()

# Create nlohmann subdirectory and copy/move the header there
file(MAKE_DIRECTORY ${nlohmann_json_SOURCE_DIR}/nlohmann)
file(COPY ${nlohmann_json_SOURCE_DIR}/json.hpp 
     DESTINATION ${nlohmann_json_SOURCE_DIR}/nlohmann)

# Create interface library for nlohmann_json
add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE ${nlohmann_json_SOURCE_DIR})

# Collect all cpp files from src/ (exclude experimental files)
file(GLOB SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/littleExperiments.cpp")

add_executable(stellarion ${SOURCES})
target_link_libraries(stellarion nlohmann_json)
