cmake_minimum_required(VERSION 3.15)
project(ExchangeRates)

# Utiliser vcpkg comme toolchain
set(CMAKE_TOOLCHAIN_FILE "C:/Users/ndzan/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(CURL REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(ExchangeRates TauxDechange.cpp)

target_link_libraries(ExchangeRates PRIVATE CURL::libcurl nlohmann_json::nlohmann_json)
