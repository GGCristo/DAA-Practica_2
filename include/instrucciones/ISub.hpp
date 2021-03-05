#pragma once
#include "../instruccion_interfaz.hpp"

class ISub: public Instruccion_Interfaz
{
  public:
    ISub(std::string&, std::string&);
    int ejecutar(Memoria&, bool) override;
  private:
    int operandoI_;
    int tipoAcceso_;
};
