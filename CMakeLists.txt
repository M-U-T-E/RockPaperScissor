cmake_minimum_required(VERSION 3.22)

project(
    "RockPaperScissor"
    VERSION 1.0.0
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

set(ROCKPAPERSCISSOR "rockpaperscissor")
set(ROCKPAPERSCISSOR_SOURCES "main.cpp")

set(CONFIG_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")
configure_file(
    "config.hpp.in" "${CMAKE_BINARY_DIR}/configured_files/include/config.hpp"
    ESCAPE_QUOTES)

add_executable(${ROCKPAPERSCISSOR} ${ROCKPAPERSCISSOR_SOURCES})
target_include_directories(${ROCKPAPERSCISSOR} PUBLIC ${CONFIG_INCLUDES})
target_link_libraries(${ROCKPAPERSCISSOR} "-static-libstdc++" "-static-libgcc" "-static" "-lpthread")
# uninstall target
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()


install(TARGETS ${ROCKPAPERSCISSOR} DESTINATION bin)
install(FILES "${CMAKE_BINARY_DIR}/configured_files/include/config.hpp" DESTINATION include)

set(CPACK_PACKAGE_NAME ${ROCKPAPERSCISSOR})
set(CPACK_PACKAGE_CONTACT "MUTE<mamute2003ucp@gmail.com>")
set(CPACK_GENERATOR NSIS)
set(CPACK_NSIS_MODIFY_PATH ON)
include(CPack)