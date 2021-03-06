#include "../../include/instrucciones/IJgtz.hpp"

IJgtz::IJgtz(std::string& opcode, std::string& operando, Memoria& memoria, Pc& pc, SetEtiquetas& set_etiquetas):
Instruccion_Interfaz(opcode, operando)
{
  pc_ = &pc;
  set_etiquetas_ = &set_etiquetas;
  memoria_ = &memoria;
}

int IJgtz::ejecutar()
{
  if ((*memoria_).get_acumulador() > 0)
  {
    pc_ -> jump(set_etiquetas_ -> buscar(operando_));
  }
  return 0;
}
