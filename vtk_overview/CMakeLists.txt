
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

PROJECT(VectorField)

# Need this to define VTK_VERSION
find_package(VTK)
if (NOT VTK_FOUND)
  message("Skipping VectorField: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  add_executable(VectorField MACOSX_BUNDLE VectorField.cxx )
  target_link_libraries(VectorField PRIVATE ${VTK_LIBRARIES})
else ()
  # include all components
  find_package(VTK COMPONENTS ${VTK_AVAILABLE_COMPONENTS})
  add_executable(overview MACOSX_BUNDLE overview.cxx )
  target_link_libraries(overview PRIVATE ${VTK_LIBRARIES})
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS overview
    MODULES ${VTK_LIBRARIES}
    )
endif () 
