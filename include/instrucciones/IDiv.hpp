#pragma once
#include "../instruccion_interfaz.hpp"

class IDiv: public Instruccion_Interfaz
{
  public:
    IDiv(std::string&, std::string&, Memoria&);
    int ejecutar() override;
  private:
    int operandoI_;
    int tipoAcceso_;
    Memoria* memoria_;
};
