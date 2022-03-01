cmake_minimum_required(VERSION 3.5)

project (LRU_LFU)

FILE(GLOB SC_FILES "*.cpp" "*.h")

add_executable(${PROJECT_NAME} ${SC_FILES})