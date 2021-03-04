#pragma once
#include "../instruccion_interfaz.hpp"

class IJzero: public Instruccion_Interfaz
{
  public:
    IJzero(std::string);
    int ejecutar();
  private:
};
