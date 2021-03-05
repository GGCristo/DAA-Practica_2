#include "../include/memoria.hpp"

// escribir (posicion, valor);
void Memoria::escribir(int posicion, int valor)
{
  if (memoria_.size() <= posicion) memoria_.resize(posicion + 1);
  memoria_[posicion] = valor;
}

const int Memoria::get_acumulador()
{
  return memoria_[0];
}

const size_t Memoria::get_sz()
{
  return memoria_.size();
}

const int Memoria::operator [](int posicion)
{
  return memoria_[posicion];
}

std::ostream& Memoria::mostrar(std::ostream& os)
{
  for (size_t i = 0; i < memoria_.size(); i++)
  {
    os << "R"<< i << ": " <<memoria_[i] << '\n';
  }
  return os;
}
