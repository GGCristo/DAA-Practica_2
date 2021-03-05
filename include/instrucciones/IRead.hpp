#pragma once
#include "../instruccion_interfaz.hpp"
#include "../cinta_entrada.hpp"

class IRead: public Instruccion_Interfaz
{
  public:
    IRead(std::string&, std::string&, CintaEntrada&);
    int ejecutar(Memoria&, bool) override;
  private:
    int operandoI_;
    int tipoAcceso_;
    CintaEntrada* cinta_entrada_;
};
