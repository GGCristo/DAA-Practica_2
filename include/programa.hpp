#pragma once
#include <vector>
#include <fstream>
#include <sstream>

#include "instruccion.hpp"
#include "set_etiquetas.hpp"
#include "cinta_salida.hpp" // Singleton
#include "cinta_entrada.hpp" // Singleton
#include "contador_de_programa.hpp" // Singleton
#include "memoria.hpp" // Singleton

class Programa
{
  public:
    explicit Programa(char *);
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
