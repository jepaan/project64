
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(COMMON_SOURCE_FILES 
    CriticalSection.cpp
    DateTimeClass.cpp
    FileClass.cpp
    HighResTimeStamp.cpp
    IniFileClass.cpp
    LogClass.cpp
    md5.cpp
    MemoryManagement.cpp
    MemTest.cpp
    path.cpp
    Platform.cpp
    Random.cpp
    StdString.cpp
    SyncEvent.cpp
    Thread.cpp
    Trace.cpp
    Util.cpp
    CriticalSection.h
    DateTimeClass.h
    FileClass.h
    HighResTimeStamp.h
    IniFileClass.h
    LogClass.h
    md5.h
    MemoryManagement.h
    MemTest.h
    path.h
    Platform.h
    Random.h
    SmartPointer.h
    StdString.h
    stdtypes.h
    SyncEvent.h
    Thread.h
    Trace.h
    TraceModulesCommon.h
    Util.h
)

include_directories(..)

add_library(Common STATIC ${COMMON_SOURCE_FILES})
