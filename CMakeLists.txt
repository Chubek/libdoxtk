cmake_minimum_required(VERSION 3.20)
project(DoxTk VERSION 0.1.0 LANGUAGES CXX)

option(DOXTK_BUILD_TESTS "Build DoxTk tests" ON)
option(DOXTK_BUILD_TOOLS "Build command-line tools" ON)
option(DOXTK_ENABLE_LUA "Build Lua integration (requires Lua and binding dependencies)" OFF)
option(DOXTK_ENABLE_PDF "Build PDF output integration (requires libharu)" OFF)
option(DOXTK_ENABLE_XML "Enable pugixml-backed XML integration" OFF)
option(DOXTK_ENABLE_YAML "Enable yaml-cpp-backed YAML integration" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(doxtk
    src/DoxTk.cpp
    src/DoxTkAST.cpp
    src/DoxTkBinfile.cpp
    src/DoxTkBytecode.cpp
    src/DoxTkBytestream.cpp
    src/DoxTkCLI.cpp
    src/DoxTkCompiler.cpp
    src/DoxTkConfig.cpp
    src/DoxTkDeserializer.cpp
    src/DoxTkDriver.cpp
    src/DoxTkEncoding.cpp
    src/DoxTkEventStream.cpp
    src/DoxTkIO.cpp
    src/DoxTkIPC.cpp
    src/DoxTkLexer.cpp
    src/DoxTkListener.cpp
    src/DoxTkLua.cpp
    src/DoxTkPDFWriter.cpp
    src/DoxTkParser.cpp
    src/DoxTkSerializer.cpp
    src/DoxTkSpecFile.cpp
    src/DoxTkTooling.cpp
    src/DoxTkTranslator.cpp
    src/DoxTkTxtfile.cpp
    src/DoxTkVisitor.cpp
    src/DoxTkXML.cpp
)
add_library(DoxTk::DoxTk ALIAS doxtk)
target_include_directories(doxtk PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_compile_features(doxtk PUBLIC cxx_std_20)
if(MSVC)
  target_compile_options(doxtk PRIVATE /W4 /permissive-)
else()
  target_compile_options(doxtk PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(DOXTK_ENABLE_LUA)
  message(FATAL_ERROR "DOXTK_ENABLE_LUA is scaffold-only: provide and wire Lua/Kaguya before enabling.")
endif()
if(DOXTK_ENABLE_PDF)
  message(FATAL_ERROR "DOXTK_ENABLE_PDF is scaffold-only: provide and wire libharu before enabling.")
endif()
if(DOXTK_ENABLE_XML)
  message(FATAL_ERROR "DOXTK_ENABLE_XML is scaffold-only: provide and wire pugixml before enabling.")
endif()
if(DOXTK_ENABLE_YAML)
  message(FATAL_ERROR "DOXTK_ENABLE_YAML is scaffold-only: provide and wire yaml-cpp before enabling.")
endif()

if(DOXTK_BUILD_TOOLS)
  add_subdirectory(toolchain)
endif()
if(DOXTK_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

include(GNUInstallDirs)
install(TARGETS doxtk EXPORT DoxTkTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT DoxTkTargets NAMESPACE DoxTk:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DoxTk)
