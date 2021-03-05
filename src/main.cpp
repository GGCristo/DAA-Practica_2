#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/programa.hpp"
#include "../include/ram.hpp"

int main(int argc, char** argv)
{
  try
  {
    if (argc != 5)
    {
      throw "Se necesita cuatro valores\n";  // ayuda();
    }
    Ram ram(argv);
    ram.ejecutar();
  }
  catch(const Halt &e)
  {
    std::cerr << "Error en tiempo de compilación: " << e.what();
  }
  catch(const std::exception& e)
  {
    std::cout << e.what();
  }
  catch(const char* message)
  {
    std::cout << message;
  }
  catch(...)
  {
    std::cout << "Ha habido un error no especificado\n";
  }
  std::cout << "Se cierra el programa\n";
  return 0;
}
