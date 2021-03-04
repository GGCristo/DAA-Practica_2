#pragma once
#include "../instruccion_interfaz.hpp"

class IRead: public Instruccion_Interfaz
{
  public:
    IRead(std::string);
    int ejecutar();
  private:
};
