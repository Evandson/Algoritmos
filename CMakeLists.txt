cmake_minimum_required(VERSION 3.5)
project(Algoritmos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Estagio.c)
set(SOURCE_FILES MaiorIndice.c)
set(SOURCE_FILES TabelaAscii.c)
set(SOURCE_FILES TabelaAscii.c)
set(SOURCE_FILES Agenda.c)
set(SOURCE_FILES Intervalo.c)
set(SOURCE_FILES Matriz.c)
set(SOURCE_FILES MatrizTwo.c)
set(SOURCE_FILES Soma.c)
set(SOURCE_FILES Recursividade.c)
set(SOURCE_FILES Mdc.c)
set(SOURCE_FILES Fibonacci.c)

add_executable(Algoritmos ${SOURCE_FILES})