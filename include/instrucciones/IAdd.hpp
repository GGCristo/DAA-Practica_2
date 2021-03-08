#pragma once
#include <limits.h>
#include "../instruccion_interfaz.hpp"
#include "../memoria.hpp"

class IAdd: public Instruccion_Interfaz
{
  public:
    IAdd(std::string&, std::string&, Memoria&);
    int ejecutar() override;
    void overflow(int, int);
  private:
    int operandoI_;
    int tipoAcceso_;
    Memoria* memoria_;
};
