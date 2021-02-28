#pragma once
#include <vector>
#include <fstream>
#include <sstream>

#include "instruccion.hpp"

class Programa
{
  public:
    Programa(char *);
    int ejecutar() const;
    void insertar_instruccion(Instruccion);
    const size_t get_sz();
    const size_t get_sz() const;
    const Instruccion& operator [](int);
    const Instruccion& operator [](int) const;
  private:
    SetEtiquetas set_etiquetas_;
    std::vector<Instruccion> programa_;
};
