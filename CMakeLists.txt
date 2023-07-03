# ============================================================================
# / <summary>
# / CMakeLists.txt
# / Packers
# / created by Mehrdad Soleimanimajd on 13.04.2019
# / </summary>
# / <created>ʆϒʅ, 13.04.2019</created>
# / <changed>ʆϒʅ, 03.07.2023</changed>
# ============================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(TARGET_NAME Packers)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
  VERSION 1.0.4.0
  DESCRIPTION "Packers Game"
  HOMEPAGE_URL "https://github.com/s-mehrdad/Packers"
  LANGUAGES CXX
)

set(VerCompanyName "BirdSofts")
set(VerFileDescription "Packers Game")
set(VerFileVersion "1,0,4,0")
set(VerInternalName ${TARGET_NAME})
set(VerLegalCopyright "Copyright (C) 2018-2023")
set(VerLegalTrademarks1 "BS")
set(VerLegalTrademarks2 "BSs")
set(VerOriginalFilename ${TARGET_NAME})
set(VerProductName ${TARGET_NAME})
set(VerProductVersion ${CMAKE_PROJECT_VERSION})

set(VerProjectType VFT_APP)

configure_file(
  Packers.rc.in
  Packers.rc
  @ONLY
  NEWLINE_STYLE LF
)

list(APPEND RESOURCES
  ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.rc
  resource.h
)

list(APPEND HEADER_FILES
  Area.h
  GameElements.h
  Infobars.h
  Input.h
  Menus.h
  Packer.h
  Packers.h
  Shared.h
  Status.h
  Tale.h
  View.h
)

list(APPEND SOURCE_FILES
  Area.cpp
  GameElements.cpp
  Infobars.cpp
  Input.cpp
  Menus.cpp
  Packer.cpp
  Packers.cpp
  Shared.cpp
  Status.cpp
  Tale.cpp
  View.cpp
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
