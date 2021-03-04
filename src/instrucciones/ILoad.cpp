#include "../../include/instrucciones/ILoad.hpp"

ILoad::ILoad(std::string operando)
{
  operando_ = operando;
}

int ILoad::ejecutar()
{
  std::cout << "Soy el Load\n";
  return 0;
}
