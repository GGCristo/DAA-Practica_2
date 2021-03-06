#pragma once
#include "../instruccion_interfaz.hpp"

#include "../contador_de_programa.hpp"
#include "../set_etiquetas.hpp"

class IJzero: public Instruccion_Interfaz
{
  public:
    IJzero(std::string&, std::string&, Pc&, SetEtiquetas&);
    int ejecutar(Memoria&) override;
  private:
   Pc* pc_;
   SetEtiquetas* set_etiquetas_;
};
