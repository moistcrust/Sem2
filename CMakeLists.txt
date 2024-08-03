cmake_minimum_required(VERSION 3.28)
project(game)

set(CMAKE_CXX_STANDARD 17)

# Add executable
add_executable(game
        main.cpp
        game.cpp
        game.h
        menu.cpp
        menu.h
        button.cpp
        button.h
)

# Set SFML directory
set(SFML_DIR C:/SFML/lib/cmake/SFML)

# Include SFML headers
include_directories(C:/SFML/include/SFML)

# Check the build type and set up conditional linking
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Set SFML static libraries
    set(SFML_STATIC_LIBRARIES TRUE)

    # Find SFML components for static linking
    find_package(SFML COMPONENTS graphics window system audio network REQUIRED)

    # Link SFML static libraries
    target_link_libraries(game sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

    # Set static linking flags
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
else()
    # Find SFML components for dynamic linking
    find_package(SFML COMPONENTS graphics window system audio network REQUIRED)

    # Link SFML dynamic libraries
    target_link_libraries(game sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

    # Ensure the SFML DLLs are found at runtime
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    add_custom_command(TARGET four POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SFML_DIR}/../../../bin $<TARGET_FILE_DIR:four>)
endif()
