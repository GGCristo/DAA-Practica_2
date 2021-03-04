#pragma once
#include "../instruccion_interfaz.hpp"

class IAdd: public Instruccion_Interfaz
{
  public:
    IAdd(std::string);
    int ejecutar();
  private:
};
