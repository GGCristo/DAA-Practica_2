#pragma once
#include "../instruccion_interfaz.hpp"

class IHalt: public Instruccion_Interfaz
{
  public:
    explicit IHalt(const std::string&);
    int ejecutar() override;
  private:
};
