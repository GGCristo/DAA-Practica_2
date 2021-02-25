#include "../include/cinta_entrada.hpp"

CintaEntrada::CintaEntrada()
{
  cabeza_ = 0;
}

CintaEntrada& CintaEntrada::get_instance()
{
  static CintaEntrada instance;
  return instance;
}

int CintaEntrada::read()
{
  return cinta_entrada_[cabeza_++];
}

void CintaEntrada::set_cinta_entrada(std::vector<int>& cinta_entrada)
{
  static int ROM = 1;
  if (ROM)
  {
    cinta_entrada_ = cinta_entrada;
    ROM = 0;
  }
  else
  {
    throw "No se puede sobrescribir la cinta de entrada\n";
  }
}
