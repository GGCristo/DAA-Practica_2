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

const int CintaSalida::operator [] (int posicion)
{
  return cinta_salida_[posicion];
}

const size_t CintaSalida::get_sz()
{
  return cinta_salida_.size();
}
