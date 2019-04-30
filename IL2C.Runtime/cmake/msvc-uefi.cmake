cmake_minimum_required (VERSION 3.7)

set(CMAKE_CONFIGURATION_TYPES, "${CONFIGURATION}")
set(CMAKE_BUILD_TYPE, "${CONFIGURATION}")

set(CMAKE_C_COMPILER_WORKS 1)
set(BUILD_UEFI true)

add_definitions(-DUEFI)
add_definitions(-D_LIB)

include(ProcessorCount)
ProcessorCount(pc)
math(EXPR pc2 "${pc}*2")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /GF /Gy /Zi /utf-8 /wd4100 /wd4197 /wd4206 /MP${pc2}")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Od /Ob0 /Oi /RTCu /GR /sdl- -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Ox /GL /GS- -DNDEBUG")

set(CMAKE_STATIC_LINKER_FLAGS "/ignore:4221")
set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "/LTCG")

set(CMAKE_EXE_LINKER_FLAGS "/OPT:ICF /OPT:REF /INCREMENTAL:NO /DEBUG /MAP /MERGE:.rdata=.text /NODEFAULTLIB /SUBSYSTEM:EFI_APPLICATION")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/RELEASE /LTCG")

set(CMAKE_SHARED_LINKER_FLAGS "/OPT:ICF /OPT:REF /INCREMENTAL:NO /DEBUG /MAP /MERGE:.rdata=.text /NODEFAULTLIB /SUBSYSTEM:EFI_APPLICATION")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/RELEASE /LTCG")

if("${PLATFORM}" STREQUAL "Win32")
set(CMAKE_EXE_LINKER_FLAGS "/SAFESEH")
set(CMAKE_SHARED_LINKER_FLAGS "/SAFESEH")
endif()

set(IL2C_LIBRARY_NAME "libil2c-msvc-uefi-${PLATFORM}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/${CONFIGURATION}/${IL2C_LIBRARY_NAME}.lib)