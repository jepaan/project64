
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

set(RSP_SOURCE_FILES 
    alist.cpp
    alist_audio.cpp
    alist_naudio.cpp
    alist_nead.cpp
    audio.cpp
    cicx105.cpp
    hle.cpp
    jpeg.cpp
    main.cpp
    mem.cpp
    mp3.cpp
    musyx.cpp
    alist.h
    arithmetics.h
    audio.h
    common.h
    hle.h
    mem.h
    Rsp.h
    stdafx.h
    ucodes.h
    Version.h
)

include_directories(../..)
include_directories(.)

add_library(RSP MODULE ${RSP_SOURCE_FILES})
target_link_libraries(RSP Common Settings)
