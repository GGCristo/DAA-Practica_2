#include <iostream>

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
    std::cerr << e.what();
  }
  catch(const char* message)
  {
    std::cout << message;
  }
  catch(...)
  {
    std::cerr << "Ha habido un error no especificado\n";
  }
  std::cout << "Se cierra el programa\n";
  return 0;
}
