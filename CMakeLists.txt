cmake_minimum_required(VERSION 3.0.0)
project(taller VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(
    OpenCV REQUIRED
    )
include_directories(${OpenCV_INCLUDE_DIRS} include)

add_executable(
    taller
    src/Set.cpp
    src/Person.cpp
    src/CentroidTracker.cpp
    src/main.cpp
)

target_link_libraries(taller ${OpenCV_LIBS})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)