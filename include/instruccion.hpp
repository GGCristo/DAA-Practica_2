#pragma once
#include <string>
class Instruccion
{
  public:
    Instruccion(const std::string&, const std::string&);
  private:
    std::string operacion_;
    std::string operando_;
};
