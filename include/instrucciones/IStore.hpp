#pragma once
#include "../instruccion_interfaz.hpp"

class IStore: public Instruccion_Interfaz
{
  public:
    IStore(std::string&, std::string&);
    int ejecutar(Memoria&) override;
  private:
    int operandoI_;
    int tipoAcceso_;
};
