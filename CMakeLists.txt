# *******************************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,13.04.2019</created>
#/ <changed>ʆϒʅ,21.08.2019</changed>
# *******************************************************************************************

# CMakeList.txt : CMake project for Packers, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(TARGET_NAME Packers)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
          VERSION 1.0.0.1
          DESCRIPTION "Packers Game in Console"
          HOMEPAGE_URL "https://github.com/BirdSofts/Packers"
          LANGUAGES CXX
)

list(APPEND RESOURCES
          ${TARGET_NAME}.rc
          resource.h
)

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

# Add source to this project's executable.
add_executable(${TARGET_NAME} ${SOURCE_FILES} ${RESOURCES})

# TODO: Add tests and install targets if needed.
