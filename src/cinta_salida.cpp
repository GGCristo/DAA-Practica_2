#include "../include/cinta_salida.hpp"

CintaSalida::CintaSalida()
{
  cabeza_ = 0;
}

CintaSalida& CintaSalida::get_instance()
{
  static CintaSalida instance;
  return instance;
}

void CintaSalida::write(int valor)
{
  cinta_salida_.push_back(valor);
  cabeza_++;
}
