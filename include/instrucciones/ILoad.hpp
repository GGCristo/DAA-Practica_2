#pragma once
#include "../instruccion_interfaz.hpp"
#include "../memoria.hpp"

class ILoad: public Instruccion_Interfaz
{
  public:
    ILoad(std::string&, std::string&, Memoria&);
    int ejecutar() override;
  private:
    int operandoI_;
    int tipoAcceso_;
    Memoria* memoria_;
};
