cmake_minimum_required(VERSION 4.0.0)

project($ENV{TARGET_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set(CMAKE_BUILD_TYPE "Debug")
if("$ENV{BUILD_MODE}" STREQUAL "Release")
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(EXE_NAME "$ENV{TARGET_NAME}")

set(third_party_dir ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
set(third_party_install_dir ${third_party_dir}/install)

add_definitions(-D__STDC_FORMAT_MACROS -D_FILE_OFFSET_BITS=64)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-error=comment -fno-rtti -std=c++17 -Wno-self-assign-overloaded -fsanitize=address -fsanitize=undefined")

# outside util headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${third_party_install_dir}/include)
include_directories(${third_party_install_dir}/include/googletest/include)
include_directories(${third_party_install_dir}/include/googlemock/include)

add_subdirectory(third_party)

link_directories(${third_party_install_dir}/lib)

file(GLOB_RECURSE SRC_FILES "src/*.cc")

set(LINK_STATIC_LIBS libgtest.a libgmock.a)

set(DEPEND_MODULES
  googletest
)

add_executable(${EXE_NAME} ${SRC_FILES})

target_link_libraries(${EXE_NAME}
  ${LINK_STATIC_LIBS}
)

add_dependencies(${EXE_NAME} ${DEPEND_MODULES})
