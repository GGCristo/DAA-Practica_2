#include "../../include/instrucciones/IAdd.hpp"

IAdd::IAdd(std::string operando)
{
  operando_ = operando;
}

int IAdd::ejecutar()
{
  std::cout << "Soy el ADD\n";
  return 0;
}
