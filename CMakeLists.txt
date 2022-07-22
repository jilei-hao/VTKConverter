cmake_minimum_required(VERSION 3.5)

project(VTKConverter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(VTK REQUIRED COMPONENTS
  IOLegacy
)

add_executable(VTKConverter main.cpp)
target_link_libraries(VTKConverter ${VTK_LIBRARIES})

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS VTKConverter
  MODULES ${VTK_LIBRARIES}
)
