cmake_minimum_required(VERSION "3.9.2")

project(RAM)

set(SOURCES
  ../src/programa.cpp
  ../src/set_etiquetas.cpp
  ../src/cinta_salida.cpp
  ../src/cinta_entrada.cpp
  ../src/memoria.cpp
  ../src/contador_de_programa.cpp
  ../src/halt.cpp
  ../src/ram.cpp
  ../src/instruccion_interfaz.cpp
  ../src/instrucciones/IAdd.cpp
  ../src/instrucciones/IDiv.cpp
  ../src/instrucciones/IHalt.cpp
  ../src/instrucciones/IJgtz.cpp
  ../src/instrucciones/IJump.cpp
  ../src/instrucciones/IJzero.cpp
  ../src/instrucciones/ILoad.cpp
  ../src/instrucciones/IMult.cpp
  ../src/instrucciones/IRead.cpp
  ../src/instrucciones/IStore.cpp
  ../src/instrucciones/ISub.cpp
  ../src/instrucciones/IWrite.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(my_test ${SOURCES}
               test.cpp)
add_test(NAME my_test COMMAND my_test)
