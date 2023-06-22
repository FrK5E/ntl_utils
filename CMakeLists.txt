# stop if cmake version is below 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project name and enable C++ support
project(ntl_utils LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)


add_library( ntl SHARED IMPORTED )
set_property( TARGET ntl PROPERTY IMPORTED_LOCATION /home/peta/ntl/lib/libntl.so ) 
target_include_directories( ntl INTERFACE /home/peta/ntl/include )



# we define the executable
add_library(ntl_utils SHARED src/utils.cpp )
target_link_libraries( ntl_utils PRIVATE ntl )
target_include_directories( ntl_utils PUBLIC include )

add_executable( test test/test.cpp  )
#target_link_libraries( test PRIVATE ntl )
target_link_libraries(test PRIVATE
                    ntl_utils ntl
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )





