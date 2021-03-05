#pragma once

#include <string.h>

#include "cinta_entrada.hpp" // Singleton
#include "cinta_salida.hpp" // Singleton
// #include "contador_de_programa.hpp" // Singleton
// #include "memoria.hpp" // Singleton
#include "programa.hpp"

class Ram
{
  public:
    Ram(){};
    explicit Ram(char**);
    void ejecutar();
    bool isHalt();
  private:
    CintaEntrada cintaEntrada_;
    CintaSalida cintaSalida_;
    Memoria memoria_;
    Programa programa_;
    bool halt_;
    bool debug_;
    char** argumentos_;
    void cargarCinta(char*);
    void volcarCinta(char*);
    void inner_ejecutar();
    bool menu(Memoria&, CintaEntrada&, CintaSalida&, bool&);
};

void ayuda();
