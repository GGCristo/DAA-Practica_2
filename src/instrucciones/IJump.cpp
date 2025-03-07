#include "../../include/instrucciones/IJump.hpp"

IJump::IJump(std::string& opcode, std::string& operando, Pc& pc, SetEtiquetas& set_etiquetas):
Instruccion_Interfaz(opcode, operando)
{
  pc_ = &pc;
  set_etiquetas_ = &set_etiquetas;
}

int IJump::ejecutar()
{
  pc_ -> jump(set_etiquetas_ -> buscar(operando_));
  return 0;
}
