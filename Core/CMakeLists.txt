SET(SOURCES
	scenemodifier.cpp
)

SET(HEADERS
	scenemodifier.h
)
FILE(GLOB_RECURSE SHADERS
    ${CMAKE_CURRENT_DIR} shaders/*.[a-z]*)
	
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_library(GMRVQt3DCore ${SOURCES} ${HEADERS} ${SHADERS})
target_include_directories(GMRVQt3DCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

qt5_use_modules(GMRVQt3DCore Core Gui Widgets 3DCore 3DExtras 3DRender 3DInput)