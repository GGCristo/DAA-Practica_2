#pragma once

#include "cinta_entrada.hpp" // Singleton
#include "cinta_salida.hpp" // Singleton
#include "contador_de_programa.hpp" // Singleton
#include "memoria.hpp" // Singleton
#include "programa.hpp"

class Ram
{
  public:
    Ram(char* argc[]);
    void ejecutar();
    bool isHalt();
  private:
    CintaEntrada cintaEntrada_;
    CintaSalida cintaSalida_;
    Memoria memoria_;
    Programa programa_;
    bool halt_;
    bool debug_;
    void cargarCinta(char*);
    void volcarCinta(char*);
    bool menu();
};

void ayuda();
