cmake_minimum_required(VERSION "3.9.2")

project(RAM)

set(SOURCES
  programa.cpp
  set_etiquetas.cpp
  cinta_salida.cpp
  cinta_entrada.cpp
  memoria.cpp
  contador_de_programa.cpp
  halt.cpp
  ram.cpp
  instruccion_interfaz.cpp
  instrucciones/IAdd.cpp
  instrucciones/IDiv.cpp
  instrucciones/IHalt.cpp
  instrucciones/IJgtz.cpp
  instrucciones/IJump.cpp
  instrucciones/IJzero.cpp
  instrucciones/ILoad.cpp
  instrucciones/IMult.cpp
  instrucciones/IRead.cpp
  instrucciones/IStore.cpp
  instrucciones/ISub.cpp
  instrucciones/IWrite.cpp
)

set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS_DEBUG "-g -pedantic-errors -Wall -Wextra -std=c++17 -fsanitize=address")
# set(CMAKE_CXX_FLAGS_DEBUG "-g -pedantic-errors -Wall -Wextra -std=c++17")

add_executable(main ${SOURCES} main.cpp)
