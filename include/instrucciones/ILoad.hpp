#pragma once
#include "../instruccion_interfaz.hpp"

class ILoad: public Instruccion_Interfaz
{
  public:
    ILoad(std::string&, std::string&);
    int ejecutar(Memoria&, bool) override;
  private:
    int operandoI_;
    int tipoAcceso_;
};
