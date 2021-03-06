#include "../../include/instrucciones/IJzero.hpp"

IJzero::IJzero(std::string& opcode, std::string& operando, Pc& pc, SetEtiquetas& set_etiquetas):
Instruccion_Interfaz(opcode, operando)
{
  pc_ = &pc;
  set_etiquetas_ = &set_etiquetas;
}

int IJzero::ejecutar(Memoria& memoria)
{
  if (memoria.get_acumulador() == 0)
  {
    pc_ -> jump(set_etiquetas_ -> buscar(operando_));
  }
  return 0;
}
