#pragma once
#include "../instruccion_interfaz.hpp"

class IHalt: public Instruccion_Interfaz
{
  public:
    IHalt(const std::string&);
    int ejecutar() override;
  private:
};
