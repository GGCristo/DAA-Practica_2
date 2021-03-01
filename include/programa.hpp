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
#include "halt.hpp" // Custom exception

class Programa
{
  public:
    explicit Programa(char *);
    void ejecutar(bool debug = 0);
    const bool isHalt();
    void insertar_instruccion(Instruccion);
    const Instruccion& operator [](int);
    const Instruccion& operator [](int) const;
  private:
    SetEtiquetas set_etiquetas_;
    std::vector<Instruccion> programa_;
    bool halt_;
};

bool isInmediato(const std::string& opcode, std::string& operando);
bool isIndirecto(const std::string& opcode, std::string& operando);
