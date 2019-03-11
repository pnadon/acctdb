cmake_minimum_required(VERSION 3.13)
project(acctdb C)

set(CMAKE_C_STANDARD 99)

add_executable(acctdb acctdb.c acctdb.h transaction_processor.c transaction_processor.h)