# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

project( quickhull_any_dim_3 )


cmake_minimum_required(VERSION 2.8.11)

# CGAL and its components
find_package( CGAL QUIET COMPONENTS  )

if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()

# include helper file
include( ${CGAL_USE_FILE} )


# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )

  message(STATUS "This project requires the Boost library, and will not be compiled.")

  return()  

endif()

# include for local directory

# include for local package


# Creating entries for target: quickhull_any_dim_3
# ############################

add_executable( quickhull_any_dim_3  quickhull_any_dim_3.cpp )

add_to_cached_list( CGAL_EXECUTABLE_TARGETS quickhull_any_dim_3 )

# Link the executable to CGAL and third-party libraries
target_link_libraries(quickhull_any_dim_3   ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} )

