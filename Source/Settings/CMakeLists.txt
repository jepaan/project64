
set(SETTINGS_SOURCE_FILES 
    Settings.cpp
    Settings.h
)

include_directories(..)

add_library(Settings STATIC ${SETTINGS_SOURCE_FILES})
