cmake_minimum_required (VERSION 3.8)
project(FalloutHackingHack)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(HEADERS
	"include/MemoryManager.h"
	)

set(SOURCES 
	"src/main.cpp"
	"src/MemoryManager.cpp"
	)

#source_group("" FILES ${miscFiles})

add_executable(FalloutHackingHack ${SOURCES} ${HEADERS})
target_include_directories(FalloutHackingHack PUBLIC include)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT FalloutHackingHack)