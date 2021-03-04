#include "../../include/instrucciones/IJump.hpp"

IJump::IJump(std::string operando)
{
  operando_ = operando;
}

int IJump::ejecutar()
{
  std::cout << "Soy el Jump\n";
  return 0;
}
