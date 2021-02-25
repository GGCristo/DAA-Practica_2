#include "../include/programa.hpp"

Programa::Programa()
{
  pc_ = 0;
}

void Programa::insertar_instruccion(Instruccion instruccion)
{
  programa_.push_back(instruccion);
}
size_t Programa::get_sz()
{
  return programa_.size();
}
