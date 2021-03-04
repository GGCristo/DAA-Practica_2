#include "../../include/instrucciones/IRead.hpp"

IRead::IRead(std::string operando)
{
  operando_ = operando;
}

int IRead::ejecutar()
{
  std::cout << "Soy el Read\n";
  return 0;
}
