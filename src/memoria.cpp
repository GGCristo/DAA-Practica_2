#include "../include/memoria.hpp"

Memoria& Memoria::get_instance()
{
  static Memoria instance;
  return instance;
}

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
