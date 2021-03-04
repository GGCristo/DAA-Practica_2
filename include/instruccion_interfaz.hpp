#pragma once
#include <iostream>
#include <string>

#include "memoria.hpp"

class Instruccion_Interfaz
{
  public:
    virtual ~Instruccion_Interfaz() = default;
    virtual int ejecutar() = 0;
  protected:
    std::string operando_;
};
