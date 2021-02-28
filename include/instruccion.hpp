#pragma once
#include <iostream>
#include <string>

#include "memoria.hpp"
#include "cinta_salida.hpp"
#include "cinta_entrada.hpp"
#include "set_etiquetas.hpp"
#include "contador_de_programa.hpp"

class Instruccion
{
  public:
  private:
    Instruccion(const std::string&, const std::string&);
    std::string opcode_;
    std::string operando_;
    friend class Programa;
};
