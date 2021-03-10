#pragma once
#include <vector>
#include <sstream>
#include <memory>

#include "instruccion_interfaz.hpp"
#include "cinta_entrada.hpp"
#include "cinta_salida.hpp"
#include "set_etiquetas.hpp"
#include "contador_de_programa.hpp"
#include "memoria.hpp"
#include "halt.hpp"

class Programa
{
  public:
    Programa() = delete;
    Programa(const char *, Memoria&, CintaEntrada&, CintaSalida&);
    Programa(const Programa&);
    void insertar_instruccion(std::string&, std::string&, Memoria&, CintaEntrada&, CintaSalida&);
    int ejecutar();
    void peek();
    int numeroEjecuciones();
    const Instruccion_Interfaz& operator [](int);
    const Instruccion_Interfaz& operator [](int) const;
  private:
    SetEtiquetas set_etiquetas_;
    Pc pc_;
    std::vector<std::unique_ptr<Instruccion_Interfaz>> programa_;
    int ejecuciones_;
};
