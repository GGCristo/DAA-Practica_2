#include "../include/instruccion.hpp"

Instruccion::Instruccion(const std::string& operacion, const std::string& operando) :
  opcode_(operacion), operando_(operando)
{}
