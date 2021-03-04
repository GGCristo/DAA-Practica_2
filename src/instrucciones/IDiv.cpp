#include "../../include/instrucciones/IDiv.hpp"

IDiv::IDiv(std::string operando)
{
  operando_ = operando;
}

int IDiv::ejecutar()
{
  std::cout << "Soy el ADD\n";
  return 0;
}
