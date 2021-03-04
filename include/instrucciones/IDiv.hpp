#pragma once
#include "../instruccion_interfaz.hpp"

class IDiv: public Instruccion_Interfaz
{
  public:
    IDiv(std::string);
    int ejecutar();
  private:
};
