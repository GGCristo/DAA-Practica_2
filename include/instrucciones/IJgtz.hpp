#pragma once

#include "../instruccion_interfaz.hpp"
#include "../memoria.hpp"
#include "../contador_de_programa.hpp"
#include "../set_etiquetas.hpp"

class IJgtz: public Instruccion_Interfaz
{
  public:
    IJgtz(std::string&, std::string&, Memoria&, Pc&, SetEtiquetas&);
    int ejecutar() override;
  private:
    Pc* pc_;
    SetEtiquetas* set_etiquetas_;
    Memoria* memoria_;
};
