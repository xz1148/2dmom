cmake_minimum_required (VERSION 2.6)
project (2dmom)
add_executable(2dmom main.cpp cartesian.cpp mesh.cpp)
target_link_libraries(2dmom complex_bessel)
