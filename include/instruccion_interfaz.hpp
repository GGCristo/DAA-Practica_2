#pragma once
#include <iostream>
#include <string>

#include "memoria.hpp"
#include "halt.hpp"

enum enum_acceso {Indirecto, Inmediato, Directo};

class Instruccion_Interfaz
{
  public:
    Instruccion_Interfaz() = default;
    Instruccion_Interfaz(const std::string&, const std::string&);
    virtual ~Instruccion_Interfaz() = default;
    virtual int ejecutar(Memoria&, bool debug = false) = 0;
  protected:
    std::string opcode_;
    std::string operando_;
    // int isInmediato(int&);
    int isIndirecto(int&);
    int isInmediatoOIndirecto(int&);
};
