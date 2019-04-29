cmake_minimum_required(VERSION 2.8)
project(lbd_mod)

###============= C++11 support====================================
if(${CMAKE_VERSION} VERSION_LESS "3.1")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
    if (COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    elseif (COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    else ()
        message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif ()
else()
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()
#=================================================================
# PYTHON option
#Please set to your folders, taking my as examples
#Python 3 is supported here as well, if you customize the folders accordingly
set(PYTHON_DESIRED_VERSION "2.7" )
set(PYTHON_VERSION_MAJOR "2")
set(PYTHON_VERSION_MINOR "7")
set(PYTHON_INCLUDE_DIR "/home/vakhitov/anaconda3/envs/lld/include/python2.7/")
set(PYTHON_NUMPY_INCLUDE_DIRS "/home/vakhitov/anaconda3/envs/lld//lib/python2.7/site-packages/numpy/core/include/numpy/")
set(PYTHON_LIBRARY "python2.7")
set(PYTHON_EXECUTABLE "python")
set(PYTHON_PACKAGES_PATH "/home/vakhitov/anaconda3/envs/lld/lib/python2.7/site-packages/")
#=============== Find Packages ====================================
## OpenCV
find_package(OpenCV COMPONENTS core imgproc highgui imgcodecs REQUIRED)
## Boost
if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    # Provisions for typical Boost compiled on Windows
    # Most commonly, Boost libraries are compiled statically on windows (change as necesssary)
    set(Boost_USE_STATIC_LIBS TRUE)
    set(Boost_USE_STATIC_RUNTIME OFF)
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_DEBUG_RUNTIME ON)
    set(Boost_USE_DEBUG_PYTHON OFF)
endif()
set(Python_ADDITIONAL_VERSIONS ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR})
find_package(Boost COMPONENTS python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR} QUIET)
if(NOT Boost_FOUND)
    message(STATUS "Trying alternative Boost.Python component name, python-py<version>...")
    find_package(Boost COMPONENTS python-py${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR} REQUIRED)
endif()

include_directories(./include)

file(GLOB lbdlib_sources
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
        src/lbd_mod_funcs.cpp)

add_library(lbd_mod SHARED ${lbdlib_sources})

target_link_libraries(lbd_mod
        ${OpenCV_LIBRARIES})

add_executable(lbd_mod_test main.cpp)

target_link_libraries(lbd_mod_test
        lbd_mod
        ${OpenCV_LIBRARIES})

#========pick python stuff========================================
set(PYTHON_INCLUDE_DIRS ${PYTHON_INCLUDE_DIR} ${PYTHON_INCLUDE_DIR2} ${PYTHON_NUMPY_INCLUDE_DIRS})
set(PYTHON_NUMPY_INCLUDE_DIRS ${PYTHON_NUMPY_INCLUDE_DIRS})
set(PYTHON_LIBRARIES ${PYTHON_LIBRARY})
set(PYTHON_EXECUTABLE ${PYTHON_EXECUTABLE})
set(PYTHON_PACKAGES_PATH ${PYTHON_PACKAGES_PATH})
set(ARCHIVE_OUTPUT_NAME pylbd)

find_package_handle_standard_args(Python DEFAULT_MSG PYTHON_INCLUDE_DIRS PYTHON_NUMPY_INCLUDE_DIRS PYTHON_LIBRARIES PYTHON_EXECUTABLE PYTHON_PACKAGES_PATH)
if(NOT Python_FOUND)
    message(SEND_ERROR "Not all requred components of Numpy/Python found.")
endif()

set(PYPROJECT_NAME pylbd)

file(GLOB project_sources src/pyboost_cv2_converter.cpp src/pyboost_cv3_converter.cpp src/pyboost_cv4_converter.cpp src/python_module.cpp src/dataconv.cpp )

add_library(pylbd SHARED ${project_sources} ${lbdlib_sources})
target_include_directories(${PYPROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        ${Boost_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS}
        ${LBD_MOD_INCLUDE}
        )

target_link_libraries(${PYPROJECT_NAME}
        ${Boost_LIBRARIES}
        ${OpenCV_LIBRARIES}
        ${PYTHON_LIBRARIES}
        )

if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    # Provisions for typical Boost compiled on Windows
    # Unless some extra compile options are used on Windows, the libraries won't have prefixes (change as necesssary)
    target_compile_definitions(${PYPROJECT_NAME} PUBLIC -DBOOST_ALL_NO_LIB -DBOOST_SYSTEM_NO_DEPRECATED)
endif()

#---------------------------   INSTALLATION    -----------------------------------------------------
#-get proper extension for python binary shared object on this platform

set(__python_ext_suffix_var "EXT_SUFFIX")
if(${PYTHON_DESIRED_VERSION} STREQUAL "2.X")
    set(__python_ext_suffix_var "SO")
endif()

execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "import distutils.sysconfig; print(distutils.sysconfig.get_config_var('${__python_ext_suffix_var}'))"
        RESULT_VARIABLE PYTHON_${PYPROJECT_NAME}_PY_PROCESS
        OUTPUT_VARIABLE ${PYPROJECT_NAME}_PY_SUFFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE)
if(NOT ${PYTHON_${PYPROJECT_NAME}_PY_PROCESS} EQUAL 0)
    set(${PYPROJECT_NAME}_PY_SUFFIX ".so")
endif()

set(${PYPROJECT_NAME}_PY_SUFFIX ".so")


set_target_properties(${PYPROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME ${ARCHIVE_OUTPUT_NAME}
        PREFIX ""
        OUTPUT_NAME pylbd
        SUFFIX ${${PYPROJECT_NAME}_PY_SUFFIX})



if (MSVC AND NOT PYTHON_DEBUG_LIBRARIES)
    set(PYTHON_INSTALL_CONFIGURATIONS CONFIGURATIONS Release)
else ()
    set(PYTHON_INSTALL_CONFIGURATIONS "")
endif ()

if (WIN32)
    set(PYTHON_INSTALL_ARCHIVE "")
else ()
    set(PYTHON_INSTALL_ARCHIVE ARCHIVE DESTINATION ${PYTHON_PACKAGES_PATH} COMPONENT python)
endif ()

install(TARGETS ${PYPROJECT_NAME}
        ${PYTHON_INSTALL_CONFIGURATIONS}
        RUNTIME DESTINATION ${PYTHON_PACKAGES_PATH} COMPONENT python
        LIBRARY DESTINATION ${PYTHON_PACKAGES_PATH} COMPONENT python
        ${PYTHON_INSTALL_ARCHIVE}
        )
