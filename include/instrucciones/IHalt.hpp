#pragma once
#include "../instruccion_interfaz.hpp"

class IHalt: public Instruccion_Interfaz
{
  public:
    IHalt();
    int ejecutar(Memoria&, bool) override;
  private:
};
