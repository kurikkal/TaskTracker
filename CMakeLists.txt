cmake_minimum_required(VERSION 3.10)
project(TaskTracker VERSION 1.0.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Collect all source files
file(GLOB SOURCES "src/*.cpp")

# Build executable
add_executable(tasktracker ${SOURCES})

# -----------------------------
# Install rules
# -----------------------------
# Executable goes to /usr/local/bin
install(TARGETS tasktracker
        RUNTIME DESTINATION bin)

# Headers go to /usr/local/include
install(DIRECTORY include/ DESTINATION include)

# -----------------------------
# CPack configuration
# -----------------------------
set(CPACK_PACKAGE_NAME "TaskTracker")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "yadun.kurikalveed@example.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple task tracker in C++")

# DEB-specific metadata
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Yadun Kurikalveed <yadun.kurikalveed@example.com>")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")  # Add dependencies if needed
# Make DEB the default package type
set(CPACK_GENERATOR "DEB")


include(CPack)
