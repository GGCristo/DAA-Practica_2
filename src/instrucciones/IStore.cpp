#include "../../include/instrucciones/IStore.hpp"

IStore::IStore(std::string operando)
{
  operando_ = operando;
}

int IStore::ejecutar()
{
  std::cout << "Soy el Store\n";
  return 0;
}
