cmake_minimum_required(VERSION 3.20)
project(BUSCAMINAS)

set(CMAKE_CXX_STANDARD 17)

add_executable(BUSCAMINAS main.cpp tablero.h tablero.cpp nivel1.cpp nivel1.h nivel2.cpp nivel2.h nivel3.cpp nivel3.h nivelP.cpp nivelP.h cruz.cpp cruz.h registros.h heap.h diamante.cpp diamante.h)
