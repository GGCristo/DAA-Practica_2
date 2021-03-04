#pragma once
#include "../instruccion_interfaz.hpp"

class IMult: public Instruccion_Interfaz
{
  public:
    IMult(std::string);
    int ejecutar();
  private:
};
