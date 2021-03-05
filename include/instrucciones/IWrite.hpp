#pragma once
#include "../instruccion_interfaz.hpp"
#include "../cinta_salida.hpp"
class IWrite: public Instruccion_Interfaz
{
  public:
    IWrite(std::string&, std::string&, CintaSalida& ram);
    int ejecutar(Memoria&, bool) override;
  private:
    int operandoI_;
    int tipoAcceso_;
    CintaSalida* cinta_salida_;
};
