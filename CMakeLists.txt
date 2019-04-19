cmake_minimum_required(VERSION 3.13)
project(RSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(RSA src/main.cpp src/BigInteger.h src/BigInteger.cpp src/BigInteger.cpp src/BigInteger.h src/RSA.cpp src/RSA.h)