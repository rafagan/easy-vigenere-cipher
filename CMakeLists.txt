cmake_minimum_required(VERSION 3.13)
project(vigenere_cipher)

set(CMAKE_CXX_STANDARD 14)

add_executable(vigenere_cipher main.cpp utils.cpp utils.h)