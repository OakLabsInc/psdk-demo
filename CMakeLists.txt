cmake_minimum_required(VERSION 3.5)

project(PSDK_Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Note that PSDK is built using C++03 ABI, hence disabling C++11 ABI
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0)

add_executable(PSDK_Test main.cpp)

target_include_directories(PSDK_Test PRIVATE "./include")
target_link_libraries(PSDK_Test "/home/swhite/oak/psdk-demo/lib/libPaymentSdk.so")
