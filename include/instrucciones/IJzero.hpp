#pragma once
#include "../instruccion_interfaz.hpp"
#include "../memoria.hpp"
#include "../contador_de_programa.hpp"
#include "../set_etiquetas.hpp"

class IJzero: public Instruccion_Interfaz
{
  public:
    IJzero(std::string&, std::string&, Memoria&, Pc&, SetEtiquetas&);
    int ejecutar() override;
  private:
   Pc* pc_;
   SetEtiquetas* set_etiquetas_;
   Memoria* memoria_;
};
