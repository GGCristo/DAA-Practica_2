#pragma once
#include "../instruccion_interfaz.hpp"

class IStore: public Instruccion_Interfaz
{
  public:
    IStore(std::string&, std::string&, Memoria&);
    int ejecutar() override;
  private:
    int operandoI_;
    int tipoAcceso_;
    Memoria* memoria_;
};
