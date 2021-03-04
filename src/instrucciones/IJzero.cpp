#include "../../include/instrucciones/IJzero.hpp"

IJzero::IJzero(std::string operando)
{
  operando_ = operando;
}

int IJzero::ejecutar()
{
  std::cout << "Soy el Jzero\n";
  return 0;
}
