INCLUDE (FindPkgConfig)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package (Threads)
find_package(ZLIB REQUIRED)
if (PKG_CONFIG_FOUND)
        PKG_CHECK_MODULES(UNZIP minizip)
endif (PKG_CONFIG_FOUND)
include_directories(..)

add_executable(Project64
    main.cpp
    UserInterface/notificationimplementation.cpp
    UserInterface/notificationimplementation.h
    UserInterface/mainwindow.cpp
    UserInterface/mainwindow.h
)

target_link_libraries(Project64 ${CMAKE_DL_LIBS} ${ZLIB_LIBRARY} ${UNZIP_LIBRARIES} Threads::Threads Qt5::Widgets Common Project64-core)
