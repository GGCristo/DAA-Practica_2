#include "../include/cinta_salida.hpp"

CintaSalida::CintaSalida()
{
  cabeza_ = 0;
}

void CintaSalida::write(int valor)
{
  cintaSalida_.push_back(valor);
  cabeza_++;
}

int CintaSalida::operator [] (int posicion)
{
  return cintaSalida_[posicion];
}

size_t CintaSalida::get_sz()
{
  return cintaSalida_.size();
}

std::ostream& CintaSalida::mostrar(std::ostream& os)
{
  for (size_t i = 0; i < cintaSalida_.size(); i++)
  {
    std::cout << cintaSalida_[i] << '\n';
  }
    return os;
}
