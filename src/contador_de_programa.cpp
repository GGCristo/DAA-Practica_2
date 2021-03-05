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

const std::string Pc::peek()
{
  return std::to_string(pc_);
}
