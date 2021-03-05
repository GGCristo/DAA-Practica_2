#pragma once
#include "../instruccion_interfaz.hpp"

class IDiv: public Instruccion_Interfaz
{
  public:
    IDiv(std::string&, std::string&);
    int ejecutar(Memoria&, bool) override;
  private:
    int operandoI_;
    int tipoAcceso_;
};
