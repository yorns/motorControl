cmake_minimum_required(VERSION 3.1.0)
project(motorControl VERSION 1.0 LANGUAGES CXX)

# in case we have a valid installation under /opt/boost, use that (ubuntu useses strange boost installation)
if(EXISTS /opt/boost/include/boost/function.hpp)
set(BOOST_ROOT /opt/boost)
endif()

if(EXISTS $ENV{OECORE_TARGET_SYSROOT}/usr/include/wiringPi.h )
SET(WORK_ON_PI 1)
endif()

set(MOTORCONTROL_SRC src/motor.cpp src/steeringControl.cpp src/motorControl.cpp)

find_package(Boost 1.53.0 REQUIRED COMPONENTS system thread)
find_package(Threads REQUIRED)

if (WORK_ON_PI EQUAL 1)
find_library(wiringpi_LIBRARIES NAMES wiringPi)
find_path(wiringpi_INCLUDE_DIRS NAMES wiringPi.h)
endif()

add_executable(motorControl ${MOTORCONTROL_SRC})
target_link_libraries(motorControl ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${wiringpi_LIBRARIES})
target_include_directories(motorControl PRIVATE ${Boost_INCLUDE_DIRS} ${wiringpi_INCLUDE_DIRS})
target_compile_definitions(motorControl PRIVATE WORK_ON_PI=${WORK_ON_PI})
set_target_properties(motorControl PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        )
