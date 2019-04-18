cmake_minimum_required(VERSION 3.13)
project(RSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(RSA src/BigNumber/main.cpp src/BigNumber/BigInteger.h src/BigNumber/BigInteger.cpp src/BigNumber/BigInteger.cpp src/BigNumber/BigInteger.h)