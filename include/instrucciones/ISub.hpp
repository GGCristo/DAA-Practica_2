#pragma once
#include "../instruccion_interfaz.hpp"

class ISub: public Instruccion_Interfaz
{
  public:
    ISub(std::string&, std::string&, Memoria&);
    int ejecutar() override;
  private:
    int operandoI_;
    int tipoAcceso_;
    Memoria* memoria_;
};
