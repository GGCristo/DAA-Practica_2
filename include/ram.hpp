#pragma once

#include "cinta_entrada.hpp" // Singleton
#include "cinta_salida.hpp" // Singleton
// #include "contador_de_programa.hpp" // Singleton
// #include "memoria.hpp" // Singleton
#include "programa.hpp"

class Ram
{
  public:
    Ram();
    explicit Ram(char* argc[]);
    void ejecutar();
    bool isHalt();
    CintaEntrada get_cinta_entrada();
    CintaSalida get_cinta_salida();
    void volcarCinta(char*);
  private:
    CintaEntrada cintaEntrada_;
    CintaSalida cintaSalida_;
    Memoria memoria_;
    Programa programa_;
    bool halt_;
    bool debug_;
    void cargarCinta(char*);
    bool menu(Memoria&, CintaEntrada&, CintaSalida&, bool&);
};

void ayuda();
