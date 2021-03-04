#pragma once
#include "../instruccion_interfaz.hpp"

class ILoad: public Instruccion_Interfaz
{
  public:
    ILoad(std::string);
    int ejecutar();
  private:
};
