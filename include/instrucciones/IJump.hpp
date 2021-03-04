#pragma once
#include "../instruccion_interfaz.hpp"

class IJump: public Instruccion_Interfaz
{
  public:
    IJump(std::string);
    int ejecutar();
  private:
};
