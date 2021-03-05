#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/programa.hpp"
#include "../include/ram.hpp"

int main(int argc, char *argv[])
{
  try
  {
    if (argc != 5)
    {
      throw "Se necesita cuatro valores\n";  // ayuda();
    }
    Ram ram(argv);
    ram.ejecutar();
    ram.volcarCinta(argv[3]);
  }
  catch(const std::exception& e)
  {
    std::cout << e.what();
  }
  catch(const char* message)
  {
    std::cout << message;
  }
  catch(const Halt &e)
  {
    std::cerr << "Error: " << e.what();
  }
  catch(...)
  {
    std::cout << "Ha habido un error no especificado\n";
  }
  return 0;
}
