#pragma once
#include <string>
class Instruccion
{
  public:
    Instruccion(std::string, std::string);
  private:
    std::string operacion_;
    std::string operando_;
};
