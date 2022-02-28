cmake_minimum_required(VERSION 3.5)

project (skiplist)

FILE(GLOB SC_FILES "*.cpp" "*.h")

add_executable(${PROJECT_NAME} ${SC_FILES})