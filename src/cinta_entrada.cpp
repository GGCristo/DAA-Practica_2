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

const int CintaEntrada::operator [] (int posicion)
{
  return cinta_entrada_[posicion];
}

const size_t CintaEntrada::get_sz()
{
  return cinta_entrada_.size();
}

int CintaEntrada::read()
{
  std::cout << "READ: " << cinta_entrada_[cabeza_] << " Cabeza: " << cabeza_ << '\n';
  return cinta_entrada_[cabeza_++];
}

void CintaEntrada::set_cinta_entrada(const std::vector<int>& cinta_entrada)
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
