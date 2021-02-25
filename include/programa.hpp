#pragma once
#include <vector>
#include "instruccion.hpp"
class Programa
{
  public:
    Programa();
    void insertar_instruccion(Instruccion);
    size_t get_sz();
  private:
    std::vector<Instruccion> programa_;
    int pc_;
};
