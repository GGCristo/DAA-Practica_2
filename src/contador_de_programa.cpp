#include "../include/contador_de_programa.hpp"

Pc::Pc()
{
  pc_ = 0;
}

Pc& Pc::get_instance()
{
  static Pc instance;
  return instance;
}

void Pc::incrementar()
{
  pc_++;
}

void Pc::jump(int direccion)
{
  pc_ = direccion;
}

const int Pc::get_Pc()
{
  return pc_;
}
