cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

PROJECT(ScatterPlot)

# Need this to define VTK_VERSION
find_package(VTK)
if (NOT VTK_FOUND)
  message("Skipping ScatterPlot: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  add_executable(ScatterPlot MACOSX_BUNDLE ScatterPlot.cxx )
  target_link_libraries(ScatterPlot PRIVATE ${VTK_LIBRARIES})
else ()
  # include all components
  find_package(VTK COMPONENTS ${VTK_AVAILABLE_COMPONENTS})
  add_executable(ScatterPlot MACOSX_BUNDLE ScatterPlot.cxx )
  target_link_libraries(ScatterPlot PRIVATE ${VTK_LIBRARIES})
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS ScatterPlot
    MODULES ${VTK_LIBRARIES}
    )
endif () 
