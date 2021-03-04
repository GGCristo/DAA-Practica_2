#include "../../include/instrucciones/IJgtz.hpp"

IJgtz::IJgtz(std::string operando)
{
  operando_ = operando;
}

int IJgtz::ejecutar()
{
  std::cout << "Soy el Jgtz\n";
  return 0;
}
