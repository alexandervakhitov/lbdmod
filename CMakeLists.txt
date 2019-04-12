cmake_minimum_required(VERSION 3.6)
project(lbd_mod)
set(CMAKE_CXX_STANDARD 11)
#-std=c++11 -fopenmp -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -Wno-comment -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -O3 -DNDEBUG  -fPIC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w  -O3 -march=native")
# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    add_definitions(-DCOMPILEDWITHC11)
    message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    add_definitions(-DCOMPILEDWITHC0X)
    message(STATUS "Using flag -std=c++0x.")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

find_package(OpenCV REQUIRED)

include_directories(
        ./include
        ${OpenCV_INCLUDE_DIRS}
)


set(SOURCE_FILES
        main.cpp
        src/binary_descriptor.cpp
        src/binary_descriptor_matcher.cpp
        src/LSDDetector.cpp
        src/LineExtractor.cc
        src/LinesConfigurator.cc
        src/LBDFloatLineMatcher.cc
        src/LLDLineMatcher.cc
        src/LBDFloatExtractor.cc
        src/LLDExtractor.cc
        src/StoredLineExtractor.cc
        src/EmptyExtractor.cc
        src/EmptyMatcher.cc
        src/LBDFLoatOnlineExtractor.cpp
        src/draw.cpp
        include/lbd_mod_funcs.h src/lbd_mod_funcs.cpp)
add_library(lbd_mod SHARED ${SOURCE_FILES})

target_link_libraries(lbd_mod
        opencv_core
        opencv_imgproc
        opencv_highgui
        opencv_imgcodecs
        )


add_executable(lbd_mod_test main.cpp)

target_link_libraries(lbd_mod_test
        lbd_mod
        opencv_core
        opencv_imgproc
        opencv_highgui
        opencv_imgcodecs
        )