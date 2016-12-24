cmake_minimum_required (VERSION 2.8)
project (2dmom)
find_package(VTK REQUIRED)
find_package(Armadillo REQUIRED)

include(${VTK_USE_FILE})
include_directories(${ARMADILLO_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/complex_bessel/include")
set(COMPLEX_BESSEL_LIB "${PROJECT_SOURCE_DIR}/complex_bessel/build/libcomplex_bessel.so")
set(SOURCES main.cpp cartesian.cpp mesh.cpp plot.cpp greens.cpp dielectric.cpp readmatlab.cpp)

add_executable(2dmom ${SOURCES})
target_link_libraries(2dmom ${VTK_LIBRARIES} ${ARMADILLO_LIBRARIES})
target_link_libraries(2dmom ${COMPLEX_BESSEL_LIB})


