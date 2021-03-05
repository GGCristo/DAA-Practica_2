#pragma once

#include "../instruccion_interfaz.hpp"
#include "../contador_de_programa.hpp"
#include "../set_etiquetas.hpp"

class IJgtz: public Instruccion_Interfaz
{
  public:
    IJgtz(std::string&, std::string&, Pc&, SetEtiquetas&);
    int ejecutar(Memoria&, bool) override;
  private:
    Pc* pc_;
    SetEtiquetas* set_etiquetas_;
};
