#include "../../include/instrucciones/IHalt.hpp"

IHalt::IHalt(const std::string& opcode)
{
  opcode_ = opcode;
}

int IHalt::ejecutar()
{
  std::cout << "El programa se ejecutó con éxito\n";
  return 1;
}
