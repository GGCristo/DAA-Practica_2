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
    virtual int ejecutar() = 0;
    std::ostream& mostrar(std::ostream& os = std::cout);
  protected:
    std::string opcode_;
    std::string operando_;
    // int isInmediato(int&);
    int isIndirecto(int&);
    int isInmediatoOIndirecto(int&);
};
