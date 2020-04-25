

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Threads REQUIRED)

include_directories(..)

add_executable(UpdateVersion
    UpdateVersion.cpp
)

target_link_libraries(UpdateVersion Common Threads::Threads)
