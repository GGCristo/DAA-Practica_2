#pragma once
#include "../instruccion_interfaz.hpp"

class IMult: public Instruccion_Interfaz
{
  public:
    IMult(std::string&, std::string&);
    int ejecutar(Memoria&, bool) override;
  private:
    int operandoI_;
    int tipoAcceso_;
};
