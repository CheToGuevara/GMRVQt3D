SET(SOURCES
  main.cpp
  mainwindow.cpp

)

SET(HEADERS
 mainwindow.h
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Fix linkage problem with windows and cross-compilation #######################
IF (WIN32)
    SET (CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -lwinmm")
ENDIF (WIN32)


FILE(GLOB ui "*.ui")
qt5_wrap_ui(HDR_UI ${ui})




# Create the main program ######################################################
add_executable(Qt3DEditor ${SOURCES} ${HEADERS} ${HDR_UI})
target_link_libraries(Qt3DEditor GMRVQt3DCore  )
target_include_directories(Qt3DEditor PUBLIC GMRVQt3DCore )
qt5_use_modules(Qt3DEditor Core Gui Widgets 3DCore 3DExtras 3DRender 3DInput)