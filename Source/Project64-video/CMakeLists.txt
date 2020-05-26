
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

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIR})

#Bit wonky but to allow the relative includes in source like png/png.h
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/png)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/png/png.h "#include <png.h>")
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/zlib)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/zlib/zlib.h "#include <zlib.h>")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(VIDEO_SOURCE_FILES 
    F3DTEXA.h
    Gfx_1.3.h
    Renderer/glitchmain.h
    Renderer/Renderer.h
    Renderer/types.h
    ScreenResolution.h
    Settings.h
    SettingsID.h
    TextureEnhancer/Ext_TxFilter.h
    TextureEnhancer/tc-1.1+/dxtn.h
    TextureEnhancer/tc-1.1+/fxt1.h
    TextureEnhancer/tc-1.1+/internal.h
    TextureEnhancer/tc-1.1+/types.h
    TextureEnhancer/TextureFilters.h
    TextureEnhancer/TextureFilters_2xsai.h
    TextureEnhancer/TextureFilters_hq2x.h
    TextureEnhancer/TextureFilters_hq4x.h
    TextureEnhancer/TextureFilters_lq2x.h
    TextureEnhancer/TxCache.h
    TextureEnhancer/TxDbg.h
    TextureEnhancer/TxFilter.h
    TextureEnhancer/TxHiResCache.h
    TextureEnhancer/TxImage.h
    TextureEnhancer/TxInternal.h
    TextureEnhancer/TxQuantize.h
    TextureEnhancer/TxReSample.h
    TextureEnhancer/TxTexCache.h
    TextureEnhancer/TxUtil.h
    trace.h
    turbo3D.h
    ucode.h
    ucode00.h
    ucode01.h
    ucode02.h
    ucode03.h
    ucode04.h
    ucode05.h
    ucode06.h
    ucode07.h
    ucode08.h
    ucode09.h
    ucode09rdp.h
    ucodeFB.h
    CRC.h
    MiClWr16b.h
    MiClWr32b.h
    MiClWr8b.h
    TexCache.h
    TexConv.h
    TexLoad.h
    TexLoad16b.h
    TexLoad32b.h
    TexLoad4b.h
    TexLoad8b.h
    TexMod.h
    TexModCI.h
    Config.h
    cursor.h
    font.h
    resource.h
    3dmath.h
    Combine.h
    Debugger.h
    DepthBufferRender.h
    Ext_TxFilter.h
    FBtoScreen.h
    rdp.h
    TexBuffer.h
    Util.h
    Version.h
    Renderer/OGLgeometry.cpp
    Renderer/OGLglitchmain.cpp
    Renderer/OGLtextures.cpp
    Renderer/Renderer.cpp
    ScreenResolution.cpp
    Settings.cpp
    TexCache.cpp
    Config.cpp
    3dmath.cpp
    Combine.cpp
    Debugger.cpp
    DepthBufferRender.cpp
    Ext_TxFilter.cpp
    FBtoScreen.cpp
    Main.cpp
    rdp.cpp
    TexBuffer.cpp
    TextureEnhancer/tc-1.1+/dxtn.c
    TextureEnhancer/tc-1.1+/fxt1.c
    TextureEnhancer/tc-1.1+/texstore.c
    TextureEnhancer/tc-1.1+/wrapper.c
    TextureEnhancer/TextureFilters.cpp
    TextureEnhancer/TextureFilters_2xsai.cpp
    TextureEnhancer/TextureFilters_hq2x.cpp
    TextureEnhancer/TextureFilters_hq4x.cpp
    TextureEnhancer/TxCache.cpp
    TextureEnhancer/TxDbg.cpp
    TextureEnhancer/TxFilter.cpp
    TextureEnhancer/TxFilterExport.cpp
    TextureEnhancer/TxHiResCache.cpp
    TextureEnhancer/TxImage.cpp
    TextureEnhancer/TxQuantize.cpp
    TextureEnhancer/TxReSample.cpp
    TextureEnhancer/TxTexCache.cpp
    TextureEnhancer/TxUtil.cpp
    trace.cpp
    turbo3D.cpp
    ucode.cpp
    ucode00.cpp
    ucode01.cpp
    ucode02.cpp
    ucode03.cpp
    ucode04.cpp
    ucode05.cpp
    ucode06.cpp
    ucode07.cpp
    ucode08.cpp
    ucode09.cpp
    ucode09rdp.cpp
    ucodeFB.cpp
    Util.cpp
    CRC.cpp
    F3DTEXA.cpp
    Renderer/OGLcombiner.cpp
)

include_directories(..)
include_directories(.)

add_library(Project64-video MODULE ${VIDEO_SOURCE_FILES})
target_link_libraries(Project64-video Common Settings ${PNG_LIBRARY})
