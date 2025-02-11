# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(RpiLoadTransportClientApp)

# Find Qt5 (make sure the Qt path is set correctly)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Set the C++ standard to C++11 or later
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(grpc)
include_directories(grpc)

# Create an executable from the source files
add_executable(RpiLoadTransportClientApp main.cpp main-window.cpp automatic-mode-window.cpp manual-mode-window.cpp all-windows-commons.cpp)
add_dependencies(RpiLoadTransportClientApp GrpcClientLib)

# Link the Qt5 Core library
target_link_libraries(RpiLoadTransportClientApp Qt5::Core Qt5::Gui Qt5::Widgets GrpcClientLib)