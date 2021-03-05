#pragma once

#include "../instruccion_interfaz.hpp"
#include "../contador_de_programa.hpp"
#include "../set_etiquetas.hpp"

class IJump: public Instruccion_Interfaz
{
  public:
    IJump(std::string&, std::string&, Pc&, SetEtiquetas&);
    int ejecutar(Memoria&, bool) override;
  private:
    Pc* pc_;
    SetEtiquetas* set_etiquetas_;
};
