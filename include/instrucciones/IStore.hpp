#pragma once
#include "../instruccion_interfaz.hpp"

class IStore: public Instruccion_Interfaz
{
  public:
    IStore(std::string);
    int ejecutar();
  private:
};
