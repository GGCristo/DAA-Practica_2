#include "../../include/instrucciones/IMult.hpp"

IMult::IMult(std::string operando)
{
  operando_ = operando;
}

int IMult::ejecutar()
{
  std::cout << "Soy el Mult\n";
  return 0;
}
