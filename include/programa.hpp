#pragma once
#include <vector>
#include <fstream>
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
    Programa();
    Programa(const Programa&);
    explicit Programa(char *, CintaEntrada&, CintaSalida&);
    void insertar_instruccion(std::string, std::string, CintaEntrada&, CintaSalida&);
    int ejecutar(Memoria&);
    void peek();
    const Instruccion_Interfaz& operator [](int);
    const Instruccion_Interfaz& operator [](int) const;
  private:
    SetEtiquetas set_etiquetas_;
    Pc pc_;
    std::vector<std::shared_ptr<Instruccion_Interfaz>> programa_;
};

bool isInmediato(const std::string& opcode, std::string& operando);
bool isIndirecto(const std::string& opcode, std::string& operando);
