#include "../../include/instrucciones/IWrite.hpp"

IWrite::IWrite(std::string operando)
{
  operando_ = operando;
}

int IWrite::ejecutar()
{
  std::cout << "Soy el Write\n";
  return 0;
}
