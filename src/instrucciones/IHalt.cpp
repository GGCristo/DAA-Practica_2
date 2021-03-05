#include "../../include/instrucciones/IHalt.hpp"

IHalt::IHalt()
{}

int IHalt::ejecutar(Memoria& memoria, bool debug)
{
  std::cout << "El programa termina\n";
  return 1;
}
