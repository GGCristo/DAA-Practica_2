#include "../../include/instrucciones/ILoad.hpp"

ILoad::ILoad(std::string& opcode, std::string& operando, Memoria& memoria):
Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
  memoria_ = &memoria;
}

int ILoad::ejecutar()
{
  if (tipoAcceso_ == Inmediato)
  {
    (*memoria_).escribir(0, operandoI_);
  }
  else if (tipoAcceso_ == Directo)
  {
    (*memoria_).escribir(0, ((*memoria_))[operandoI_]);
  }
  else if (tipoAcceso_ == Indirecto)
  {
    (*memoria_).escribir(0, ((*memoria_))[((*memoria_))[operandoI_]]);
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
