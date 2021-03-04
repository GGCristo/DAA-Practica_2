#pragma once
#include "../instruccion_interfaz.hpp"

class ISub: public Instruccion_Interfaz
{
  public:
    ISub(std::string);
    int ejecutar();
  private:
};
