#pragma once
#include "../instruccion_interfaz.hpp"

class IJgtz: public Instruccion_Interfaz
{
  public:
    IJgtz(std::string);
    int ejecutar();
  private:
};
