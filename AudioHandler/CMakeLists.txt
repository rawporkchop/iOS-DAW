cmake_minimum_required(VERSION 3.29)

project(
    AudioHandler
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_OSX_DEPLOYMENT_TARGET "16.0")
set(CMAKE_OSX_ARCHITECTURES "arm64")


# CPM JUCE Package Manager
set(CPM_DOWNLOAD_VERSION 0.40.7)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if (NOT EXISTS ${CPM_DOWNLOAD_LOCATION})
    file(DOWNLOAD https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
    NAME juce
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 8.0.13
)


add_library(AudioHandlerEngine STATIC
    Engine/AudioEngine.cpp
    Engine/AudioEngine_C.cpp
)

target_compile_definitions(AudioHandlerEngine PUBLIC
    $<$<CONFIG:Debug>:DEBUG=1 JUCE_DEBUG=1>
)

target_include_directories(AudioHandlerEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine
)

target_link_libraries(AudioHandlerEngine PUBLIC
    juce::juce_core
    juce::juce_events
    juce::juce_audio_basics
    juce::juce_audio_devices
)
