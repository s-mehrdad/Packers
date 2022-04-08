# *******************************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,13.04.2019</created>
#/ <changed>ʆϒʅ,05.12.2021</changed>
# *******************************************************************************************

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(TARGET_NAME Packers)

set(PROJECT_NAME ${TARGET_NAME})

#if(${CMAKE_SIZEOF_VOID_P} EQUAL "8")
#  set(CMAKE_GENERATOR_PLATFORM "x64")
#else()
#  set(CMAKE_GENERATOR_PLATFORM "x86")
#endif()

project(${PROJECT_NAME}
          VERSION 1.0.0.1
          DESCRIPTION "Packers Game in Console"
          HOMEPAGE_URL "https://github.com/BirdSofts/Packers"
          LANGUAGES CXX
)

if(MSVC)
  list(APPEND RESOURCES
    ${TARGET_NAME}.rc
    resource.h
    )
endif(MSVC)

list(APPEND HEADER_FILES
          Packers.h
          Area.h
          Console.h
          Infobars.h
          Menus.h
          Packer.h
          Shared.h
          Status.h
          Tale.h
)

list(APPEND SOURCE_FILES
          Packers.cpp
          Area.cpp
          Console.cpp
          Infobars.cpp
          Menus.cpp
          Packer.cpp
          Shared.cpp
          Status.cpp
          Tale.cpp
)

if(WIN32)
          list(APPEND SOURCE_FILES ${HEADER_FILES})
endif()

add_executable(${TARGET_NAME} ${SOURCE_FILES} ${RESOURCES})

if(MINGW)
  add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
    COMMAND cmake -E copy_if_different
    ${CMAKE_PREFIX_PATH}/bin/libgcc_s_seh-1.dll
    ${CMAKE_PREFIX_PATH}/bin/libstdc++-6.dll
    ${CMAKE_PREFIX_PATH}/bin/libwinpthread-1.dll
    $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endif(MINGW)
