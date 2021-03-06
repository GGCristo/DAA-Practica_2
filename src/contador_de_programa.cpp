#include "../include/contador_de_programa.hpp"

Pc::Pc()
{
  pc_ = 0;
}

void Pc::jump(int direccion)
{
  pc_ = direccion;
}

int Pc::acceso()
{
  return pc_++;
}

int Pc::peek()
{
  return pc_;
}
