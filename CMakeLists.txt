cmake_minimum_required(VERSION 3.1.0)
project(motorControl VERSION 1.0 LANGUAGES CXX)

# in case we have a valid installation under /opt/boost, use that (ubuntu useses strange boost installation)
if(EXISTS /opt/boost/include/boost/function.hpp)
set(BOOST_ROOT /opt/boost)
endif()

set(MOTORCONTROL_SRC src/motor.cpp src/steeringControl.cpp src/motorControl.cpp)

find_package(Boost 1.61.0 REQUIRED COMPONENTS system thread)
find_package(Threads REQUIRED)

find_library(wiringpi_LIBRARIES NAMES wiringPi)
find_path(wiringpi_INCLUDE_DIRS NAMES wiringPi.h)

find_library(snc_client_LIBRARIES NAMES snc_client)
find_path(snc_client_INCLUDE_DIRS NAMES snc/client.h)

add_executable(motorControl ${MOTORCONTROL_SRC})

if (${wiringpi_LIBRARIES} MATCHES ".*NOTFOUND")
  message("wiring pi not found - using dummy")
  target_link_libraries(motorControl ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${snc_client_LIBRARIES})
  target_include_directories(motorControl PRIVATE ${Boost_INCLUDE_DIRS} ${snc_client_INCLUDE_DIRS})
else()
  target_link_libraries(motorControl ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${wiringpi_LIBRARIES} ${snc_client_LIBRARIES})
  target_include_directories(motorControl PRIVATE ${Boost_INCLUDE_DIRS} ${wiringpi_INCLUDE_DIRS} ${snc_client_INCLUDE_DIRS})
  target_compile_definitions(motorControl PRIVATE WORK_ON_PI)
endif()

set_target_properties(motorControl PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        )
