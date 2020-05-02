
#Update version
#Execute program with INFILE OUTFILE CURRENT_TAG

execute_process(COMMAND git describe --tags --long --dirty
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                OUTPUT_VARIABLE GIT_TAG
                ERROR_VARIABLE GIT_ERROR
                OUTPUT_STRIP_TRAILING_WHITESPACE
                )

set(UPDATE_VERSION_ARGUMENTS "Version.h.in" "Version.h" "${GIT_TAG}")
execute_process(COMMAND "${PROJECT_BINARY_DIR}/Source/UpdateVersion/UpdateVersion" ${UPDATE_VERSION_ARGUMENTS}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                OUTPUT_VARIABLE UPDATE_OUT)

set(AUDIO_SOURCE_FILES 
    AudioMain.cpp
    AudioSettings.cpp
    Driver/OpenSLES.cpp
    Driver/SoundBase.cpp
    trace.cpp
    AudioMain.h
    Audio_1.1.h
    AudioSettings.h
    Driver/OpenSLES.h
    Driver/SoundBase.h
    resource.h
    SettingsID.h
    trace.h
    Version.h
)

include_directories(..)
include_directories(.)

add_library(Project64-audio SHARED ${AUDIO_SOURCE_FILES})
target_link_libraries(Project64-audio Common Settings ${PNG_LIBRARY})
