set(CMAKE_SYSTEM_NAME "Linux")
# set(CMAKE_SYSTEM_NAME "Windows")
cmake_minimum_required(VERSION 3.0)
project(MyTest)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
set(CMAKE_C_COMPILER "C:/MyProgram/Code/Environments/MinGW/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/bin/gcc")
set(CMAKE_CXX_COMPILER "C:/MyProgram/Code/Environments/MinGW/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/bin/g++")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
else()
endif()

aux_source_directory(${PROJECT_SOURCE_DIR}/MyTest DIR_MAIN_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/source/bookstore DIR_WIN_SRCS)

add_executable(${CMAKE_PROJECT_NAME} ${DIR_MAIN_SRCS} ${DIR_WIN_SRCS})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/build/MyTest.exe ${PROJECT_SOURCE_DIR}/deploy/bin/Win/MyTest.exe 
        COMMENT "copy the exe to deploy/bin/Win"
    )
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/build/MyTest ${PROJECT_SOURCE_DIR}/deploy/bin/Linux/MyTest 
        COMMENT "copy the exe to deploy/bin/Linux"
    )
else()
endif()

# include_directories("${PROJECT_SOURCE_DIR}/include/Win")
# include_directories("${PROJECT_SOURCE_DIR}/include")
# aux_source_directory(${PROJECT_SOURCE_DIR}/include/Win DIR_WIN_HEADS)


# message(STATUS ${PROJECT_SOURCE_DIR})
# message(STATUS ${CMAKE_PROJECT_NAME})

# file(GLOB DIR_MAIN_SRCS "${PROJECT_SOURCE_DIR}/MyTest/*.cpp")
# file(GLOB DIR_WIN_SRCS "${PROJECT_SOURCE_DIR}/source/Win/*.cpp")

# file(GLOB SRC_FILES
#     "${PROJECT_SOURCE_DIR}/include/Win/*.h"
#     "${PROJECT_SOURCE_DIR}/source/Win/*.h"
#     "${PROJECT_SOURCE_DIR}/source/Win/*.cpp"
#     "${PROJECT_SOURCE_DIR}/MyTest/*.h"
#     "${PROJECT_SOURCE_DIR}/MyTest/*.cpp")
# add_executable(${CMAKE_PROJECT_NAME} ${DIR_MAIN_SRCS} ${DIR_WIN_HEADS} ${DIR_WIN_SRCS})

    # gnome-terminal --geometry=96x32+700+300
