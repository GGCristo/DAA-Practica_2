#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>

#include "instruccion_interfaz.hpp"
#include "set_etiquetas.hpp"
#include "cinta_salida.hpp" // Singleton
#include "cinta_entrada.hpp" // Singleton
#include "contador_de_programa.hpp" // Singleton
#include "memoria.hpp" // Singleton
#include "halt.hpp" // Custom exception
#include "../include/instrucciones/cabeceras.hpp"

class Programa
{
  public:
    explicit Programa(char *);
    int ejecutar(bool debug = 0);
    const bool isHalt();
    void insertar_instruccion(std::string, std::string);
    const Instruccion_Interfaz& operator [](int);
    const Instruccion_Interfaz& operator [](int) const;
  private:
    SetEtiquetas set_etiquetas_;
    Pc pc_;
    std::vector<std::shared_ptr<Instruccion_Interfaz>> programa_;
};

bool isInmediato(const std::string& opcode, std::string& operando);
bool isIndirecto(const std::string& opcode, std::string& operando);
