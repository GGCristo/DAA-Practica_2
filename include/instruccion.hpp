#pragma once
#include <iostream>
#include <string>

class Instruccion
{
  public:
  private:
    Instruccion(const std::string&, const std::string&);
    std::string opcode_;
    std::string operando_;
    friend class Programa;
};
