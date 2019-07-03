cmake_minimum_required(VERSION 3.6)
project(thermometer)
include(ExternalProject)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose build type: Debug Release." FORCE)
endif()

IF(CMAKE_BUILD_TYPE MATCHES Debug)
  set(COMPILE_DEFINITIONS_DEBUG -O0 -g -DDEBUG)
  message(STATUS "DEBUG: ${COMPILE_DEFINITIONS_DEBUG}")
ELSEIF(CMAKE_BUILD_TYPE MATCHES Release)
  set(COMPILE_DEFINITIONS_RELEASE -Os -fno-inline-functions -DNDEBUG)
  message(STATUS "RELEASE: ${COMPILE_DEFINITIONS_RELEASE}")
ENDIF()

set(FLAGS_COMMON
		"-pedantic"
		"-Wall"
		"-Wcast-align"
		"-Wcast-qual"
		"-Wconversion"
		"-Wextra"
		"-Winline"
		"-Wshadow"
		"-fno-exceptions"
)
string(REPLACE ";" " " FLAGS_COMMON "${FLAGS_COMMON}")

set(PLATFORM_SOC "STM32F0")
set(PLATFORM "STM32F0xx")
set(FLAGS_PLATFORM "${FLAGS_PLATFORM} -D${PLATFORM}")
set(FLAGS_PLATFORM_SOC "${FLAGS_PLATFORM_SOC} -D${PLATFORM_SOC}")
set(CMAKE_C_FLAGS "${FLAGS_CPU} ${FLAGS_COMMON} ${FLAGS_PLATFORM} ${FLAGS_PLATFORM_SOC}")
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

ExternalProject_Add(libopencm3
        SOURCE_DIR ${PROJECT_SOURCE_DIR}/libopencm3
        CONFIGURE_COMMAND ""
        BINARY_DIR ${PROJECT_BINARY_DIR}/libopencm3
        BUILD_COMMAND make -C ${PROJECT_SOURCE_DIR}/libopencm3
        INSTALL_COMMAND ""
        BUILD_ALWAYS 1
)
include_directories(src)
file(GLOB_RECURSE CORE_SOURCE_LIST "${PROJECT_SOURCE_DIR}/src/*.c")

include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/libopencm3/include")
link_directories("${PROJECT_SOURCE_DIR}/libopencm3/lib")

set(LINKER_SCRIPT "${PROJECT_SOURCE_DIR}/libopencm3/lib/stm32/f0/stm32f07xz8.ld")
set(FLAGS_LINKER ${FLAGS_LINKER} opencm3_stm32f0)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nosys.specs --specs=nano.specs -Xlinker --gc-sections -T ${LINKER_SCRIPT} -Xlinker -Map=${PROJECT_NAME}.map")

add_executable(${PROJECT_NAME} ${CORE_SOURCE_LIST})
add_dependencies(${PROJECT_NAME} libopencm3)
target_link_libraries(${PROJECT_NAME} ${FLAGS_LINKER})


add_custom_target(
		${PROJECT_NAME}.bin ALL
		COMMAND ${CMAKE_OBJCOPY} ${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX} -Obinary ${PROJECT_NAME}.bin
		DEPENDS ${PROJECT_NAME}
)

add_custom_target(
		${PROJECT_NAME}.hex ALL
		COMMAND ${CMAKE_OBJCOPY} ${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX} -Oihex ${PROJECT_NAME}.hex
		DEPENDS ${PROJECT_NAME}
)
