#pragma once
#include "../instruccion_interfaz.hpp"
#include "../cinta_salida.hpp"

class IWrite: public Instruccion_Interfaz
{
  public:
    IWrite(std::string&, std::string&, Memoria&, CintaSalida&);
    int ejecutar() override;
  private:
    int operandoI_;
    int tipoAcceso_;
    CintaSalida* cinta_salida_;
    Memoria* memoria_;
};
