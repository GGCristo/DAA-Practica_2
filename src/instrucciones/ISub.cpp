#include "../../include/instrucciones/ISub.hpp"

ISub::ISub(std::string operando)
{
  operando_ = operando;
}

int ISub::ejecutar()
{
  std::cout << "Soy el Sub\n";
  return 0;
}
