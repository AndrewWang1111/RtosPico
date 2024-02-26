# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/wjl/pico/pico-sdk")
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)


if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(RtosPico C CXX ASM)
pico_sdk_init()
add_subdirectory(FreeRTOS-Kernel)                  #将FreeRTOS作为自模块添加到工程
include_directories(
FreeRTOS-Kernel/include                            #增加freertos的include目录
)
add_executable(RtosPico RtosPico.c )
pico_set_program_name(RtosPico "RtosPico")
pico_set_program_version(RtosPico "0.1")
pico_enable_stdio_uart(RtosPico 1)
pico_enable_stdio_usb(RtosPico 0)
target_link_libraries(RtosPico        
        pico_stdlib      
        freertos_kernel                             #静态链接Freertos库
        hardware_gpio                                #GPIO用来测试freertos
        )

# Add the standard include files to the build
target_include_directories(RtosPico PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

pico_add_extra_outputs(RtosPico)

