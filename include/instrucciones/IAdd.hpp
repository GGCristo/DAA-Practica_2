#pragma once
#include "../instruccion_interfaz.hpp"

class IAdd: public Instruccion_Interfaz
{
  public:
    IAdd(std::string&, std::string&);
    int ejecutar(Memoria&) override;
  private:
    int operandoI_;
    int tipoAcceso_;
};
