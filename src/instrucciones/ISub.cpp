#include "../../include/instrucciones/ISub.hpp"

ISub::ISub(std::string& opcode, std::string& operando, Memoria& memoria):
Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
  memoria_ = &memoria;
}

int ISub::ejecutar()
{
  if (tipoAcceso_ == Inmediato)
  {
    (*memoria_).escribir(0, (*memoria_).get_acumulador() - operandoI_);
  }
  else if (tipoAcceso_ == Directo)
  {
    (*memoria_).escribir(0, (*memoria_).get_acumulador() - ((*memoria_))[operandoI_]);
  }
  else if (tipoAcceso_ == Indirecto)
  {
    (*memoria_).escribir(0, (*memoria_).get_acumulador() - ((*memoria_))[((*memoria_))[operandoI_]]);
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
