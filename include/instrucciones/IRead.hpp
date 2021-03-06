#pragma once
#include "../instruccion_interfaz.hpp"
#include "../cinta_entrada.hpp"

class IRead: public Instruccion_Interfaz
{
  public:
    IRead(std::string&, std::string&, Memoria&, CintaEntrada&);
    int ejecutar() override;
  private:
    int operandoI_;
    int tipoAcceso_;
    CintaEntrada* cinta_entrada_;
    Memoria* memoria_;
};
