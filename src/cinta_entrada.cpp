#include "../include/cinta_entrada.hpp"

CintaEntrada::CintaEntrada()
{
  cabeza_ = 0;
}

CintaEntrada::~CintaEntrada()
{
}

const int CintaEntrada::operator [] (int posicion)
{
  return cintaEntrada_[posicion];
}

const size_t CintaEntrada::get_sz()
{
  return cintaEntrada_.size();
}

int CintaEntrada::read()
{
  if (cabeza_ >= cintaEntrada_.size())
  {
    throw Halt("Se intento leer fuera de la cinta\n");
  }
  return cintaEntrada_[cabeza_++];
}

void CintaEntrada::set_cinta_entrada(const std::vector<int>& cinta_entrada)
{
  static int ROM = 1;
  if (ROM)
  {
    cintaEntrada_ = cinta_entrada;
    ROM = 0;
  }
  else
  {
    throw "No se puede sobrescribir la cinta de entrada\n";
  }
}

std::ostream& CintaEntrada::mostrar(std::ostream& os)
{
  for (size_t i = 0; i < cintaEntrada_.size(); i++)
  {
    std::cout << cintaEntrada_[i] << '\n';
  }
    return os;
}
