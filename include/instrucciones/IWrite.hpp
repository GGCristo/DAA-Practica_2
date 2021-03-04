#pragma once
#include "../instruccion_interfaz.hpp"

class IWrite: public Instruccion_Interfaz
{
  public:
    IWrite(std::string);
    int ejecutar();
  private:
};
