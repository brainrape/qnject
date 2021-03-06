cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MACOSX_RPATH 1) 

# Coolest thing ever. used for vim autocompletion
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

# Allow double colon in library imports
cmake_policy(SET CMP0028 OLD)

project(qnject)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Use rpath always during build phase (otherwise tests will not work)
set(CMAKE_SKIP_BUILD_RPATH OFF)

# add -pthread switch when necessary
find_package(Threads REQUIRED)

# Find the Qt package
find_package(Qt5Core)
find_package(Qt5Widgets)

# We're using xxd to build .h files with static 
# string (json) contents
find_program(RESOURCE_COMPILER xxd)

# to validate swagger.json file we need the swagger-cli npm package
# -> if not found, we do validation using the public web services 
find_program(SWAGGER_CLI swagger)

if(NOT RESOURCE_COMPILER)
    message(FATAL_ERROR "You must have xxd in order to build qnject" )
endif()

configure_file(config.h.in config.h)

enable_testing()
add_subdirectory(vaccine)
